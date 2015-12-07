#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "pong.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private:
    void createHorizontalGroupBox();

    Ui::Settings *ui;
    int numPlayers;
    QGroupBox *horizontalGroupBox;
    QPushButton *onePushButton;
    QPushButton *twoPushButton;
    QSpinBox *numBallsBox;

    Pong *game;

public slots:
    void setPlayers1();
    void setPlayers2();
    void play();
};

#endif // SETTINGS_H
