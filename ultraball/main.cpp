#include <QApplication>
#include "gamelayout.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameLayout w;
    w.show();

    return a.exec();
}
