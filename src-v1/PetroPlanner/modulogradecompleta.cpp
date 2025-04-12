#include "modulogradecompleta.h"
#include "ui_modulogradecompleta.h"
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

ModuloGradeCompleta::ModuloGradeCompleta(const CAluno& alunoRef, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModuloGradeCompleta)
    , aluno(alunoRef)
{
    ui->setupUi(this);
    carregarDisciplinas();
}

ModuloGradeCompleta::~ModuloGradeCompleta()
{
    delete ui;
}

void ModuloGradeCompleta::carregarDisciplinas() {
    std::vector<CDisciplinas> todas = getDisciplinasCurso();
    QGridLayout *layout = new QGridLayout();
    int row = 0;

    for (int periodo = 1; periodo <= 10; ++periodo) {
        int column = 0;

        for (const auto& disc : todas) {
            if (disc.periodo != periodo)
                continue;

            QPushButton *botao = new QPushButton(QString::fromStdString(disc.nome));
            QString cor = "background-color: lightgray"; // padrão: não cursada

            // Verifica se está aprovada (no vetor do aluno)
            bool aprovada = std::any_of(
                aluno.disciplinasAprovadas.begin(), aluno.disciplinasAprovadas.end(),
                [&disc](const CDisciplinas& d) { return d.nome == disc.nome; }
                );

            if (aprovada) {
                cor = "background-color: lightgreen";
            } else {
                // Se não está no vetor, verificar no TXT
                QFile file("InformacoesAluno.txt");
                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        QString linha = in.readLine();
                        if (linha.startsWith("#") || linha.trimmed().isEmpty())
                            continue;

                        if (linha.contains(QString::fromStdString(disc.nome), Qt::CaseInsensitive)) {
                            QString ultimaSituacao;
                            QStringList partes = linha.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

                            // Procurar pela última situação relevante
                            for (int i = partes.size() - 1; i >= 0; --i) {
                                QString valor = partes[i];
                                if (valor == "Aprovada" || valor == "Reprovada") {
                                    ultimaSituacao = valor;
                                    break;
                                } else if (valor == "Curso" && i > 0 && partes[i - 1] == "Em") {
                                    ultimaSituacao = "Em Curso";
                                    break;
                                } else if (valor == "Cursada" && i > 0 && partes[i - 1] == "Nao") {
                                    ultimaSituacao = "Nao Cursada";
                                    break;
                                }
                            }

                            // Atribuir cor com base na última situação
                            if (ultimaSituacao == "Aprovada") {
                                cor = "background-color: lightgreen";
                            } else if (ultimaSituacao == "Reprovada") {
                                cor = "background-color: red";
                            } else if (ultimaSituacao == "Em Curso") {
                                cor = "background-color: yellow";
                            } else if (ultimaSituacao == "Nao Cursada") {
                                cor = "background-color: lightgray";
                            }

                            break;
                        }
                    }
                    file.close();
                }
            }

            botao->setStyleSheet(cor);
            layout->addWidget(botao, row, column++);

            if (column > 4) {
                column = 0;
                row++;
            }
        }

        row++;
    }

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}
