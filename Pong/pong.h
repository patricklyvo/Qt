#ifndef PONG_H
#define PONG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

namespace Ui {
class Pong;
}

class Pong : public QDialog
{
    Q_OBJECT

public:
    explicit Pong(QWidget *parent = 0);
    ~Pong();

private:
    Ui::Pong *ui;
    QGraphicsScene *scene;
    QTimer *timer;
};

#endif // PONG_H