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
                }
                break;
            }
        }
        arquivo.close();
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
        QLabel* label = new QLabel;
        QFont fonte("Bookman Old Style", 18, QFont::Bold);
        label->setFont(fonte);

        double nota = 0.0, peso = 1.0;

        if (v.startsWith("-(") && v.endsWith(")")) {
            QString pesoStr = v.mid(2, v.length() - 3).trimmed();
            peso = pesoStr.toDouble();
            label->setText("?");
            label->setStyleSheet("color: gray;");
            previsoesCinza.append({label, peso});
            ent.layout->addWidget(label);
            continue;
        }

        if (v == "-" || v.isEmpty()) {
            label->setText("?");
            label->setStyleSheet("color: gray;");
            previsoesCinza.append({label, 1.0});
            ent.layout->addWidget(label);
            continue;
        }

        if (v.contains("(") && v.endsWith(")")) {
            QString notaStr = v.section("(", 0, 0).trimmed();
            QString pesoStr = v.section("(", 1, 1).remove(")").trimmed();
            nota = notaStr.toDouble();
            peso = pesoStr.toDouble();
        } else {
            nota = v.toDouble();
            peso = 1.0;
        }

        somaNotas += nota * peso;
        somaPesos += peso;

        label->setText(QString::number(nota));
        label->setStyleSheet(nota >= 60 ? "color: green;" : "color: red;");
        ent.layout->addWidget(label);
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

    // Atualizar labelMedia com base nas notas simuladas de fato
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
