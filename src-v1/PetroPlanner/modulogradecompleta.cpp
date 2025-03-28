#include "modulogradecompleta.h"
#include "ui_modulogradecompleta.h"

ModuloGradeCompleta::ModuloGradeCompleta(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModuloGradeCompleta)
{
    ui->setupUi(this);
}

ModuloGradeCompleta::~ModuloGradeCompleta()
{
    delete ui;
}
