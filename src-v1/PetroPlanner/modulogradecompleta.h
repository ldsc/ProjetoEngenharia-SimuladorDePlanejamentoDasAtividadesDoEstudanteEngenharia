#ifndef MODULOGRADECOMPLETA_H
#define MODULOGRADECOMPLETA_H

#include <QMainWindow>
#include <QGridLayout>
#include "CDisciplinas.h"
#include "CAluno.h"

namespace Ui {
class ModuloGradeCompleta;
}

class ModuloGradeCompleta : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModuloGradeCompleta(const CAluno& alunoRef, QWidget *parent = nullptr);
    ~ModuloGradeCompleta();

private:
    Ui::ModuloGradeCompleta *ui;
    QGridLayout *gridLayout;
    CAluno aluno;
    void carregarDisciplinas();
};

#endif
