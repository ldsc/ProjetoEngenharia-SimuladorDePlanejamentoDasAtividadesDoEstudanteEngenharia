#ifndef QUADRODEHORARIOS_H
#define QUADRODEHORARIOS_H

#include <QMainWindow>
#include "caluno.h"

namespace Ui {
class QuadroDeHorarios;
}

class QuadroDeHorarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuadroDeHorarios(CAluno* aluno, QWidget *parent = nullptr);
    ~QuadroDeHorarios();

private:
    Ui::QuadroDeHorarios *ui;
    CAluno* aluno;

    void preencherQuadro();
    int horarioParaLinha(const QString& horario);
    int diaParaColuna(const QString& dia);
};

#endif
