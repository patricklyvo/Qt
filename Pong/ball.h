#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "math.h"
#include "pong.h"

class Ball : public QGraphicsItem
{
public:
    Ball();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    double speed;
    double dx;
    double dy;
    double angle;
    void doCollision();
};

#endif // BALL_H
