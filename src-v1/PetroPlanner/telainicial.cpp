#include "telainicial.h"
#include "ui_telainicial.h"

TelaInicial::TelaInicial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaInicial)
    , gradeCompleta(nullptr) // Inicializa o ponteiro como nullptr
{
    ui->setupUi(this);
}

TelaInicial::~TelaInicial()
{
    delete ui;
    if (gradeCompleta) {
        delete gradeCompleta; // Libera memória caso tenha sido criada
    }
}

void TelaInicial::on_botaoVerGradeCompleta_clicked()
{
    if (!gradeCompleta) {
        gradeCompleta = new ModuloGradeCompleta(this); // Cria a janela se ainda não existir
    }
    gradeCompleta->show(); // Exibe a janela
}
