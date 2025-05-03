#ifndef ACOMPANHAMENTODISCIPLINA_H
#define ACOMPANHAMENTODISCIPLINA_H

#include <QMainWindow>

namespace Ui {
class AcompanhamentoDisciplina;
}

class AcompanhamentoDisciplina : public QMainWindow
{
    Q_OBJECT

public:
    explicit AcompanhamentoDisciplina(const QString& nomeDisciplina, QWidget *parent = nullptr);
    ~AcompanhamentoDisciplina();

private:
    Ui::AcompanhamentoDisciplina *ui;
};

#endif
