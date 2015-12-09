#include "pong.h"
#include "ui_pong.h"

Pong::Pong(QWidget *parent, int players, int speed) :
    QDialog(parent),
    ui(new Ui::Pong)
{
    ui->setupUi(this);
    resize(WIDTH * 1.1, HEIGHT  * 1.25);
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

    // center line points
    topCenter = new QPointF(scene->sceneRect().width() / 2, scene->sceneRect().height());
    bottomCenter = new QPointF(scene->sceneRect().width() / 2, 0);

    // using lines for collision detection
    topLine = new QLineF(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    leftLine = new QLineF(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    rightLine = new QLineF(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    bottomLine = new QLineF(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    centerLine = new QLineF(*topCenter, *bottomCenter);

    // adding lines to scene
    scene->addLine(*topLine, borderPen);
    scene->addLine(*leftLine, borderPen);
    scene->addLine(*rightLine, borderPen);
    scene->addLine(*bottomLine, borderPen);

    // adding center line to scene
    borderPen = QPen(Qt::black, 1, Qt::DashLine);
    scene->addLine(*centerLine, borderPen);

    // font for text
    QFont font;
    font.setPixelSize(20);
    font.setBold(false);
    font.setFamily("Calibri");

    // generate paddles
    p1 = new Paddle(1);
    scene->addItem(p1);
    p1Score = 0;
    p1Text = new QGraphicsTextItem;
    p1Text->setPos((WIDTH / 5), -30);
    p1Text->setFont(font);
    p1Text->setPlainText(QString::number(p1Score));
    scene->addItem(p1Text);

    if (players == 2) {
        p2 = new Paddle(2);
        scene->addItem(p2);
        p2Score = 0;
        p2Text = new QGraphicsTextItem;
        p2Text->setPos((WIDTH - (WIDTH / 5)), -30);
        p2Text->setFont(font);
        p2Text->setPlainText(QString::number(p2Score));
        scene->addItem(p2Text);
    }

    // spawn ball and set speed
    this->speed = speed;
    ball = new Ball(this->speed);
    scene->addItem(ball);

    // timer ticks, advance notifies objects in scene to advance one/multiple steps
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    // timer is going off every 25ms
    timer->start(25);

    // check collision
    connect(timer, SIGNAL(timeout()), this, SLOT(ballCollision()));

    //this->setFocus();
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

void Pong::reset()
{
    scene->removeItem(ball);
    ball = new Ball(speed);

    // if there is a winner, game stops
    if (p1Score > 10 || p2Score > 10) {
        QFont font;
        font.setPixelSize(30);
        font.setBold(false);
        font.setFamily("Calibri");

        QGraphicsTextItem *winnerText = new QGraphicsTextItem;
        winnerText->setPos(((WIDTH / 2) - 100),((HEIGHT / 2) - 25));
        winnerText->setFont(font);
        if (p1Score > p2Score) {
            winnerText->setPlainText(tr("PLAYER 1 WINS!"));
        } else {
            winnerText->setPlainText(tr("PLAYER 2 WINS!"));
        }
        scene->addItem(winnerText);
    } else {
        scene->addItem(ball);
    }
}

void Pong::ballCollision()
{
    QPointF ballPos = ball->pos();
    QPointF p1Pos = p1->pos();

    // ball passes p1 paddle or collides w/ p1 paddle
    if (ballPos.x() < (p1Pos.x() + PADDLE_WIDTH - abs(ball->getDx()))) {
        if (players == 2) ++p2Score;
        p2Text->setPlainText(QString::number(p2Score));
        reset();
    }
    else if (ball->collidesWithItem(p1)) {
        if ((ballPos.y() < (p1Pos.y() + (PADDLE_HEIGHT * 0.3))) && (ball->getDy() >= 0)) {
            ball->setDy(abs(ball->getDx()) * -1);
        }
        else if ((ballPos.y() > (p1Pos.y() + (PADDLE_HEIGHT * 0.65))) && (ball->getDy() <= 0)) {
            ball->setDy(abs(ball->getDx()));
        }
        else {
            ball->setDy(ball->getDy() * 0.8);
        }
        ball->setDx(ball->getDx() * -1);
    }

    // ball passes p2 paddle or collides w/ p2 paddle
    if (players == 2) {
        QPointF p2Pos = p2->pos();
        if ((ballPos.x() + ball->getDiameter()) > (p2Pos.x() + abs(ball->getDx()))) {
            ++p1Score;
            p1Text->setPlainText(QString::number(p1Score));
            reset();
        }
        else if (ball->collidesWithItem(p2)) {
            if ((ballPos.y() < (p2Pos.y() + (PADDLE_HEIGHT * 0.3))) && (ball->getDy() >= 0)) {
                ball->setDy(abs(ball->getDx()) * -1);
            }
            else if ((ballPos.y() > (p2Pos.y() + (PADDLE_HEIGHT * 0.65))) && (ball->getDy() <= 0)) {
                ball->setDy(abs(ball->getDx()));
            }
            else {
                ball->setDy(ball->getDy() * 0.8);
            }
            ball->setDx(ball->getDx() * -1);
        }
    }

    // collision with top and bottom walls
    if ((ballPos.y() <= 0) || ((ballPos.y() + ball->getDiameter()) >= HEIGHT)) {
        ball->setDy(ball->getDy() * -1);
    }
}
