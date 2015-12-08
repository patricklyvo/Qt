#ifndef PONG_H
#define PONG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "ball.h"
#include "paddle.h"

#define WIDTH 600
#define HEIGHT (WIDTH / 2)
#define PADDLE_WIDTH (WIDTH * 0.025)
#define PADDLE_HEIGHT (HEIGHT / 4)

namespace Ui {
class Pong;
}

class Pong : public QDialog
{
    Q_OBJECT

public:
    //explicit Pong(QWidget *parent = 0);
    Pong(QWidget *parent = 0, int players = 1, int balls = 1);
    ~Pong();

private:
    Ui::Pong *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    int players;
};

#endif // PONG_H
