#include "ball.h"

Ball::Ball()
{
    // random start angle, ensure ball doesn't get stuck
    do {
        angle = (qrand() % 360);
    }
    while (static_cast<int>(angle) % 90 == 0);

    // set the speed
    speed = 5;
    dx = speed;
    dy = speed;

    // start from center
    int startX = WIDTH / 2;
    int startY = HEIGHT / 2;

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

    //painter->fillRect(rec, brush);
    //painter->drawRect(rec);
    painter->setBrush(brush);
    painter->drawEllipse(rec);
}

void Ball::advance(int phase)
{
    if (!phase) return;

    //double theta = qAtan2(dy, dx);
    //angle = theta * (180 / M_PI);

    setPos(mapToParent(dx * qCos(angle), dy * qSin(angle)));
}

void Ball::doCollision()
{
    // get new position
    QPointF location = this->pos();

    qDebug() << "X: " << location.x() << " Y: " << location.y();

    // if hitting a wall, reverse direction
    if (location.x() <= 0 + boundingRect().width() || location.x() >= WIDTH - boundingRect().width()) {
        dx = -dx;
    }
    if (location.y() <= 0 + boundingRect().height() || location.y() >= HEIGHT - boundingRect().height()) {
        dy = -dy;
    }
}

