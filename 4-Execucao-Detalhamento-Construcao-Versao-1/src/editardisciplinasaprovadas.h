#ifndef EDITARDISCIPLINASAPROVADAS_H
#define EDITARDISCIPLINASAPROVADAS_H

#include <QDialog>
#include "CAluno.h"

namespace Ui {
class editardisciplinasaprovadas;
}

class EditarDisciplinasAprovadas : public QDialog
{
    Q_OBJECT

public:
    explicit EditarDisciplinasAprovadas(CAluno* aluno, QWidget *parent = nullptr);
    ~EditarDisciplinasAprovadas();

private:
    Ui::editardisciplinasaprovadas *ui;
    CAluno* aluno;
};

#endif
