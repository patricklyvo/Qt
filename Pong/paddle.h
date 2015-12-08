#ifndef PADDLE_H
#define PADDLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

#define WIDTH 600
#define HEIGHT (WIDTH / 2)
#define PADDLE_WIDTH (WIDTH * 0.025)
#define PADDLE_HEIGHT (HEIGHT / 4)

class Paddle : public QGraphicsItem
{
public:
    Paddle(int playerNum);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int player;
};

#endif // PADDLE_H
