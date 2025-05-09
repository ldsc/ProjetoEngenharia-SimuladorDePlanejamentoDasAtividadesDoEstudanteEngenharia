#include "acompanhamentoDisciplina.h"
#include "ui_acompanhamentoDisciplina.h"
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QHBoxLayout>

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

                    preencherNotas(ui->horizontalLayoutTrabs, trabalhosStr);
                    preencherNotas(ui->horizontalLayoutProvas, provasStr);
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

void AcompanhamentoDisciplina::preencherNotas(QHBoxLayout* layout, const QString& notasStr)
{
    if (notasStr.trimmed().isEmpty()) return;

    QStringList valores = notasStr.split(",", Qt::KeepEmptyParts); // importante manter vazio!
    double somaNotas = 0.0;
    int numPreenchidos = 0;
    int totalPrevistos = valores.size();

    for (const QString& val : valores) {
        QString v = val.trimmed();
        QLabel* label = new QLabel;
        QFont fonte("Bookman Old Style", 18, QFont::Bold);
        label->setFont(fonte);

        if (v == "-" || v.isEmpty()) {
            // Temporariamente pula, será tratado depois
            label->setText("?");
            label->setStyleSheet("color: gray;");
        } else {
            double nota = v.toDouble();
            somaNotas += nota;
            numPreenchidos++;

            label->setText(QString::number(nota));
            label->setStyleSheet(nota >= 60 ? "color: green;" : "color: red;");
        }

        layout->addWidget(label);
    }

    // Preencher os "?" com a nota necessária para atingir média 60
    int faltando = totalPrevistos - numPreenchidos;
    if (faltando > 0) {
        double notaNecessaria = (60.0 * totalPrevistos - somaNotas) / faltando;
        notaNecessaria = qMax(0.0, notaNecessaria); // evita número negativo

        // Atualiza os labels com "?" para a nota prevista
        for (int i = 0; i < layout->count(); ++i) {
            QWidget* widget = layout->itemAt(i)->widget();
            QLabel* label = qobject_cast<QLabel*>(widget);
            if (label && label->text() == "?") {
                label->setText(QString::number(notaNecessaria, 'f', 1));
                label->setStyleSheet("color: gray;");
            }
        }
    }
}
