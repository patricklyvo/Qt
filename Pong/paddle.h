#ifndef PADDLE_H
#define PADDLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "math.h"
#include "pong.h"

class Paddle : public QGraphicsItem
{
public:
    Paddle(int playerNum);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    double speed;
};

#endif // PADDLE_H
