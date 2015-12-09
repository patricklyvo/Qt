#include "pong.h"
#include "ui_pong.h"

Pong::Pong(QWidget *parent, int players, int speed) :
    QDialog(parent),
    ui(new Ui::Pong)
{
    ui->setupUi(this);
    resize(WIDTH * 1.1, HEIGHT  * 1.1);
    setWindowTitle("Pong");

    qDebug() << "Players: " << players << "Speed: " << speed;

    // set number of players
    this->players = players;

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // tell graphics view type of rendering we want
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);

    QPen borderPen = QPen(Qt::black);

    QPointF topCenter(scene->sceneRect().width() / 2, scene->sceneRect().height());
    QPointF bottomCenter(scene->sceneRect().width() / 2, 0);
    // using lines for collision detection
    topLine = new QLineF(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    leftLine = new QLineF(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    rightLine = new QLineF(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    bottomLine = new QLineF(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    centerLine = new QLineF(topCenter, bottomCenter);

    // adding lines to scene
    scene->addLine(*topLine, borderPen);
    scene->addLine(*leftLine, borderPen);
    scene->addLine(*rightLine, borderPen);
    scene->addLine(*bottomLine, borderPen);
    scene->addLine(*centerLine);

    // generate paddles
    p1 = new Paddle(1);
    scene->addItem(p1);
    if (players == 2) {
        p2 = new Paddle(2);
        scene->addItem(p2);
    }

    // spawn ball and set speed
    ball = new Ball(speed);
    scene->addItem(ball);

    // timer ticks, advance notifies objects in scene to advance one/multiple steps
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    // timer is going off every 100ms
    timer->start(25);

    // check collision
    connect(timer, SIGNAL(timeout()), this, SLOT(ballCollision()));

    this->setFocus();
}

Pong::~Pong()
{
    delete ui;
}

// moving paddles
void Pong::keyPressEvent(QKeyEvent *e)
{
    // single player
    QPointF p1Pos = p1->pos();

    if (e->key() == Qt::Key_W && (p1Pos.y() - PADDLE_SPEED) > 0) {
        p1->moveBy(0, (-1 * PADDLE_SPEED));
    }
    else if (e->key() == Qt::Key_S && (p1Pos.y() + PADDLE_SPEED) < (HEIGHT - PADDLE_HEIGHT)) {
        p1->moveBy(0, PADDLE_SPEED);
        qDebug() << p1->pos();
    }

    // if two players
    if (players  == 2) {
        QPointF p2Pos = p2->pos();

        if (e->key() == Qt::Key_8 && (p2Pos.y() - PADDLE_SPEED) > 0) {
            p2->moveBy(0, (-1 * PADDLE_SPEED));
        }
        else if (e->key() == Qt::Key_5 && (p2Pos.y() + PADDLE_SPEED) < (HEIGHT - PADDLE_HEIGHT)) {
            p2->moveBy(0, PADDLE_SPEED);
        }
    }
}

void Pong::ballCollision()
{
    if (ball->collidesWithItem(p1)) {
        ball->setDx(ball->getDx() * -1);
    }
    if (players > 1) {
        if (ball->collidesWithItem(p2)) {
            ball->setDx(ball->getDx() * -1);
        }
    }
}
