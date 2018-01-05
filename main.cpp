#include "machintype.h"
#include <QApplication>

QString getQssContent()
{
    qDebug() << __FUNCTION__;
    QFile styleSheet(":/resource.qss");
    if (!styleSheet.open(QIODevice::ReadOnly))
    {
        return "";
    }
    return styleSheet.readAll();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MachinType w;
    w.show();

    a.setStyleSheet(getQssContent());
    return a.exec();
}
