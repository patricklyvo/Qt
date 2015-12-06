#include "pong.h"
#include "ui_pong.h"
#include "ball.h"

Pong::Pong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pong)
{
    ui->setupUi(this);
    resize(WIDTH * 1.1, HEIGHT  * 1.1);
    setWindowTitle("Pong");

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Ask for players
    scene->addText("How many people are playing?");

    // tell graphics view type of rendering we want
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);

    QPen borderPen = QPen(Qt::black);

    QPointF topCenter(scene->sceneRect().width() / 2, scene->sceneRect().height());
    QPointF bottomCenter(scene->sceneRect().width() / 2, 0);
    // using lines for collision detection
    QLineF topLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF leftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF rightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF bottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    QLineF centerLine(topCenter, bottomCenter);

    // adding lines to scene
    scene->addLine(topLine, borderPen);
    scene->addLine(leftLine, borderPen);
    scene->addLine(rightLine, borderPen);
    scene->addLine(bottomLine, borderPen);
    scene->addLine(centerLine);

    // number of ping pong balls in game
    int itemCount = 1;
    for (int i = 0; i < itemCount; i++) {
        Ball *item = new Ball;
        scene->addItem(item);
    }

    // timer ticks, advance notifies objects in scene to advance one/multiple steps
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    // timer is going off every 100ms
    timer->start(25);
}

Pong::~Pong()
{
    delete ui;
}

void Pong::keyPressEvent(QKeyEvent *e)
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
}

