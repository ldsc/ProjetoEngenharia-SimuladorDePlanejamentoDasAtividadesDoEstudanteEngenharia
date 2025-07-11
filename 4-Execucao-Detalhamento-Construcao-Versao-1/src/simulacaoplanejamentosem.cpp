#include "simulacaoplanejamentosem.h"
#include "ui_simulacaoplanejamentosem.h"

#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QPainter>
#include <QDebug>
#include <map>

int detectarPeriodoAtualDoAluno(const CAluno* aluno);

SimulacaoPlanejamentoSEM::SimulacaoPlanejamentoSEM(CAluno* alunoPtr, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimulacaoPlanejamentoSEM)
    , aluno(alunoPtr)
{
    ui->setupUi(this);

    container = new QWidget;
    layoutSimulacao = new QVBoxLayout(container);
    layoutSimulacao->setAlignment(Qt::AlignTop);
    layoutSimulacao->setSpacing(20);
    layoutSimulacao->setContentsMargins(10, 10, 10, 10);  // reduz margem lateral
    container->setLayout(layoutSimulacao);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidget(container);

    ui->verticalLayoutMain->addWidget(scrollArea);

    connect(ui->botaoAvancar, &QPushButton::clicked, this, &SimulacaoPlanejamentoSEM::avancarSemestre);
    connect(ui->botaoSalvar, &QPushButton::clicked, this, &SimulacaoPlanejamentoSEM::salvarComoImagem);

    periodoAtualSimulado = detectarPeriodoAtualDoAluno(aluno) + 1;

    disciplinasDisponiveis = QVector<CDisciplinas>(aluno->disciplinasNaoCursadas.begin(), aluno->disciplinasNaoCursadas.end());
    disciplinasAprovadas   = QVector<CDisciplinas>(aluno->disciplinasAprovadas.begin(), aluno->disciplinasAprovadas.end());
    disciplinasEmCurso     = QVector<CDisciplinas>(aluno->disciplinasEmCurso.begin(), aluno->disciplinasEmCurso.end());

    avancarSemestre();
}

SimulacaoPlanejamentoSEM::~SimulacaoPlanejamentoSEM()
{
    delete ui;
}

int detectarPeriodoAtualDoAluno(const CAluno* aluno) {
    std::map<int, int> contagem;
    for (const auto& disc : aluno->disciplinasEmCurso)
        contagem[disc.periodo]++;

    int maisFrequente = 1;
    int maxContagem = 0;
    for (const auto& par : contagem) {
        if (par.second > maxContagem) {
            maisFrequente = par.first;
            maxContagem = par.second;
        }
    }
    return maisFrequente;
}

bool SimulacaoPlanejamentoSEM::preRequisitosOk(const CDisciplinas& disc) const {
    QSet<QString> feitas;
    for (const auto& d : disciplinasAprovadas)
        feitas.insert(QString::fromStdString(d.nome));
    for (const auto& d : disciplinasEmCurso)
        feitas.insert(QString::fromStdString(d.nome));
    for (const auto& s : semestres)
        for (const auto& nome : s.disciplinasEscolhidas)
            feitas.insert(nome);

    for (const auto& pre : disc.preRequisitos)
        if (!feitas.contains(QString::fromStdString(pre)))
            return false;
    return true;
}

void SimulacaoPlanejamentoSEM::avancarSemestre() {
    QList<CDisciplinas> elegiveis;
    for (const auto& disc : disciplinasDisponiveis) {
        QString nomeDisc = QString::fromStdString(disc.nome);

        bool jaFez =
            std::any_of(disciplinasAprovadas.begin(), disciplinasAprovadas.end(), [&](const CDisciplinas& d) {
                return d.nome == disc.nome;
            }) ||
            std::any_of(disciplinasEmCurso.begin(), disciplinasEmCurso.end(), [&](const CDisciplinas& d) {
                return d.nome == disc.nome;
            }) ||
            std::any_of(semestres.begin(), semestres.end(), [&](const SimulacaoSemestre& s) {
                return s.disciplinasEscolhidas.contains(nomeDisc);
            });

        if (jaFez) continue;
        if ((disc.periodo % 2) != (periodoAtualSimulado % 2)) continue;
        if (preRequisitosOk(disc)) {
            elegiveis.append(disc);
        }
    }

    SimulacaoSemestre semestre;
    semestre.numero = periodoAtualSimulado;
    semestre.layoutCheck = new QHBoxLayout;
    semestre.layoutDisciplinas = new QHBoxLayout;
    semestre.layoutDisciplinas->setSpacing(8);
    semestre.layoutDisciplinas->setContentsMargins(0, 0, 0, 0);
    semestre.layoutDisciplinas->setAlignment(Qt::AlignLeft);

    QLabel* label = new QLabel(QString("Semestre %1").arg(periodoAtualSimulado));
    label->setStyleSheet("font-weight: bold; color: black;");
    semestre.layoutCheck->addWidget(label);

    int indiceSemestre = semestres.size();
    for (const auto& disc : elegiveis) {
        QString nome = QString::fromStdString(disc.nome);
        QCheckBox* chk = new QCheckBox(nome);
        chk->setStyleSheet("color: black; margin: 6px;");
        semestre.checkboxes.append(chk);
        semestre.layoutCheck->addWidget(chk);

        connect(chk, &QCheckBox::stateChanged, this, [=]() mutable {
            auto& semestreRef = semestres[indiceSemestre];

            if (chk->isChecked()) {
                if (!semestreRef.botoesDisciplinas.contains(nome)) {
                    QPushButton* btn = new QPushButton(nome);
                    btn->setFixedSize(180, 40);
                    btn->setStyleSheet("background-color: #82b4cf; color: black; border-radius: 15px; font-weight: bold; margin: 5px;");
                    semestreRef.layoutDisciplinas->addWidget(btn);
                    semestreRef.botoesDisciplinas[nome] = btn;
                    semestreRef.disciplinasEscolhidas.insert(nome);
                }
            } else {
                if (semestreRef.botoesDisciplinas.contains(nome)) {
                    delete semestreRef.botoesDisciplinas[nome];
                    semestreRef.botoesDisciplinas.remove(nome);
                    semestreRef.disciplinasEscolhidas.remove(nome);
                }

                while (semestres.size() > indiceSemestre + 1) {
                    auto s = semestres.takeLast();
                    for (QCheckBox* c : s.checkboxes) delete c;
                    for (auto b : s.botoesDisciplinas) delete b;
                    delete s.layoutCheck;
                    delete s.layoutDisciplinas;

                    QLayoutItem* item;
                    while ((item = layoutSimulacao->takeAt(layoutSimulacao->count() - 1))) {
                        if (item->layout()) delete item->layout();
                        else if (item->widget()) delete item->widget();
                        delete item;
                    }
                    periodoAtualSimulado--;
                }
            }
        });
    }

    layoutSimulacao->addLayout(semestre.layoutCheck);
    layoutSimulacao->addLayout(semestre.layoutDisciplinas);
    semestres.append(semestre);
    periodoAtualSimulado++;
}

void SimulacaoPlanejamentoSEM::salvarComoImagem() {
    for (const auto& semestre : semestres)
        for (QCheckBox* chk : semestre.checkboxes)
            chk->hide();

    container->adjustSize();
    QSize size = container->size();

    QPixmap imagem(size);
    imagem.fill(Qt::white);
    container->render(&imagem);

    QString nomeArquivo = "Simulacao_Planejamento.png";
    int contador = 1;
    while (QFile::exists(nomeArquivo))
        nomeArquivo = QString("Simulacao_Planejamento_%1.png").arg(contador++);

    for (const auto& semestre : semestres)
        for (QCheckBox* chk : semestre.checkboxes)
            chk->show();

    if (imagem.save(nomeArquivo)) {

        QMessageBox msgBox;
        msgBox.setWindowTitle("Sucesso");
        msgBox.setText("Imagem salva como " + nomeArquivo);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet(
            "QLabel { color: black; font-size: 14px; }"
            "QPushButton { background-color: #82b4cf; color: black; padding: 6px 12px; border-radius: 10px; font-weight: bold; }"
            "QPushButton:hover { background-color: #7ab2d6; }"
            );
        msgBox.exec();


    } else {

        QMessageBox msgBox;
        msgBox.setWindowTitle("Erro");
        msgBox.setText("Falha ao salvar a imagem.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setStyleSheet(
            "QLabel { color: black; font-size: 14px; }"
            "QPushButton { background-color: #f28b82; color: black; padding: 6px 12px; border-radius: 10px; font-weight: bold; }"
            "QPushButton:hover { background-color: #e57373; }"
            );
        msgBox.exec();


    }
}
