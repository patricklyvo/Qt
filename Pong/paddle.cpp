#include "paddle.h"

Paddle::Paddle(int playerNum)
{
    this->player = playerNum;

    // starting position for paddles
    int startX;
    int startY;
    if (player == 1) {
        startX = PADDLE_WIDTH;
    } else {
        startX = (WIDTH - (PADDLE_WIDTH * 2));
    }
    startY = ((HEIGHT - PADDLE_HEIGHT) / 2);

    setPos(mapToParent(startX, startY));
}

QRectF Paddle::boundingRect() const
{
    return QRect(0, 0, PADDLE_WIDTH, PADDLE_HEIGHT);
}

void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::gray);

    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}
