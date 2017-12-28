#include "machintype.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MachinType w;
    w.show();

    return a.exec();
}
