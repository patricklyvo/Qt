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
#define PADDLE_SPEED (HEIGHT * 0.05)

namespace Ui {
class Pong;
}

class Pong : public QDialog
{
    Q_OBJECT

public:
    //explicit Pong(QWidget *parent = 0);
    explicit Pong(QWidget *parent = 0, int players = 1, int balls = 1);
    ~Pong();

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::Pong *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    int players;
    int p1Score;
    int p2Score;

    QGraphicsTextItem *p1Text;
    QGraphicsTextItem *p2Text;

    QPointF *topCenter;
    QPointF *bottomCenter;

    QLineF *topLine;
    QLineF *leftLine;
    QLineF *rightLine;
    QLineF *bottomLine;
    QLineF *centerLine;

    Ball *ball;
    int speed;

    Paddle *p1;
    Paddle *p2;

    void reset();

public slots:
    void ballCollision();
};

#endif // PONG_H
