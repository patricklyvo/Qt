#include "pong.h"
#include "settings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Settings config;
    config.show();

    return a.exec();
}
