#include "mainwindow.h"
#include <QApplication>
#include "gamelayout.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(QTime::currentTime().msecsSinceStartOfDay());
    GameLayout w;
    w.show();

    return a.exec();
}
