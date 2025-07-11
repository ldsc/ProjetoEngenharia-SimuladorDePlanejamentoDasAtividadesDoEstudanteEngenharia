#include "editardisciplinasaprovadas.h"
#include "ui_editardisciplinasaprovadas.h"
#include "CAluno.h"

EditarDisciplinasAprovadas::EditarDisciplinasAprovadas(CAluno* aluno, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::editardisciplinasaprovadas),
    aluno(aluno)
{
    ui->setupUi(this);
}


EditarDisciplinasAprovadas::~EditarDisciplinasAprovadas()
{
    delete ui;
}


