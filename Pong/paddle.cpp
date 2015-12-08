#include "paddle.h"

Paddle::Paddle(int playerNum)
{
    speed = 5;

    // starting position for paddles
    int startX;
    int startY;
    if (playerNum == 1) {
        startX = (PADDLE_WIDTH * 2);
    } else {
        startX = (WIDTH - (PADDLE_WIDTH * 2));
    }
    startY = ((HEIGHT - PADDLE_WIDTH) / 2);

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

void Paddle::keyPressEvent(QKeyEvent *e)
{
        int p1 = 0;
        int p2 = 0;

        switch(e->key()) {

        case (Qt::Key_Up):
                p1 = -1;
                break;
        case (Qt::Key_Down):
                p1 = 1;
                break;
        case (Qt::Key_W):
                p2 = -1;
                break;
        case (Qt::Key_S):
                p2 = 1;
                break;
        default:
                p1 = 0;
                p2 = 0;
                break;
        }

        // move paddles
        setPos(mapToParent(0, p1));
}
