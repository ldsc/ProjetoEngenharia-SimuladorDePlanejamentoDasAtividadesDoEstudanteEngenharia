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
    layoutSimulacao->setAlignment(Qt::AlignTop);     // Alinha ao topo
    layoutSimulacao->setSpacing(20);                 // Espaço entre blocos
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
    for (const auto& disc : aluno->disciplinasEmCurso) {
        contagem[disc.periodo]++;
    }

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
    auto aprovadoOuEmCurso = [&](const std::string& nome) {
        for (const auto& d : disciplinasAprovadas)
            if (d.nome == nome) return true;
        for (const auto& d : disciplinasEmCurso)
            if (d.nome == nome) return true;
        for (const auto& semestre : semestres)
            if (semestre.disciplinasEscolhidas.contains(QString::fromStdString(nome)))
                return true;
        return false;
    };

    for (const auto& pre : disc.preRequisitos)
        if (!aprovadoOuEmCurso(pre)) return false;

    return true;
}

void SimulacaoPlanejamentoSEM::avancarSemestre()
{
    QList<CDisciplinas> elegiveis;

    for (const auto& disc : disciplinasDisponiveis) {
        // Ignora se já foi aprovado ou está em curso
        bool jaFez = std::any_of(disciplinasAprovadas.begin(), disciplinasAprovadas.end(), [&](const CDisciplinas& d) {
                         return d.nome == disc.nome;
                     }) || std::any_of(disciplinasEmCurso.begin(), disciplinasEmCurso.end(), [&](const CDisciplinas& d) {
                            return d.nome == disc.nome;
                        });

        if (jaFez) continue;

        // Somente paridade compatível (ex: simula semestre ímpar → só pega ímpares)
        if ((disc.periodo % 2) != (periodoAtualSimulado % 2)) continue;

        // Não permite planejar algo muito à frente
       // if (disc.periodo > periodoAtualSimulado) continue;

        // Checa pré-requisitos
        if (preRequisitosOk(disc)) {
            elegiveis.append(disc);
        }
    }



    SimulacaoSemestre semestre;
    semestre.numero = periodoAtualSimulado;
    semestre.layoutCheck = new QHBoxLayout;
    QWidget* containerDisciplinas = new QWidget;
    QHBoxLayout* layoutBtns = new QHBoxLayout(containerDisciplinas);
    layoutBtns->setSpacing(10);
    layoutBtns->setContentsMargins(0, 0, 0, 0);
    layoutBtns->setAlignment(Qt::AlignHCenter); // Centraliza o grupo

    semestre.layoutDisciplinas = layoutBtns;
    semestre.layoutDisciplinas->setSpacing(8);
    semestre.layoutDisciplinas->setContentsMargins(0, 0, 0, 0);

    QLabel* label = new QLabel(QString("Semestre %1").arg(periodoAtualSimulado));
    label->setStyleSheet("font-weight: bold; color: black;");
    semestre.layoutCheck->addWidget(label);

    for (const auto& disc : elegiveis) {
        QString nome = QString::fromStdString(disc.nome);
        QCheckBox* chk = new QCheckBox(nome);
        chk->setStyleSheet("color: black; margin: 6px;");
        semestre.checkboxes.append(chk);
        semestre.layoutCheck->addWidget(chk);

        int indiceSemestre = semestres.size();

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
            }

            // Atualizar semestres posteriores (remover se mudou o anterior)
            while (!semestres.isEmpty() && semestres.last().numero > semestreRef.numero) {
                QLayoutItem* item;
                while ((item = layoutSimulacao->takeAt(layoutSimulacao->count() - 1))) {
                    if (item->layout()) delete item->layout();
                    else if (item->widget()) delete item->widget();
                    delete item;
                }
                semestres.removeLast();
                periodoAtualSimulado--;
            }
        });
    }

    layoutSimulacao->addLayout(semestre.layoutCheck);
    layoutSimulacao->addWidget(containerDisciplinas, Qt::AlignHCenter);
    semestres.append(semestre);
    periodoAtualSimulado++;
}

void SimulacaoPlanejamentoSEM::salvarComoImagem()
{
    // Esconde os checkboxes
    for (const auto& semestre : semestres) {
        for (QCheckBox* chk : semestre.checkboxes) {
            chk->hide();
        }
    }

    // Renderiza
    QSize size = container->sizeHint();
    QPixmap imagem(size);
    imagem.fill(Qt::white);
    container->render(&imagem);

    // Salva com nome novo
    QString nomeArquivo = "Simulacao_Planejamento.png";
    int contador = 1;
    while (QFile::exists(nomeArquivo)) {
        nomeArquivo = QString("Simulacao_Planejamento_%1.png").arg(contador++);
    }

    // Mostra novamente os checkboxes
    for (const auto& semestre : semestres) {
        for (QCheckBox* chk : semestre.checkboxes) {
            chk->show();
        }
    }

    if (imagem.save(nomeArquivo)) {
        QMessageBox::information(this, "Sucesso", "Imagem salva como " + nomeArquivo);
    } else {
        QMessageBox::warning(this, "Erro", "Falha ao salvar a imagem.");
    }
}
