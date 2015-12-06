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

    // tell graphics view type of rendering we want
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, WIDTH, HEIGHT);

    QPen borderPen = QPen(Qt::black);

    // using lines for collision detection
    QLineF topLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF leftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF rightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF bottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    // adding lines to scene
    scene->addLine(topLine, borderPen);
    scene->addLine(leftLine, borderPen);
    scene->addLine(rightLine, borderPen);
    scene->addLine(bottomLine, borderPen);

    int itemCount = 1;
    for (int i = 0; i < itemCount; i++) {
        Ball *item = new Ball;
        scene->addItem(item);
    }

    // timer ticks, advance notifies objects in scene to advance one/multiple steps
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    // timer is going off every 100ms
    timer->start(100);
}

Pong::~Pong()
{
    delete ui;
}
