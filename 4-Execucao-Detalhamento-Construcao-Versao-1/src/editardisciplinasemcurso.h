#ifndef EDITARDISCIPLINASEMCURSO_H
#define EDITARDISCIPLINASEMCURSO_H

#include <QDialog>
#include <QMap>
#include <QCheckBox>
#include "CAluno.h"

namespace Ui {
class editardisciplinasaprovadas;
}

class EditarDisciplinasEmCurso : public QDialog
{
    Q_OBJECT

public:
    explicit EditarDisciplinasEmCurso(CAluno* aluno, QWidget *parent = nullptr);
    ~EditarDisciplinasEmCurso();

private slots:
    void on_buttonBox_accepted(); // Para OK
    void on_buttonBox_rejected(); // Para Cancel

private:
    Ui::editardisciplinasaprovadas *ui;
    CAluno* aluno;
    QMap<QString, QCheckBox*> checkboxes;
};

#endif
