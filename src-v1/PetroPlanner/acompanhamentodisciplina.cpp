#include "acompanhamentoDisciplina.h"
#include "ui_acompanhamentoDisciplina.h"
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QCheckBox>

AcompanhamentoDisciplina::AcompanhamentoDisciplina(const QString& nomeDisciplina, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AcompanhamentoDisciplina)
{
    ui->setupUi(this);
    ui->label_NomeDisc->setText(nomeDisciplina);
    nomeAtualDisciplina = nomeDisciplina.trimmed();
    modoEdicaoAtivo = false;

    ui->botaoAdcTrab->setEnabled(false);
    ui->botaoAdcProva->setEnabled(false);
    ui->botaoRemTrab->setEnabled(false);
    ui->botaoRemProva->setEnabled(false);
    ui->botaoSalvar->setEnabled(false);

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

            if (secaoDisciplinas && !linha.isEmpty() && linha.section(";", 0, 0).trimmed() == nomeAtualDisciplina) {
                QStringList partes = linha.split(";", Qt::SkipEmptyParts);
                if (partes.size() >= 5) {
                    QString trabalhosStr = partes[3].trimmed().remove("Trabalhos:").trimmed();
                    QString provasStr = partes[4].trimmed().remove("Provas:").trimmed();
                    novaListaTrabalhos = trabalhosStr.split(",", Qt::KeepEmptyParts);
                    novaListaProvas = provasStr.split(",", Qt::KeepEmptyParts);
                    preencherAmbosLayouts(trabalhosStr, provasStr);
                    encontrado = true;
                }
                break;
            }
        }
        arquivo.close();
    }

    if (!encontrado) {
        QFile arqAppend("InformacoesAluno.txt");
        if (arqAppend.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&arqAppend);
            out << nomeAtualDisciplina << " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: -(1) ; Provas: -(1)\n";
            arqAppend.close();

            novaListaTrabalhos = {"-(1)"};
            novaListaProvas = {"-(1)"};
            preencherAmbosLayouts("-(1)", "-(1)");
        }
    }
}

AcompanhamentoDisciplina::~AcompanhamentoDisciplina() { delete ui; }

void AcompanhamentoDisciplina::preencherAmbosLayouts(const QString& trabs, const QString& provas) {
    auto limparLayout = [](QHBoxLayout* layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget(); delete item;
        }
    };

    limparLayout(ui->horizontalLayoutTrabs);
    limparLayout(ui->horizontalLayoutProvas);
    entradasTrabalhos.clear();
    entradasProvas.clear();

    auto adicionarCampo = [&](const QString& valorStr, QHBoxLayout* layout, QList<EntradaNota>& listaDestino) {
        double nota = 0.0, peso = 1.0;
        bool notaPreenchida = false;

        if (valorStr.startsWith("-(") && valorStr.endsWith(")"))
            peso = valorStr.mid(2, valorStr.length() - 3).toDouble();
        else if (valorStr.contains("(") && valorStr.endsWith(")")) {
            nota = valorStr.section("(", 0, 0).toDouble();
            peso = valorStr.section("(", 1, 1).remove(")").toDouble();
            notaPreenchida = true;
        } else if (!valorStr.isEmpty() && valorStr != "-") {
            nota = valorStr.toDouble();
            notaPreenchida = true;
        }

        QLineEdit* editNota = new QLineEdit;
        QLineEdit* editPeso = new QLineEdit;

        editNota->setText(notaPreenchida ? QString::number(nota, 'f', 1) : "");
        editNota->setPlaceholderText("?");
        editPeso->setText(QString::number(peso));

        QFont fontNota("Bookman Old Style", 18, QFont::Bold);
        QFont fontPeso("Bookman Old Style", 10);
        editNota->setFont(fontNota);
        editPeso->setFont(fontPeso);

        editNota->setAlignment(Qt::AlignHCenter);
        editPeso->setAlignment(Qt::AlignHCenter);

        editNota->setReadOnly(!modoEdicaoAtivo);
        editPeso->setReadOnly(!modoEdicaoAtivo);

        QCheckBox* checkSimulado = new QCheckBox("Simulado");
        checkSimulado->setChecked(!notaPreenchida);
        checkSimulado->setEnabled(modoEdicaoAtivo);

        QVBoxLayout* vbox = new QVBoxLayout;
        vbox->addWidget(editNota);
        vbox->addWidget(editPeso);
        vbox->addWidget(checkSimulado);

        QWidget* container = new QWidget;
        container->setLayout(vbox);
        layout->addWidget(container);

        listaDestino.append({editNota, editPeso, checkSimulado});

        if (modoEdicaoAtivo) {
            connect(editNota, &QLineEdit::textChanged, this, &AcompanhamentoDisciplina::atualizarMedia);
            connect(editPeso, &QLineEdit::textChanged, this, &AcompanhamentoDisciplina::atualizarMedia);
        }
    };

    for (const QString& val : trabs.split(",", Qt::KeepEmptyParts))
        if (!val.trimmed().isEmpty())
            adicionarCampo(val.trimmed(), ui->horizontalLayoutTrabs, entradasTrabalhos);

    for (const QString& val : provas.split(",", Qt::KeepEmptyParts))
        if (!val.trimmed().isEmpty())
            adicionarCampo(val.trimmed(), ui->horizontalLayoutProvas, entradasProvas);

    atualizarMedia();
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

    for (auto& e : entradasTrabalhos) {
        e.editNota->setReadOnly(false);
        e.editPeso->setReadOnly(false);
        e.checkSimulado->setEnabled(true);
    }
    for (auto& e : entradasProvas) {
        e.editNota->setReadOnly(false);
        e.editPeso->setReadOnly(false);
        e.checkSimulado->setEnabled(true);
    }
}

void AcompanhamentoDisciplina::aoClicarSalvar()
{
    if (!modoEdicaoAtivo) return;
    modoEdicaoAtivo = false;

    for (auto& e : entradasTrabalhos) {
        e.editNota->setReadOnly(true);
        e.editPeso->setReadOnly(true);
        e.checkSimulado->setEnabled(false);
    }
    for (auto& e : entradasProvas) {
        e.editNota->setReadOnly(true);
        e.editPeso->setReadOnly(true);
        e.checkSimulado->setEnabled(false);
    }

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
    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}


void AcompanhamentoDisciplina::salvarAlteracoes() {
    auto converter = [](const QList<EntradaNota>& entradas) {
        QStringList lista;
        for (const auto& e : entradas) {
            QString nota = e.editNota->text().trimmed();
            QString peso = e.editPeso->text().trimmed();
            if (e.checkSimulado->isChecked() || nota.isEmpty())
                lista << QString("-(%1)").arg(peso);
            else
                lista << QString("%1(%2)").arg(nota).arg(peso);
        }
        return lista;
    };

    novaListaTrabalhos = converter(entradasTrabalhos);
    novaListaProvas = converter(entradasProvas);

    QFile file("InformacoesAluno.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QStringList linhas;
    QTextStream in(&file);
    bool linhaSubstituida = false;

    while (!in.atEnd()) {
        QString linha = in.readLine();
        QString nomeNaLinha = linha.section(";", 0, 0).trimmed();

        if (!linhaSubstituida && nomeNaLinha == nomeAtualDisciplina) {
            QStringList partes = linha.split(";");
            if (partes.size() >= 5) {
                // Mantém faltas e dias/horários
                QString faltas = partes[1].trimmed();
                QString diasHorarios = partes[2].trimmed();
                QString novaLinha = nomeAtualDisciplina + " ; " + faltas + " ; " + diasHorarios +
                                    " ; Trabalhos: " + novaListaTrabalhos.join(",") +
                                    " ; Provas: " + novaListaProvas.join(",");
                linhas.append(novaLinha);
            } else {
                // Se a linha estiver malformada, mantém comportamento anterior como fallback
                QString novaLinha = nomeAtualDisciplina + " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: " +
                                    novaListaTrabalhos.join(",") + " ; Provas: " + novaListaProvas.join(",");
                linhas.append(novaLinha);
            }
            linhaSubstituida = true;
        } else {
            linhas.append(linha);
        }
    }
    file.close();

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const QString& l : linhas)
            out << l.trimmed() << "\n";
        file.close();
    }
}


void AcompanhamentoDisciplina::atualizarMedia() {
    double somaNotas = 0.0, somaPesos = 0.0;
    QList<QPair<QLineEdit*, double>> previsoesCinza;

    auto processar = [&](const QList<EntradaNota>& lista) {
        for (const auto& e : lista) {
            QString notaStr = e.editNota->text().trimmed();
            QString pesoStr = e.editPeso->text().trimmed();
            bool okNota = false, okPeso = false;
            double nota = notaStr.toDouble(&okNota);
            double peso = pesoStr.toDouble(&okPeso);
            if (!okPeso) peso = 1.0;

            if (e.checkSimulado->isChecked()) {
                previsoesCinza.append({e.editNota, peso});
                e.editNota->setStyleSheet("color: gray;");
            } else if (okNota) {
                somaNotas += nota * peso;
                somaPesos += peso;
                e.editNota->setStyleSheet(nota >= 60 ? "color: green;" : "color: red;");
            }
        }
    };

    processar(entradasTrabalhos);
    processar(entradasProvas);

    double pesoFaltante = 0.0;
    for (const auto& par : previsoesCinza)
        pesoFaltante += par.second;

    double notaNecessaria = 60.0;
    if (pesoFaltante > 0.0)
        notaNecessaria = (60.0 * (somaPesos + pesoFaltante) - somaNotas) / pesoFaltante;

    notaNecessaria = qMax(0.0, notaNecessaria);

    for (auto& par : previsoesCinza) {
        par.first->blockSignals(true);
        par.first->setText(QString::number(notaNecessaria, 'f', 1));
        par.first->blockSignals(false);
    }

    double somaCinza = 0.0;
    for (const auto& par : previsoesCinza) {
        bool ok;
        double valor = par.first->text().toDouble(&ok);
        if (ok) somaCinza += valor * par.second;
    }

    double mediaFinal = (somaPesos + pesoFaltante) > 0 ?
                            ((somaNotas + somaCinza) / (somaPesos + pesoFaltante)) : 0.0;

    ui->labelMedia->setText(QString::number(mediaFinal, 'f', 1));
    ui->labelMedia->setStyleSheet(previsoesCinza.isEmpty() ?
                                      (mediaFinal >= 60 ? "color: green;" : "color: red;") : "color: gray;");
}

void AcompanhamentoDisciplina::adicionarTrabalho() {
    if (!modoEdicaoAtivo) return;
    novaListaTrabalhos.append("-(1)");
    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}

void AcompanhamentoDisciplina::removerTrabalho() {
    if (!modoEdicaoAtivo) return;
    if (!novaListaTrabalhos.isEmpty())
        novaListaTrabalhos.removeLast();
    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}

void AcompanhamentoDisciplina::adicionarProva() {
    if (!modoEdicaoAtivo) return;
    novaListaProvas.append("-(1)");
    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}

void AcompanhamentoDisciplina::removerProva() {
    if (!modoEdicaoAtivo) return;
    if (!novaListaProvas.isEmpty())
        novaListaProvas.removeLast();
    preencherAmbosLayouts(novaListaTrabalhos.join(","), novaListaProvas.join(","));
}
