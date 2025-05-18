#include "acompanhamentoDisciplina.h"
#include "ui_acompanhamentoDisciplina.h"
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>

AcompanhamentoDisciplina::AcompanhamentoDisciplina(const QString& nomeDisciplina, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AcompanhamentoDisciplina)
{
    ui->setupUi(this);
    ui->label_NomeDisc->setText(nomeDisciplina);
    nomeAtualDisciplina = nomeDisciplina.trimmed();
    modoEdicaoAtivo = false;

    // Desabilita os botões até o modo de edição ser ativado
    ui->botaoAdcTrab->setEnabled(false);
    ui->botaoAdcProva->setEnabled(false);
    ui->botaoRemTrab->setEnabled(false);
    ui->botaoRemProva->setEnabled(false);
    ui->botaoSalvar->setEnabled(false);

    // Conectar os botões aos slots
    connect(ui->botaoEditar, &QPushButton::clicked, this, &AcompanhamentoDisciplina::aoClicarEditar);
    connect(ui->botaoSalvar, &QPushButton::clicked, this, &AcompanhamentoDisciplina::aoClicarSalvar);
    connect(ui->botaoAdcTrab, &QPushButton::clicked, this, &AcompanhamentoDisciplina::adicionarTrabalho);
    connect(ui->botaoRemTrab, &QPushButton::clicked, this, &AcompanhamentoDisciplina::removerTrabalho);
    connect(ui->botaoAdcProva, &QPushButton::clicked, this, &AcompanhamentoDisciplina::adicionarProva);
    connect(ui->botaoRemProva, &QPushButton::clicked, this, &AcompanhamentoDisciplina::removerProva);



    QFile arquivo("InformacoesAluno.txt");
    bool encontrado = false;

    if (arquivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&arquivo);
        bool secaoDisciplinas = false;

        while (!in.atEnd()) {
            QString linha = in.readLine().trimmed();

            if (linha == "Disciplinas em Andamento:") {
                secaoDisciplinas = true;
                continue;
            }

            if (secaoDisciplinas && !linha.isEmpty() &&
                linha.section(";", 0, 0).trimmed() == nomeAtualDisciplina) {
                QStringList partes = linha.split(";", Qt::SkipEmptyParts);
                if (partes.size() >= 5) {
                    QString trabalhosStr = partes[3].trimmed().remove("Trabalhos:").trimmed();
                    QString provasStr = partes[4].trimmed().remove("Provas:").trimmed();

                    preencherAmbosLayouts(trabalhosStr, provasStr);
                    encontrado = true;

                    novaListaTrabalhos = trabalhosStr.split(",", Qt::KeepEmptyParts);
                    novaListaProvas = provasStr.split(",", Qt::KeepEmptyParts);
                }
                break;
            }
        }
        arquivo.close();
    }

    // Se não encontrou a disciplina no txt, adiciona uma linha padrão
    if (!encontrado) {
        QFile arqAppend("InformacoesAluno.txt");
        if (arqAppend.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&arqAppend);
            out << nomeAtualDisciplina << " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: -(1) ; Provas: -(1)\n";
            arqAppend.close();

            preencherAmbosLayouts("-(1)", "-(1)");
            novaListaTrabalhos = {"-(1)"};
            novaListaProvas = {"-(1)"};
        }
    }
}

AcompanhamentoDisciplina::~AcompanhamentoDisciplina()
{
    delete ui;
}

void AcompanhamentoDisciplina::preencherAmbosLayouts(const QString& trabs, const QString& provas)
{
    // Limpa layouts antes de preencher novamente
    QLayoutItem *item;
    while ((item = ui->horizontalLayoutTrabs->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    while ((item = ui->horizontalLayoutProvas->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    struct Entrada {
        QString tipo;
        QString valorStr;
        QHBoxLayout* layout;
    };

    QList<Entrada> entradas;
    for (const QString& val : trabs.split(",", Qt::KeepEmptyParts)) {
        QString trimmedVal = val.trimmed();
        if (!trimmedVal.isEmpty())
            entradas.append({"trab", trimmedVal, ui->horizontalLayoutTrabs});
    }

    for (const QString& val : provas.split(",", Qt::KeepEmptyParts)) {
        QString trimmedVal = val.trimmed();
        if (!trimmedVal.isEmpty())
            entradas.append({"prova", trimmedVal, ui->horizontalLayoutProvas});
    }

    double somaNotas = 0.0, somaPesos = 0.0;
    QList<QPair<QLabel*, double>> previsoesCinza;

    for (const Entrada& ent : entradas) {
        QString v = ent.valorStr;
        double nota = 0.0, peso = 1.0;

        if (v.startsWith("-(") && v.endsWith(")"))
            peso = v.mid(2, v.length() - 3).trimmed().toDouble();
        else if (v.contains("(") && v.endsWith(")")) {
            nota = v.section("(", 0, 0).trimmed().toDouble();
            peso = v.section("(", 1, 1).remove(")").trimmed().toDouble();
        } else if (!v.isEmpty() && v != "-")
            nota = v.toDouble();

        QLabel* labelNota = new QLabel;
        labelNota->setFont(QFont("Bookman Old Style", 18, QFont::Bold));
        labelNota->setAlignment(Qt::AlignHCenter);

        QLabel* labelPeso = new QLabel(QString("peso %1").arg(peso));
        labelPeso->setFont(QFont("Bookman Old Style", 10));
        labelPeso->setAlignment(Qt::AlignHCenter);

        QVBoxLayout* vbox = new QVBoxLayout;
        vbox->addWidget(labelNota);
        vbox->addWidget(labelPeso);
        QWidget* container = new QWidget;
        container->setLayout(vbox);
        ent.layout->addWidget(container);

        if (v.startsWith("-(") || v == "-" || v.isEmpty()) {
            labelNota->setText("?");
            labelNota->setStyleSheet("color: gray;");
            previsoesCinza.append({labelNota, peso});
        } else {
            labelNota->setText(QString::number(nota));
            labelNota->setStyleSheet(nota >= 60 ? "color: green;" : "color: red;");
            somaNotas += nota * peso;
            somaPesos += peso;
        }
    }

    double pesoFaltante = 0.0;
    for (const auto& par : previsoesCinza) pesoFaltante += par.second;

    if (pesoFaltante > 0.0) {
        double notaNecessaria = (60.0 * (somaPesos + pesoFaltante) - somaNotas) / pesoFaltante;
        notaNecessaria = qMax(0.0, notaNecessaria);
        for (auto& par : previsoesCinza)
            par.first->setText(QString::number(notaNecessaria, 'f', 1));
    }

    double somaCinza = 0.0;
    for (const auto& par : previsoesCinza) {
        bool ok;
        double valor = par.first->text().toDouble(&ok);
        if (ok) somaCinza += valor * par.second;
    }

    double mediaFinal = (somaPesos + pesoFaltante) > 0 ? ((somaNotas + somaCinza) / (somaPesos + pesoFaltante)) : 0.0;
    ui->labelMedia->setText(QString::number(mediaFinal, 'f', 1));
    ui->labelMedia->setStyleSheet(previsoesCinza.isEmpty() ? (mediaFinal >= 60 ? "color: green;" : "color: red;") : "color: gray;");
}

void AcompanhamentoDisciplina::aoClicarEditar()
{
    modoEdicaoAtivo = true;

    ui->botaoEditar->setStyleSheet("background-color: #a6a6a6; color: white;");
    ui->botaoSalvar->setStyleSheet("background-color: #ffa308; color: white;");
    ui->botaoAdcProva->setStyleSheet("background-color: #ffa308; color: white;");
    ui->botaoAdcTrab->setStyleSheet("background-color: #ffa308; color: white;");
    ui->botaoRemProva->setStyleSheet("background-color: #ffa308; color: white;");
    ui->botaoRemTrab->setStyleSheet("background-color: #ffa308; color: white;");

    ui->botaoSalvar->setEnabled(true);
    ui->botaoAdcProva->setEnabled(true);
    ui->botaoAdcTrab->setEnabled(true);
    ui->botaoRemProva->setEnabled(true);
    ui->botaoRemTrab->setEnabled(true);
}

void AcompanhamentoDisciplina::aoClicarSalvar()
{
    if (!modoEdicaoAtivo) return;

    modoEdicaoAtivo = false;

    ui->botaoEditar->setStyleSheet("background-color: #ffa308; color: white;");
    ui->botaoSalvar->setStyleSheet("background-color: #a6a6a6; color: white;");
    ui->botaoAdcProva->setStyleSheet("background-color: #a6a6a6; color: white;");
    ui->botaoAdcTrab->setStyleSheet("background-color: #a6a6a6; color: white;");
    ui->botaoRemProva->setStyleSheet("background-color: #a6a6a6; color: white;");
    ui->botaoRemTrab->setStyleSheet("background-color: #a6a6a6; color: white;");

    ui->botaoSalvar->setEnabled(false);
    ui->botaoAdcProva->setEnabled(false);
    ui->botaoAdcTrab->setEnabled(false);
    ui->botaoRemProva->setEnabled(false);
    ui->botaoRemTrab->setEnabled(false);

    salvarAlteracoes();
}

void AcompanhamentoDisciplina::adicionarTrabalho()
{
    if (!modoEdicaoAtivo) return;

    novaListaTrabalhos.append("-(1)");
    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}


void AcompanhamentoDisciplina::removerTrabalho()
{
    if (!modoEdicaoAtivo) return;

    if (!novaListaTrabalhos.isEmpty())
        novaListaTrabalhos.removeLast();

    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}


void AcompanhamentoDisciplina::adicionarProva()
{
    if (!modoEdicaoAtivo) return;

    novaListaProvas.append("-(1)");
    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}

void AcompanhamentoDisciplina::removerProva()
{
    if (!modoEdicaoAtivo) return;

    if (!novaListaProvas.isEmpty())
        novaListaProvas.removeLast();

    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}



void AcompanhamentoDisciplina::salvarAlteracoes()
{
    QFile file("InformacoesAluno.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QStringList linhas;
    QTextStream in(&file);
    bool linhaSubstituida = false;

    while (!in.atEnd()) {
        QString linha = in.readLine();
        QString nomeNaLinha = linha.section(";", 0, 0).trimmed();
        if (!linhaSubstituida && nomeNaLinha == nomeAtualDisciplina) {
            QString novaLinha = nomeAtualDisciplina + " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: " +
                                novaListaTrabalhos.join(",") + " ; Provas: " + novaListaProvas.join(",");
            linhas.append(novaLinha);
            linhaSubstituida = true;
        } else {
            linhas.append(linha);
        }
    }
    file.close();

    if (!linhaSubstituida) {
        QString novaLinha = nomeAtualDisciplina + " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: " +
                            novaListaTrabalhos.join(",") + " ; Provas: " + novaListaProvas.join(",");
        linhas.append(novaLinha);
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const QString& l : linhas)
            out << l.trimmed() << "\n";
        file.close();
    }
}
