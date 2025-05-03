#include "acompanhamentoDisciplina.h"
#include "ui_acompanhamentoDisciplina.h"

AcompanhamentoDisciplina::AcompanhamentoDisciplina(const QString& nomeDisciplina, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AcompanhamentoDisciplina)
{
    ui->setupUi(this);
    ui->label_NomeDisc->setText(nomeDisciplina);
}

AcompanhamentoDisciplina::~AcompanhamentoDisciplina()
{
    delete ui;
}
