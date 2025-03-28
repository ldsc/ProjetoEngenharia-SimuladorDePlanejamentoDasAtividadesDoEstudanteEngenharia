#include "telainicial.h"
#include "./ui_telainicial.h"

TelaInicial::TelaInicial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaInicial)
{
    ui->setupUi(this);
}

TelaInicial::~TelaInicial()
{
    delete ui;
}

void TelaInicial::on_botaoVerGradeCompleta_clicked()
{

}

