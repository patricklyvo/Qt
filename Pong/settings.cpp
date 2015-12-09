#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    numPlayers = 0;

    QGridLayout *layout = new QGridLayout;
    layout->setSizeConstraint(QLayout::SetFixedSize);

    // intro text
    QLabel *pongLabel = new QLabel(tr("<h1>Welcome to Pong!</h1>"));

    // how many players
    onePushButton = new QPushButton(this);
    onePushButton->setText(tr("One"));
    twoPushButton = new QPushButton(this);
    twoPushButton->setText(tr("Two"));

    // how many ping pong balls
    QLabel *numBallsLabel = new QLabel(tr("Select ball speed."));
    speedBox = new QSpinBox(this);
    speedBox->setValue(5);
    speedBox->setMinimum(1);
    speedBox->setMaximum(20);

    // play
    QPushButton *playPushButton = new QPushButton(tr("PLAY"));

    // clicking number of players button sets value numPlayers
    connect(onePushButton, SIGNAL(released()), this, SLOT(setPlayers1()));
    connect(twoPushButton, SIGNAL(released()), this, SLOT(setPlayers2()));

    // play button
    connect(playPushButton, SIGNAL(released()), this, SLOT(play()));

    createHorizontalGroupBox();

    layout->addWidget(pongLabel, 0, 0);
    layout->addWidget(horizontalGroupBox, 1, 0);
    layout->addWidget(numBallsLabel, 2, 0);
    layout->addWidget(speedBox, 3, 0);
    layout->addWidget(playPushButton, 4, 0);

    setLayout(layout);

    setWindowTitle(tr("Pong"));
}

Settings::~Settings()
{
    delete ui;
}

void Settings::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Players"));
    QHBoxLayout *hbLayout = new QHBoxLayout;

    hbLayout->addWidget(onePushButton);
    hbLayout->addWidget(twoPushButton);

    horizontalGroupBox->setLayout(hbLayout);
}

void Settings::setPlayers1()
{
    numPlayers = 1;
    onePushButton->setStyleSheet("background-color:red");
    twoPushButton->setStyleSheet("");
}

void Settings::setPlayers2()
{
    numPlayers = 2;
    onePushButton->setStyleSheet("");
    twoPushButton->setStyleSheet("background-color:red");
}

void Settings::play()
{
    if (numPlayers == 0) {
        QMessageBox::warning(this,tr("Pong"),tr("Please specify the number of players."));
        return;
    }
    Pong *game = new Pong(this, numPlayers, speedBox->value());
    game->show();
}
