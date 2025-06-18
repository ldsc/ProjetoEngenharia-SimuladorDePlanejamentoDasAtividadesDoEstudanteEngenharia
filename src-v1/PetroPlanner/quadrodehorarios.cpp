#include "quadrodehorarios.h"
#include "ui_quadrodehorarios.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QComboBox>



QuadroDeHorarios::QuadroDeHorarios(CAluno* aluno, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuadroDeHorarios)
    , aluno(aluno)
{
    ui->setupUi(this);

    connect(ui->botaoEditar, &QPushButton::clicked, this, &QuadroDeHorarios::aoClicarEditar);
    connect(ui->botaoSalvar, &QPushButton::clicked, this, &QuadroDeHorarios::aoClicarSalvar);
    connect(ui->tableWidgetQuadroHor, &QTableWidget::cellClicked, this, &QuadroDeHorarios::aoClicarSimplesCelula);



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

    // === Atualiza os horários no objeto CAluno ===
    QMap<QString, QStringList> horariosPorDisciplina;

    for (int linha = 0; linha < ui->tableWidgetQuadroHor->rowCount(); ++linha) {
        for (int coluna = 0; coluna < ui->tableWidgetQuadroHor->columnCount(); ++coluna) {
            QTableWidgetItem* item = ui->tableWidgetQuadroHor->item(linha, coluna);
            if (!item || item->text().isEmpty()) continue;

            QString nome = item->text().trimmed();
            QString horaInicio = QString::number(6 + linha) + "h";
            QString horaFim = QString::number(6 + linha + 1) + "h";

            QString dia;
            switch (coluna) {
            case 0: dia = "Segunda"; break;
            case 1: dia = "Terca"; break;
            case 2: dia = "Quarta"; break;
            case 3: dia = "Quinta"; break;
            case 4: dia = "Sexta"; break;
            case 5: dia = "Sabado"; break;
            case 6: dia = "Domingo"; break;
            }

            QString bloco = dia + ":" + horaInicio + "-" + horaFim;
            horariosPorDisciplina[nome].append(bloco);
        }
    }

    // === Atualiza os objetos disciplinasEmCurso com base no mapa atualizado ===
    for (CDisciplinas& disc : aluno->disciplinasEmCurso) {
        QString nome = QString::fromStdString(disc.nome).trimmed();
        if (horariosPorDisciplina.contains(nome)) {
            QStringList blocosOriginais = horariosPorDisciplina[nome];
            QMap<QString, QList<QPair<int, int>>> blocosPorDia;

            // Agrupar por dia
            for (const QString& bloco : blocosOriginais) {
                QString dia = bloco.section(":", 0, 0).trimmed();
                QString faixa = bloco.section(":", 1).trimmed();
                int ini = faixa.section("-", 0, 0).remove("h").toInt();
                int fim = faixa.section("-", 1, 1).remove("h").toInt();
                blocosPorDia[dia].append(qMakePair(ini, fim));
            }

            // Unir blocos consecutivos
            QStringList blocosUnidos;
            for (auto it = blocosPorDia.begin(); it != blocosPorDia.end(); ++it) {
                QString dia = it.key();
                QList<QPair<int, int>> lista = it.value();

                // Ordenar blocos por hora de início
                std::sort(lista.begin(), lista.end());

                int ini = lista[0].first;
                int fim = lista[0].second;

                for (int i = 1; i < lista.size(); ++i) {
                    if (lista[i].first == fim) {
                        fim = lista[i].second; // bloco contínuo, estende o final
                    } else {
                        blocosUnidos << QString("%1:%2h-%3h").arg(dia).arg(ini).arg(fim);
                        ini = lista[i].first;
                        fim = lista[i].second;
                    }
                }
                blocosUnidos << QString("%1:%2h-%3h").arg(dia).arg(ini).arg(fim);
            }

            disc.diasHorarios = blocosUnidos.join(",");

        }
    }

    // === Atualiza o arquivo InformacoesAluno.txt ===
    QFile file("InformacoesAluno.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QStringList novasLinhas;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linha = in.readLine();
        QString nomeNaLinha = linha.section(";", 0, 0).trimmed();

        bool atualizou = false;
        for (const CDisciplinas& disc : aluno->disciplinasEmCurso) {
            QString nome = QString::fromStdString(disc.nome).trimmed();
            if (nome == nomeNaLinha) {
                // Substitui apenas o campo "Dias e Horarios"
                QString novaLinha = linha;
                QStringList partes = linha.split(";");
                if (partes.size() >= 5) {
                    partes[2] = " " + disc.diasHorarios; // atualiza o campo diasHorarios
                    novaLinha = partes.join(";");
                }
                novasLinhas << novaLinha;
                atualizou = true;
                break;
            }
        }

        if (!atualizou)
            novasLinhas << linha;
    }
    file.close();

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const QString& linha : novasLinhas)
            out << linha.trimmed() << "\n";
        file.close();
    }

    // Agora salva as atividades extras
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
            QString faixa = bloco.section(":", 1).trimmed();  // pega tudo após o :

            if (!faixa.contains("-"))
                continue;

            QString horaIniStr = faixa.section("-", 0, 0).remove("h").trimmed();
            QString horaFimStr = faixa.section("-", 1, 1).remove("h").trimmed();

            bool okIni, okFim;
            int horaIni = horaIniStr.toInt(&okIni);
            int horaFim = horaFimStr.toInt(&okFim);

            if (!okIni || !okFim || horaIni >= horaFim)
                continue;

            QString diaAbrev = dia.left(3).toLower();
            diaAbrev[0] = diaAbrev[0].toUpper();

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


void QuadroDeHorarios::aoClicarSimplesCelula(int row, int column) {
    if (modoEdicaoAtivo && !ui->tableWidgetQuadroHor->item(row, column)) {
        // Cria o combo box
        QComboBox* combo = new QComboBox(ui->tableWidgetQuadroHor);
        QStringList nomesDisciplinas;
        for (const CDisciplinas& d : aluno->disciplinasEmCurso) {
            nomesDisciplinas << QString::fromStdString(d.nome);
        }

        nomesDisciplinas << "Adicionar outra...";
        combo->addItems(nomesDisciplinas);
        combo->setEditable(false);
        combo->setFocusPolicy(Qt::StrongFocus);

        // Coloca o combo na célula
        ui->tableWidgetQuadroHor->setCellWidget(row, column, combo);

        // Conecta a seleção ao slot
        connect(combo, &QComboBox::activated, this, [=](int index) {
            QString nomeSelecionado = combo->itemText(index);

            // Se for "Adicionar outra...", abre input para digitar
            if (nomeSelecionado == "Adicionar outra...") {
                bool ok;
                QString novaAtividade = QInputDialog::getText(this, "Nova Atividade",
                                                              "Digite o nome da atividade:", QLineEdit::Normal,
                                                              "", &ok);
                if (ok && !novaAtividade.trimmed().isEmpty()) {
                    nomeSelecionado = novaAtividade.trimmed();
                } else {
                    // Cancelado: remove o combo e não faz nada
                    ui->tableWidgetQuadroHor->removeCellWidget(row, column);
                    return;
                }
            }

            aoSelecionarDisciplina(nomeSelecionado);

            // Remove o combobox e adiciona o item definitivo
            QTableWidgetItem* item = new QTableWidgetItem(nomeSelecionado);
            if (!mapaCores.contains(nomeSelecionado)) {
                mapaCores[nomeSelecionado] = coresDisponiveis[mapaCores.size() % coresDisponiveis.size()];
            }
            item->setBackground(mapaCores[nomeSelecionado]);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidgetQuadroHor->removeCellWidget(row, column);
            ui->tableWidgetQuadroHor->setItem(row, column, item);

            // Atualiza a disciplina com novo horário
            for (CDisciplinas& d : aluno->disciplinasEmCurso) {
                if (QString::fromStdString(d.nome) == nomeSelecionado) {
                    QString dia;
                    switch (column) {
                    case 0: dia = "Segunda"; break;
                    case 1: dia = "Terca"; break;
                    case 2: dia = "Quarta"; break;
                    case 3: dia = "Quinta"; break;
                    case 4: dia = "Sexta"; break;
                    case 5: dia = "Sabado"; break;
                    case 6: dia = "Domingo"; break;
                    }

                    QString horario = QString::number(6 + row) + "h-" + QString::number(6 + row + 1) + "h";
                    QString novoHorario = dia + ":" + horario;

                    if (!d.diasHorarios.contains(novoHorario)) {
                        if (!d.diasHorarios.isEmpty() && !d.diasHorarios.endsWith(","))
                            d.diasHorarios += ",";
                        d.diasHorarios += novoHorario;
                    }
                }
            }
        });

    }
}


void QuadroDeHorarios::aoSelecionarDisciplina(const QString&) {
    // Implementação vazia para evitar erro de linker
}

