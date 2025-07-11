#ifndef EDITARDISCIPLINASAPROVADAS_H
#define EDITARDISCIPLINASAPROVADAS_H

#include <QDialog>
#include <QMap>
#include <QCheckBox>
#include "CAluno.h"

namespace Ui {
class EditarDisciplinasAprovadas;
}

class EditarDisciplinasAprovadas : public QDialog
{
    Q_OBJECT

public:
    explicit EditarDisciplinasAprovadas(CAluno* aluno, QWidget *parent = nullptr);
    ~EditarDisciplinasAprovadas();

private slots:
    void on_buttonBox_accepted(); // OK
    void on_buttonBox_rejected(); // Cancelar

private:
    Ui::EditarDisciplinasAprovadas *ui;
    CAluno* aluno;
    QMap<QString, QCheckBox*> checkboxes;
};

#endif // EDITARDISCIPLINASAPROVADAS_H
