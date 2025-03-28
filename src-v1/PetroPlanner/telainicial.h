#ifndef TELAINICIAL_H
#define TELAINICIAL_H

#include <QMainWindow>
#include "modulogradecompleta.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TelaInicial;
}
QT_END_NAMESPACE

class TelaInicial : public QMainWindow
{
    Q_OBJECT

public:
    TelaInicial(QWidget *parent = nullptr);
    ~TelaInicial();

private slots:
    void on_botaoVerGradeCompleta_clicked();

private:
    Ui::TelaInicial *ui;
    ModuloGradeCompleta *gradeCompleta; // Ponteiro para a janela
};

#endif
