/****************************************************************************
**
** This file was written by Patrick Ly-Vo.
**
****************************************************************************/

#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
