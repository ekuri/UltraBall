#include <QApplication>
#include "gamelayout.h"
#include "debugwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameLayout w;
    w.show();
    DebugWindow debugWindow;
    debugWindow.show();

    return a.exec();
}
