#include "pong.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pong game;
    game.show();

    return a.exec();
}
