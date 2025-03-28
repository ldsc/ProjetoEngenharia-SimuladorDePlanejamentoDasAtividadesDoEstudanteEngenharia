#include "modulogradecompleta.h"
#include "ui_modulogradecompleta.h"
#include "CDisciplinas.h"
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>

ModuloGradeCompleta::ModuloGradeCompleta(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModuloGradeCompleta)
{
    ui->setupUi(this);

    // Criar o layout de grade
    QWidget *centralWidget = new QWidget(this);
    gridLayout = new QGridLayout(centralWidget);
    centralWidget->setLayout(gridLayout);
    setCentralWidget(centralWidget);

    // Carregar disciplinas
    carregarDisciplinas();
}

ModuloGradeCompleta::~ModuloGradeCompleta()
{
    delete ui;
}

void ModuloGradeCompleta::carregarDisciplinas()
{
    std::vector<CDisciplinas> disciplinas = getDisciplinasCurso();

    std::map<int, int> linhaPorPeriodo;  // Guarda a linha de cada período no grid

    for (const auto& disciplina : disciplinas) {
        int periodo = disciplina.periodo;

        // Se o período ainda não foi registrado, adicione uma nova linha no grid
        if (linhaPorPeriodo.find(periodo) == linhaPorPeriodo.end()) {
            linhaPorPeriodo[periodo] = linhaPorPeriodo.size();
        }

        int row = linhaPorPeriodo[periodo];
        int col = gridLayout->columnCount(); // Adiciona ao final da linha

        // Criar um quadrado (QFrame) para representar a disciplina
        QFrame *disciplinaFrame = new QFrame(this);
        disciplinaFrame->setFrameShape(QFrame::Box);
        disciplinaFrame->setFrameShadow(QFrame::Raised);
        disciplinaFrame->setStyleSheet("background-color: #f0f0f0; padding: 10px;");
        disciplinaFrame->setFixedSize(200, 100);

        // Criar um layout dentro do quadrado
        QVBoxLayout *frameLayout = new QVBoxLayout(disciplinaFrame);

        // Criar um label com o nome da disciplina
        QLabel *nomeDisciplina = new QLabel(QString::fromStdString(disciplina.nome), disciplinaFrame);
        nomeDisciplina->setAlignment(Qt::AlignCenter);
        nomeDisciplina->setStyleSheet("font-weight: bold;");

        // Adicionar ao layout do quadrado
        frameLayout->addWidget(nomeDisciplina);
        disciplinaFrame->setLayout(frameLayout);

        // Adicionar ao grid layout
        gridLayout->addWidget(disciplinaFrame, row, col);
    }
}
