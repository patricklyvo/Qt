#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtWidgets>
#include "math.h"

#define WIDTH 600
#define HEIGHT (WIDTH / 2)

class Ball : public QGraphicsItem
{
public:
    Ball(int speed);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getDiameter();
    double getDx();
    void setDx(double dx);
    double getDy();
    void setDy(double dy);
protected:
    void advance(int phase);

private:
    int diameter;
    double speed;
    double dx;
    double dy;
};

#endif // BALL_H
