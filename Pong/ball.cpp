#include "ball.h"

Ball::Ball(int speed)
{
    // number of times ball has been hit
    hits = 0;

    // diameter of ball
    diameter = 20;

    // random speed and direction
    switch(qrand() % 4) {
        case (0):
            dx = speed;
            dy = speed;
            break;
        case (1):
            dx = -speed;
            dy = speed;
            break;
        case (2):
            dx = speed;
            dy = -speed;
            break;
        case (3):
            dx = -speed;
            dy = -speed;
            break;
    }

    // start from center
    int startX = WIDTH / 2;
    int startY = HEIGHT / 2;

    setPos(mapToParent(startX, startY));
}

// outer most region of object
QRectF Ball::boundingRect() const
{
    return QRect(0, 0, diameter, diameter);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::gray);

    // change ball color as round goes on
    if (hits > 15) {
        brush.setColor(Qt::red);
    }
    else if (hits > 10) {
        brush.setColor("orange");
    }
    else if (hits > 5) {
        brush.setColor(Qt::yellow);
    }

    painter->setBrush(brush);
    painter->drawEllipse(rec);
}

int Ball::getDiameter()
{
    return this->diameter;
}

double Ball::getDx() const
{
    return dx;
}

void Ball::setDx(double dx)
{
    this->dx = dx;
    hits++;

    // increase speed
    if ((hits > 0) && (hits % 5 == 0)) {
        this->dx = this->dx * 1.1;
        dy = dy * 1.1;
    }
}

double Ball::getDy() const
{
    return dy;
}

void Ball::setDy(double dy)
{
    this->dy = dy;
}

void Ball::advance(int phase)
{
    if (!phase) return;

    setPos(mapToParent(dx, dy));

    //qDebug() << "hits: " << hits << " dx: " << dx << " dy: " << dy;
}

