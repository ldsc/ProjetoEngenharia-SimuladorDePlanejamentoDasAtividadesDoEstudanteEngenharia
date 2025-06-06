#ifndef QUADRODEHORARIOS_H
#define QUADRODEHORARIOS_H

#include <QMainWindow>

namespace Ui {
class QuadroDeHorarios;
}

class QuadroDeHorarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuadroDeHorarios(QWidget *parent = nullptr);
    ~QuadroDeHorarios();

private:
    Ui::QuadroDeHorarios *ui;
};

#endif // QUADRODEHORARIOS_H
