#include "quadrodehorarios.h"
#include "ui_quadrodehorarios.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMessageBox>

QuadroDeHorarios::QuadroDeHorarios(CAluno* aluno, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuadroDeHorarios)
    , aluno(aluno)
{
    ui->setupUi(this);
    preencherQuadro();
}

QuadroDeHorarios::~QuadroDeHorarios()
{
    delete ui;
}

void QuadroDeHorarios::preencherQuadro()
{
    ui->tableWidgetQuadroHor->clearContents();

    QString resumoHorarios;

    for (const auto& disc : aluno->disciplinasEmCurso) {
        QString nome = QString::fromStdString(disc.nome);
        QString diasHorarios = disc.diasHorarios;

        resumoHorarios += nome + ": " + diasHorarios + "\n";

        QStringList blocos = diasHorarios.split(",", Qt::SkipEmptyParts);

        for (QString bloco : blocos) {
            bloco = bloco.trimmed();

            if (!bloco.contains(":") || !bloco.contains("-"))
                continue;

            QString diaCompleto = bloco.section(":", 0, 0).trimmed();
            QString faixa = bloco.section(":", 1).trimmed();

            QString diaAbrev = diaCompleto.left(3).toLower();
            diaAbrev[0] = diaAbrev[0].toUpper();  // "segunda" → "Seg"

            QString horaIniStr = faixa.section("-", 0, 0).trimmed(); // "8h"
            QString horaFimStr = faixa.section("-", 1, 1).trimmed(); // "10h"

            bool okIni = false, okFim = false;
            int horaIni = horaIniStr.remove("h").toInt(&okIni);
            int horaFim = horaFimStr.remove("h").toInt(&okFim);

            if (!okIni || !okFim) continue;

            for (int h = horaIni; h < horaFim; ++h) {
                QString horaAtual = QString::number(h) + "h";
                int linha = horarioParaLinha(horaAtual);
                int coluna = diaParaColuna(diaAbrev);

                if (linha >= 0 && coluna >= 0) {
                    QTableWidgetItem* item = new QTableWidgetItem(nome);
                    static QList<QColor> coresDisponiveis = {
                        QColor("#F44336"), // Vermelho
                        QColor("#2196F3"), // Azul
                        QColor("#4CAF50"), // Verde
                        QColor("#FF9800"), // Laranja
                        QColor("#9C27B0"), // Roxo
                        QColor("#009688"), // Verde-água
                        QColor("#FFEB3B"), // Amarelo
                        QColor("#3F51B5"), // Azul escuro
                        QColor("#CDDC39"), // Verde limão
                        QColor("#E91E63"), // Rosa forte
                        QColor("#00BCD4"), // Azul piscina
                        QColor("#795548")  // Marrom
                    };

                    static QMap<QString, QColor> mapaCores;

                    if (!mapaCores.contains(nome)) {
                        QColor cor = coresDisponiveis[mapaCores.size() % coresDisponiveis.size()];
                        mapaCores[nome] = cor;
                    }

                    item->setBackground(mapaCores[nome]);

                    item->setTextAlignment(Qt::AlignCenter);
                    ui->tableWidgetQuadroHor->setItem(linha, coluna, item);
                }
            }
        }
    }

    // Exibe os horários lidos depois de preencher o quadro
    //QMessageBox::information(this, "Horários Lidos", resumoHorarios);
}





int QuadroDeHorarios::horarioParaLinha(const QString& horario)
{
    static QStringList listaHoras = {
        "6h", "7h", "8h", "9h", "10h", "11h", "12h", "13h",
        "14h", "15h", "16h", "17h", "18h", "19h", "20h", "21h", "22h", "23h"
    };
    return listaHoras.indexOf(horario);
}

int QuadroDeHorarios::diaParaColuna(const QString& dia)
{
    static QMap<QString, int> mapaDias = {
        {"Seg", 0}, {"Ter", 1}, {"Qua", 2}, {"Qui", 3},
        {"Sex", 4}, {"Sab", 5}, {"Dom", 6}
    };
    return mapaDias.value(dia, -1);
}

