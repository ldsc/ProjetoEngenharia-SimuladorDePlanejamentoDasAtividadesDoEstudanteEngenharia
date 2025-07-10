#include "telainicial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int returnCode;

    do {
        QApplication a(argc, argv);
        TelaInicial w;
        w.show();
        returnCode = a.exec();
    } while (returnCode == 42);  // 42 = código de reinício

    return returnCode;
}
