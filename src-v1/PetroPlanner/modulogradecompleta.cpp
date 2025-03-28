#include "modulogradecompleta.h"
#include "ui_modulogradecompleta.h"
#include "CDisciplinas.h"  // Incluindo a classe CDisciplinas
#include <QPushButton>     // Para criar botões ou etiquetas para as disciplinas
#include <QGridLayout>     // Para usar o QGridLayout
#include <QString>         // Para conversão de string para Qstring

ModuloGradeCompleta::ModuloGradeCompleta(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModuloGradeCompleta)
{
    ui->setupUi(this);
    carregarDisciplinas();
}

ModuloGradeCompleta::~ModuloGradeCompleta()
{
    delete ui;
}

void ModuloGradeCompleta::carregarDisciplinas() {
    // Pegue as disciplinas do curso
    std::vector<CDisciplinas> disciplinas = getDisciplinasCurso();

    // Crie um layout de grade (grid layout)
    QGridLayout *layout = new QGridLayout();   // Define o layout

    // Inicialize o número da linha como 0
    int row = 0;

    // Adicionar 10 linhas, uma para cada período
    for (int periodo = 1; periodo <= 10; ++periodo) {
        int column = 0; // Iniciar sempre na primeira coluna para cada período

        // Iterar sobre as disciplinas para aquele período específico
        for (const auto& disciplina : disciplinas) {
            if (disciplina.periodo == periodo) {
                // Criar um botão para cada disciplina (pode ser uma QLabel, QPushButton, etc)
                QPushButton *botaoDisciplina = new QPushButton(QString::fromStdString(disciplina.nome));

                // Adicionar a disciplina no layout na linha correspondente ao período
                layout->addWidget(botaoDisciplina, row, column);

                column++;  // Avançar para a próxima coluna

                // Limitar a quantidade de disciplinas por linha (pode ajustar esse valor)
                if (column > 4) {
                    column = 0;  // Voltar à primeira coluna
                    row++;  // Avançar para a próxima linha
                }
            }
        }

        row++;  // Avançar para a próxima linha para o próximo período
    }

    // Defina o layout no widget principal
    QWidget *centralWidget = new QWidget(this);  // Crie um widget central
    centralWidget->setLayout(layout);  // Defina o layout nele
    setCentralWidget(centralWidget);  // Defina o widget como o central
}
