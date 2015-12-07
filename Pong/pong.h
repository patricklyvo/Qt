#ifndef PONG_H
#define PONG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#define WIDTH 600
#define HEIGHT (WIDTH / 2)

namespace Ui {
class Pong;
}

class Pong : public QDialog
{
    Q_OBJECT

public:
    //explicit Pong(QWidget *parent = 0);
    Pong(QWidget *parent = 0, int players = 1, int balls = 1);
    ~Pong();

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::Pong *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    int players;
};

#endif // PONG_H
