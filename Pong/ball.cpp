#include "ball.h"

Ball::Ball()
{
    // random start rotation
    angle = (qrand() % 360);
    setRotation(angle);

    // set the speed
    speed = 5;

    // random start position
    int startX = qrand() % WIDTH;
    int startY = qrand() % HEIGHT;

    setPos(mapToParent(startX, startY));
}

// outer most region of object
QRectF Ball::boundingRect() const
{
    return QRect(0, 0, 20, 20);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::gray);

    // basic collision detection
    if (scene()->collidingItems(this).isEmpty()) {
        // no collision
        brush.setColor(Qt::green);
    } else {
        // collision
        brush.setColor(Qt::red);

        // set position
        doCollision();
    }

    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}

void Ball::advance(int phase)
{
    if (!phase) return;

    //QPointF location = this->pos();

    setPos(mapToParent(0, -(speed)));
}

void Ball::doCollision()
{
    // get new position

    // change angle with randomness
    if ((qrand() % 2)) {
        setRotation(rotation() + (180 + (qrand() % 10)));
    } else {
        setRotation(rotation() + (180 + (qrand() % -10)));
    }

    // check if new position is in bounds
    QPointF newPoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 2));

    if (!scene()->sceneRect().contains(newPoint)) {
        // move ball in bounds
        newPoint = mapToParent(0, 0);
    } else {
        // set new position
        setPos(newPoint);
    }

}

