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

            if (secaoDisciplinas && !linha.isEmpty() && linha.startsWith(nomeDisciplina + " ;")) {
                QStringList partes = linha.split(";", Qt::SkipEmptyParts);
                if (partes.size() >= 5) {
                    QString trabalhosStr = partes[3].trimmed().remove("Trabalhos:").trimmed();
                    QString provasStr = partes[4].trimmed().remove("Provas:").trimmed();

                    preencherAmbosLayouts(trabalhosStr, provasStr);
                    encontrado = true;
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
            out << nomeDisciplina << " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: -(1) ; Provas: -(1)\n";
            arqAppend.close();

            // Preenche com a estrutura padrão
            preencherAmbosLayouts("-(1)", "-(1)");
        }
    }

}

AcompanhamentoDisciplina::~AcompanhamentoDisciplina()
{
    delete ui;
}

void AcompanhamentoDisciplina::preencherAmbosLayouts(const QString& trabs, const QString& provas)
{
    struct Entrada {
        QString tipo; // "trab" ou "prova"
        QString valorStr;
        QHBoxLayout* layout;
    };

    QList<Entrada> entradas;

    QStringList trabList = trabs.split(",", Qt::KeepEmptyParts);
    QStringList provaList = provas.split(",", Qt::KeepEmptyParts);

    for (const QString& val : trabList)
        entradas.append({"trab", val.trimmed(), ui->horizontalLayoutTrabs});
    for (const QString& val : provaList)
        entradas.append({"prova", val.trimmed(), ui->horizontalLayoutProvas});

    double somaNotas = 0.0;
    double somaPesos = 0.0;
    QList<QPair<QLabel*, double>> previsoesCinza;

    for (const Entrada& ent : entradas) {
        QString v = ent.valorStr;
        double nota = 0.0, peso = 1.0;

        // Interpretação do valor
        if (v.startsWith("-(") && v.endsWith(")")) {
            QString pesoStr = v.mid(2, v.length() - 3).trimmed();
            peso = pesoStr.toDouble();
        } else if (v == "-" || v.isEmpty()) {
            peso = 1.0;
        } else if (v.contains("(") && v.endsWith(")")) {
            QString notaStr = v.section("(", 0, 0).trimmed();
            QString pesoStr = v.section("(", 1, 1).remove(")").trimmed();
            nota = notaStr.toDouble();
            peso = pesoStr.toDouble();
        } else {
            nota = v.toDouble();
            peso = 1.0;
        }

        // Criar os widgets
        QLabel* labelNota = new QLabel;
        QFont fonteNota("Bookman Old Style", 18, QFont::Bold);
        labelNota->setFont(fonteNota);
        labelNota->setAlignment(Qt::AlignHCenter);


        QLabel* labelPeso = new QLabel;
        QFont fontePeso("Bookman Old Style", 10);
        labelPeso->setFont(fontePeso);
        labelPeso->setText(QString("peso %1").arg(peso));
        labelPeso->setAlignment(Qt::AlignHCenter);

        QVBoxLayout* vbox = new QVBoxLayout;
        vbox->setSpacing(0);
        vbox->setContentsMargins(0, 0, 0, 0);
        vbox->addWidget(labelNota);
        vbox->addWidget(labelPeso);

        QWidget* container = new QWidget;
        container->setLayout(vbox);
        ent.layout->addWidget(container);

        // Lógica de cor e soma
        if (v.startsWith("-(") && v.endsWith(")")) {
            labelNota->setText("?");
            labelNota->setStyleSheet("color: gray;");
            previsoesCinza.append({labelNota, peso});
            continue;
        }

        if (v == "-" || v.isEmpty()) {
            labelNota->setText("?");
            labelNota->setStyleSheet("color: gray;");
            previsoesCinza.append({labelNota, peso});
            continue;
        }

        labelNota->setText(QString::number(nota));
        labelNota->setStyleSheet(nota >= 60 ? "color: green;" : "color: red;");
        somaNotas += nota * peso;
        somaPesos += peso;
    }

    double pesoFaltante = 0.0;
    for (const auto& par : previsoesCinza)
        pesoFaltante += par.second;

    if (pesoFaltante > 0.0) {
        double notaNecessaria = (60.0 * (somaPesos + pesoFaltante) - somaNotas) / pesoFaltante;
        notaNecessaria = qMax(0.0, notaNecessaria);

        for (auto& par : previsoesCinza) {
            QLabel* label = par.first;
            label->setText(QString::number(notaNecessaria, 'f', 1));
            label->setStyleSheet("color: gray;");
        }
    }

    // Média final
    double somaCinza = 0.0;
    for (const auto& par : previsoesCinza) {
        bool ok;
        double valor = par.first->text().toDouble(&ok);
        if (ok)
            somaCinza += valor * par.second;
    }

    double mediaFinal = (somaPesos + pesoFaltante) > 0 ? ((somaNotas + somaCinza) / (somaPesos + pesoFaltante)) : 0.0;
    ui->labelMedia->setText(QString::number(mediaFinal, 'f', 1));
    if (!previsoesCinza.isEmpty())
        ui->labelMedia->setStyleSheet("color: gray;");
    else
        ui->labelMedia->setStyleSheet(mediaFinal >= 60 ? "color: green;" : "color: red;");
}
