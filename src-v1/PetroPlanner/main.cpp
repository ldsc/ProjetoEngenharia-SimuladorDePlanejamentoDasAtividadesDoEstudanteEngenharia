#include "telainicial.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TelaInicial w;
    w.show();
    return a.exec();
}
