#include "quadrodehorarios.h"
#include "ui_quadrodehorarios.h"

QuadroDeHorarios::QuadroDeHorarios(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuadroDeHorarios)
{
    ui->setupUi(this);
}

QuadroDeHorarios::~QuadroDeHorarios()
{
    delete ui;
}
