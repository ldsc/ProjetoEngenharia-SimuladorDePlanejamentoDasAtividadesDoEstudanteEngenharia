#include "quadrodehorarios.h"
#include "ui_quadrodehorarios.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

QuadroDeHorarios::QuadroDeHorarios(CAluno* aluno, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuadroDeHorarios)
    , aluno(aluno)
{
    ui->setupUi(this);

    connect(ui->botaoEditar, &QPushButton::clicked, this, &QuadroDeHorarios::aoClicarEditar);
    connect(ui->botaoSalvar, &QPushButton::clicked, this, &QuadroDeHorarios::aoClicarSalvar);

    coresDisponiveis = {
        QColor("#F44336"), QColor("#2196F3"), QColor("#4CAF50"), QColor("#FF9800"),
        QColor("#9C27B0"), QColor("#009688"), QColor("#FFEB3B"), QColor("#3F51B5"),
        QColor("#CDDC39"), QColor("#E91E63"), QColor("#00BCD4"), QColor("#795548")
    };

    definirModoEdicao(false);
    preencherQuadro();



    // Mostrar aviso com disciplinas e atividades
    QString aviso = "Disciplinas em curso detectadas:\n";
    for (const auto& d : aluno->disciplinasEmCurso)
        aviso += "- " + QString::fromStdString(d.nome) + "\n";

    aviso += "\nAtividades extras detectadas:\n";
    for (const auto& a : aluno->atividadesExtras)
        aviso += "- " + a + "\n";

    QMessageBox::information(this, "Resumo Inicial", aviso);

}

QuadroDeHorarios::~QuadroDeHorarios()
{
    delete ui;
}

void QuadroDeHorarios::definirModoEdicao(bool ativo)
{
    modoEdicaoAtivo = ativo;

    ui->tableWidgetQuadroHor->setEditTriggers(ativo ? QAbstractItemView::DoubleClicked : QAbstractItemView::NoEditTriggers);

    ui->botaoEditar->setStyleSheet(ativo ? "background-color: #a6a6a6; color: white; border-radius: 10px;" : "background-color: #ffa308; color: white; border-radius: 10px;");
    ui->botaoSalvar->setStyleSheet(ativo ? "background-color: #ffa308; color: white; border-radius: 10px;" : "background-color: #a6a6a6; color: white; border-radius: 10px;");

    ui->botaoEditar->setEnabled(!ativo);
    ui->botaoSalvar->setEnabled(ativo);
}

void QuadroDeHorarios::aoClicarEditar()
{
    definirModoEdicao(true);
}

void QuadroDeHorarios::aoClicarSalvar()
{
    definirModoEdicao(false);
    salvarAtividadesExtras();
}

void QuadroDeHorarios::preencherQuadro()
{
    ui->tableWidgetQuadroHor->clearContents();

    // Preencher com disciplinas em curso
    for (const auto& disc : aluno->disciplinasEmCurso) {
        QString nome = QString::fromStdString(disc.nome);
        QString diasHorarios = disc.diasHorarios;

        QStringList blocos = diasHorarios.split(",", Qt::SkipEmptyParts);
        for (QString bloco : blocos) {
            QString dia = bloco.section(":", 0, 0).trimmed();
            QString faixa = bloco.section(":", 1, 1).trimmed();

            QString diaAbrev = dia.left(3).toLower();
            diaAbrev[0] = diaAbrev[0].toUpper();

            int horaIni = bloco.section(":", 1).section("-", 0, 0).remove("h").toInt();
            int horaFim = bloco.section(":", 1).section("-", 1, 1).remove("h").toInt();

            for (int h = horaIni; h < horaFim; ++h) {
                int linha = horarioParaLinha(QString::number(h) + "h");
                int coluna = diaParaColuna(diaAbrev);

                if (linha >= 0 && coluna >= 0) {
                    QTableWidgetItem* item = new QTableWidgetItem(nome);
                    if (!mapaCores.contains(nome))
                        mapaCores[nome] = coresDisponiveis[mapaCores.size() % coresDisponiveis.size()];

                    item->setBackground(mapaCores[nome]);
                    item->setTextAlignment(Qt::AlignCenter);
                    ui->tableWidgetQuadroHor->setItem(linha, coluna, item);
                }
            }
        }
    }

    // Preencher com atividades extras já lidas
    carregarAtividadesExtras();
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

void QuadroDeHorarios::carregarAtividadesExtras()
{
    for (const QString& linha : aluno->atividadesExtras) {
        QString nome = linha.section(";", 0, 0).trimmed();
        QString horarios = linha.section(";", 1).trimmed();

        QStringList blocos = horarios.split(",", Qt::SkipEmptyParts);
        for (QString bloco : blocos) {
            QString dia = bloco.section(":", 0, 0).trimmed();
            QString faixa = bloco.section(":", 1, 1).trimmed();

            QString diaAbrev = dia.left(3).toLower();
            diaAbrev[0] = diaAbrev[0].toUpper();

            int horaIni = bloco.section("-", 0, 0).remove("h").toInt();
            int horaFim = bloco.section("-", 1, 1).remove("h").toInt();

            for (int h = horaIni; h < horaFim; ++h) {
                int linha = horarioParaLinha(QString::number(h) + "h");
                int coluna = diaParaColuna(diaAbrev);

                if (linha >= 0 && coluna >= 0) {
                    QTableWidgetItem* item = new QTableWidgetItem(nome);
                    if (!mapaCores.contains(nome))
                        mapaCores[nome] = coresDisponiveis[mapaCores.size() % coresDisponiveis.size()];

                    item->setBackground(mapaCores[nome]);
                    item->setTextAlignment(Qt::AlignCenter);
                    ui->tableWidgetQuadroHor->setItem(linha, coluna, item);
                }
            }
        }
    }
}

void QuadroDeHorarios::salvarAtividadesExtras()
{
    QStringList novasAtividades;

    for (int linha = 0; linha < ui->tableWidgetQuadroHor->rowCount(); ++linha) {
        for (int col = 0; col < ui->tableWidgetQuadroHor->columnCount(); ++col) {
            QTableWidgetItem* item = ui->tableWidgetQuadroHor->item(linha, col);
            if (!item || item->text().isEmpty()) continue;

            QString nome = item->text().trimmed();
            bool ehDisciplina = std::any_of(aluno->disciplinasEmCurso.begin(), aluno->disciplinasEmCurso.end(),
                                            [&nome](const CDisciplinas& d) {
                                                return QString::fromStdString(d.nome).trimmed() == nome;
                                            });

            if (ehDisciplina) continue;

            QString hora = QString::number(6 + linha) + "h";

            QString dia;
            switch (col) {
            case 0: dia = "Segunda"; break;
            case 1: dia = "Terca"; break;
            case 2: dia = "Quarta"; break;
            case 3: dia = "Quinta"; break;
            case 4: dia = "Sexta"; break;
            case 5: dia = "Sabado"; break;
            case 6: dia = "Domingo"; break;
            }

            QString chave = nome;
            QString linhaNova = QString("%1 ; %2:%3-%4")
                                    .arg(nome).arg(dia).arg(hora).arg(QString::number(6 + linha + 1) + "h");

            novasAtividades.append(linhaNova);
        }
    }


    aluno->atividadesExtras.clear();
    for (const QString& linha : novasAtividades)
        aluno->atividadesExtras.push_back(linha);



}
