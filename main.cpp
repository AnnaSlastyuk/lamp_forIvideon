//==================================================
// Lamp - test task for Ivideon
// Anna Slastyuk
// 09.09.14
//==================================================

#include "lamp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TLamp w;
    w.show();

    return a.exec();
}
