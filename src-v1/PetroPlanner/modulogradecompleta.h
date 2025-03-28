#ifndef MODULOGRADECOMPLETA_H
#define MODULOGRADECOMPLETA_H

#include <QMainWindow>

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
};

#endif // MODULOGRADECOMPLETA_H
