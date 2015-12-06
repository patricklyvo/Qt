#include "pong.h"
#include "ui_pong.h"

Pong::Pong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pong)
{
    ui->setupUi(this);
    setWindowTitle("Pong");
}

Pong::~Pong()
{
    delete ui;
}
