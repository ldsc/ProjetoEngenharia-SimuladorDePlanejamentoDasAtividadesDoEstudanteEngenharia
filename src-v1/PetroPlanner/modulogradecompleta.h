#ifndef MODULOGRADECOMPLETA_H
#define MODULOGRADECOMPLETA_H

#include <QMainWindow>
#include <QGridLayout>
#include "CDisciplinas.h"

namespace Ui {
class ModuloGradeCompleta;
}

class ModuloGradeCompleta : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModuloGradeCompleta(QWidget *parent = nullptr);
    ~ModuloGradeCompleta();

private:
    Ui::ModuloGradeCompleta *ui;
    QGridLayout *gridLayout;
    void carregarDisciplinas();  // Método para popular o layout
};

#endif
