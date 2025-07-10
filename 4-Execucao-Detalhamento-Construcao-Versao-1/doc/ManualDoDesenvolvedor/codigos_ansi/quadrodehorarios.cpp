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
    , aluno(aluno)                  {
    ui->setupUi(this);

    connect(ui->botaoEditar, &QPushButton::clicked, this, &QuadroDeHorarios::aoClicarEditar);
    connect(ui->botaoSalvar, &QPushButton::clicked, this, &QuadroDeHorarios::aoClicarSalvar);
    connect(ui->tableWidgetQuadroHor, &QTableWidget::cellClicked, this, &QuadroDeHorarios::aoClicarSimplesCelula);
    connect(ui->botaoExcluir, &QPushButton::clicked, this, &QuadroDeHorarios::aoClicarExcluir);
    connect(ui->botaoBaixar, &QPushButton::clicked, this, &QuadroDeHorarios::salvarQuadroComoImagem);

    ui->botaoBaixar->setStyleSheet("background-color: #ffa308; color: white; border-radius: 30px;");




    coresDisponiveis = {
        QColor("#F44336"), QColor("#2196F3"), QColor("#4CAF50"), QColor("#FF9800"),
        QColor("#9C27B0"), QColor("#009688"), QColor("#FFEB3B"), QColor("#3F51B5"),
        QColor("#CDDC39"), QColor("#E91E63"), QColor("#00BCD4"), QColor("#795548")
    };

    definirModoEdicao(false);
    preencherQuadro();



    // Mostrar aviso com disciplinas e atividades
    //QString aviso = "Disciplinas em curso detectadas:\n";
    //for (const auto& d : aluno->disciplinasEmCurso)
    //    aviso += "- " + QString::fromStdString(d.nome) + "\n";

    //aviso += "\nAtividades extras detectadas:\n";
    //for (const auto& a : aluno->atividadesExtras)
    //    aviso += "- " + a + "\n";

    //QMessageBox::information(this, "Resumo Inicial", aviso);

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
    ui->botaoExcluir->setStyleSheet(ativo ? "background-color: #ffa308; color: white; border-radius: 10px;" : "background-color: #a6a6a6; color: white; border-radius: 10px;");


    ui->botaoEditar->setEnabled(!ativo);
    ui->botaoSalvar->setEnabled(ativo);
    ui->botaoExcluir->setEnabled(ativo);
}

void QuadroDeHorarios::aoClicarEditar() {
    definirModoEdicao(true);
}

void QuadroDeHorarios::aoClicarSalvar() {
    definirModoEdicao(false);

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

    QStringList nomesDisciplinasEmCurso;
    for (const CDisciplinas& d : aluno->disciplinasEmCurso)
        nomesDisciplinasEmCurso << QString::fromStdString(d.nome).trimmed();

    for (CDisciplinas& disc : aluno->disciplinasEmCurso) {
        QString nome = QString::fromStdString(disc.nome).trimmed();

        if (horariosPorDisciplina.contains(nome)) {
            QStringList blocosOriginais = horariosPorDisciplina[nome];
            QMap<QString, QList<QPair<int, int>>> blocosPorDia;

            for (const QString& bloco : blocosOriginais) {
                QString dia = bloco.section(":", 0, 0).trimmed();
                QString faixa = bloco.section(":", 1).trimmed();
                int ini = faixa.section("-", 0, 0).remove("h").toInt();
                int fim = faixa.section("-", 1, 1).remove("h").toInt();
                blocosPorDia[dia].append(qMakePair(ini, fim));
            }

            QStringList blocosUnidos;
            for (auto it = blocosPorDia.begin(); it != blocosPorDia.end(); ++it) {
                QString dia = it.key();
                QList<QPair<int, int>> lista = it.value();
                std::sort(lista.begin(), lista.end());

                int ini = lista[0].first;
                int fim = lista[0].second;
                for (int i = 1; i < lista.size(); ++i) {
                    if (lista[i].first == fim) {
                        fim = lista[i].second;
                    } else {
                        blocosUnidos << QString("%1:%2h-%3h").arg(dia).arg(ini).arg(fim);
                        ini = lista[i].first;
                        fim = lista[i].second;
                    }
                }
                blocosUnidos << QString("%1:%2h-%3h").arg(dia).arg(ini).arg(fim);
            }

            disc.diasHorarios = blocosUnidos.join(",");
        } else {
            // Essa disciplina foi removida completamente do quadro -> atualizar como "vazia"
            disc.diasHorarios = "InserirDiaDeAula,InserirHorariosDaAula";
        }
    }


    // Processa atividades extras
    QStringList novasAtividadesExtras;
    for (auto it = horariosPorDisciplina.begin(); it != horariosPorDisciplina.end(); ++it) {
        QString nome = it.key().trimmed();
        if (nomesDisciplinasEmCurso.contains(nome)) continue;

        QStringList blocosOriginais = it.value();
        QMap<QString, QList<QPair<int, int>>> blocosPorDia;

        for (const QString& bloco : blocosOriginais) {
            QString dia = bloco.section(":", 0, 0).trimmed();
            QString faixa = bloco.section(":", 1).trimmed();
            int ini = faixa.section("-", 0, 0).remove("h").toInt();
            int fim = faixa.section("-", 1, 1).remove("h").toInt();
            blocosPorDia[dia].append(qMakePair(ini, fim));
        }

        QStringList blocosUnidos;
        for (auto diaIt = blocosPorDia.begin(); diaIt != blocosPorDia.end(); ++diaIt) {
            QString dia = diaIt.key();
            QList<QPair<int, int>> lista = diaIt.value();
            std::sort(lista.begin(), lista.end());

            int ini = lista[0].first;
            int fim = lista[0].second;
            for (int i = 1; i < lista.size(); ++i) {
                if (lista[i].first == fim) {
                    fim = lista[i].second;
                } else {
                    blocosUnidos << QString("%1:%2h-%3h").arg(dia).arg(ini).arg(fim);
                    ini = lista[i].first;
                    fim = lista[i].second;
                }
            }
            blocosUnidos << QString("%1:%2h-%3h").arg(dia).arg(ini).arg(fim);
        }

        novasAtividadesExtras << QString("%1 ; %2").arg(nome).arg(blocosUnidos.join(", "));
    }
    aluno->atividadesExtras = std::vector<QString>(novasAtividadesExtras.begin(), novasAtividadesExtras.end());


    // Atualiza o arquivo
    QFile file("InformacoesAluno.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QStringList novasLinhas;
    QTextStream in(&file);
    bool dentroAtividades = false;
    bool encontrouCabecalhoExtras = false;

    while (!in.atEnd()) {
        QString linha = in.readLine();
        QString nomeNaLinha = linha.section(";", 0, 0).trimmed();

        // Atualiza disciplina
        bool atualizou = false;
        for (const CDisciplinas& disc : aluno->disciplinasEmCurso) {
            QString nome = QString::fromStdString(disc.nome).trimmed();
            QString nomeLinhaLimpo = nomeNaLinha.trimmed();

            if (nome == nomeLinhaLimpo) {
                QStringList partes = linha.split(";");
                while (partes.size() < 5)
                    partes << ""; // garante número mínimo de campos

                partes[2] = " " + disc.diasHorarios;
                QString novaLinha = partes.join(";");
                novasLinhas << novaLinha;
                atualizou = true;
                break;
            }
        }


        if (!atualizou) {
            if (linha.startsWith("# Formato: Nome da Atividade")) {
                encontrouCabecalhoExtras = true;
                dentroAtividades = true;
                novasLinhas << "# Formato: Nome da Atividade ; Dias e Horários";
                novasLinhas << "# Exemplo: Estudo Individual ; Terça:14h-16h, Quinta:14h-16h";
                for (const QString& atv : aluno->atividadesExtras)
                    novasLinhas << atv;
                continue;
            }

            if (dentroAtividades) {
                if (linha.startsWith("#") || linha.trimmed().isEmpty())
                    continue;
            } else {
                novasLinhas << linha;
            }
        }
    }
    file.close();

    if (!encontrouCabecalhoExtras) {
        novasLinhas << "";
        novasLinhas << "# Formato: Nome da Atividade ; Dias e Horários";
        novasLinhas << "# Exemplo: Estudo Individual ; Terça:14h-16h, Quinta:14h-16h";
        for (const QString& atv : aluno->atividadesExtras)
            novasLinhas << atv;
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const QString& linha : novasLinhas)
            out << linha.trimmed() << "\n";
        file.close();
    }
}




void QuadroDeHorarios::preencherQuadro() {
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

           bool okIni = false, okFim = false;
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
                QInputDialog inputDialog(this);
                inputDialog.setWindowTitle("Nova Atividade");
                inputDialog.setLabelText("Digite o nome da atividade:");
                inputDialog.setStyleSheet(R"(
    QInputDialog {
        background-color: white;
        color: black;
    }

    QLabel, QLineEdit {
        color: black;
        background-color: white;
    }

    QPushButton {
        background-color: #ffa308;
        color: white;
        border-radius: 5px;
        padding: 5px;
    }

    QPushButton:hover {
        background-color: #e69500;
    }
)");

                QString novaAtividade;

                if (inputDialog.exec() == QDialog::Accepted) {
                    novaAtividade = inputDialog.textValue().trimmed();
                    if (!novaAtividade.isEmpty()) {
                        nomeSelecionado = novaAtividade;
                    } else {
                        ui->tableWidgetQuadroHor->removeCellWidget(row, column);
                        return;
                    }
                } else {
                    ui->tableWidgetQuadroHor->removeCellWidget(row, column);
                    return;
                }

                if (!novaAtividade.trimmed().isEmpty()) {
                    nomeSelecionado = novaAtividade.trimmed();
                } else {
                    ui->tableWidgetQuadroHor->removeCellWidget(row, column);
                    return;
                }


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

}


void QuadroDeHorarios::aoClicarExcluir()
{
    if (!modoEdicaoAtivo) return;

    int row = ui->tableWidgetQuadroHor->currentRow();
    int col = ui->tableWidgetQuadroHor->currentColumn();

    if (row < 0 || col < 0) {
        QMessageBox::warning(this, "Aviso", "Selecione uma célula com conteúdo para excluir.");
        return;
    }

    QTableWidgetItem* item = ui->tableWidgetQuadroHor->item(row, col);
    if (!item || item->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Aviso", "A célula selecionada está vazia.");
        return;
    }

    QString nome = item->text().trimmed();

    // Remover o item visualmente
    ui->tableWidgetQuadroHor->removeCellWidget(row, col);
    delete ui->tableWidgetQuadroHor->takeItem(row, col);

    QString horaInicio = QString::number(6 + row) + "h";
    QString horaFim = QString::number(6 + row + 1) + "h";

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

    QString horarioExcluir = QString("%1:%2-%3").arg(dia).arg(horaInicio).arg(horaFim);

    bool ehDisciplina = std::any_of(aluno->disciplinasEmCurso.begin(), aluno->disciplinasEmCurso.end(),
                                    [&nome](const CDisciplinas& d) {
                                        return QString::fromStdString(d.nome).trimmed() == nome;
                                    });

    if (ehDisciplina) {
        for (CDisciplinas& d : aluno->disciplinasEmCurso) {
            if (QString::fromStdString(d.nome).trimmed() == nome) {
                QStringList blocos = d.diasHorarios.split(",", Qt::SkipEmptyParts);
                blocos.removeAll(horarioExcluir);
                d.diasHorarios = blocos.isEmpty() ? "InserirDiaDeAula,InserirHorariosDaAula" : blocos.join(",");
                break;
            }
        }
    } else {
        for (int i = 0; i < aluno->atividadesExtras.size(); ++i) {
            QString linha = aluno->atividadesExtras[i];
            QString nomeLinha = linha.section(";", 0, 0).trimmed();
            QString horarios = linha.section(";", 1).trimmed();
            if (nomeLinha == nome) {
                QStringList blocos = horarios.split(",", Qt::SkipEmptyParts);
                blocos.removeAll(horarioExcluir);
                if (blocos.isEmpty()) {
                    aluno->atividadesExtras[i] = nome + " ; InserirDiaDeAula,InserirHorariosDaAula";
                } else {
                    aluno->atividadesExtras[i] = nome + " ; " + blocos.join(", ");
                }
                break;
            }
        }
    }

}




void QuadroDeHorarios::salvarQuadroComoImagem() {
    QTableWidget* tabela = ui->tableWidgetQuadroHor;

    int larguraTotal = tabela->verticalHeader()->width();
    for (int col = 0; col < tabela->columnCount(); ++col)
        larguraTotal += tabela->columnWidth(col);

    int alturaTotal = tabela->horizontalHeader()->height();
    for (int row = 0; row < tabela->rowCount(); ++row)
        alturaTotal += tabela->rowHeight(row);

    QPixmap imagem(larguraTotal, alturaTotal);
    imagem.fill(Qt::white);
    tabela->render(&imagem, QPoint(0, 0));

    QString nomeArquivo = "Quadro de Horários.png";
    int contador = 1;
    while (QFile::exists(nomeArquivo)) {
        nomeArquivo = QString("Quadro de Horários_%1.png").arg(contador++);
    }

    if (imagem.save(nomeArquivo)) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Sucesso");
        msgBox.setText("Imagem salva como " + nomeArquivo);
        msgBox.setStyleSheet(R"(
            QMessageBox {
                background-color: white;
                color: black;
            }

            QLabel {
                color: black;
                background-color: white;
            }

            QPushButton {
                background-color: #ffa308;
                color: white;
                border-radius: 5px;
                padding: 5px;
            }

            QPushButton:hover {
                background-color: #e69500;
            }
        )");
        msgBox.exec();
    } else {
        QMessageBox::warning(this, "Erro", "Falha ao salvar a imagem.");
    }
}



