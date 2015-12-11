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
    explicit Ball(int speed = 5);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getDiameter();
    double getDx() const;
    void setDx(double dx);
    double getDy() const;
    void setDy(double dy);
protected:
    void advance(int phase);

private:
    int diameter;
    double dx;
    double dy;
    int hits;
};

#endif // BALL_H
