/****************************************************************************
**
** This file was written by Patrick Ly-Vo.
**
****************************************************************************/

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout;
    layout->setSizeConstraint(QLayout::SetFixedSize);

    QLabel *selectLabel = new QLabel("Select the value you want to calculate");
    selection = new QComboBox;
    selection->addItem("Distance (miles)");
    selection->addItem("Fuel economy (mpg)");
    selection->addItem("Fuel used (gallons)");
    label1 = new QLabel("Fuel used (gallons)");
    label2 = new QLabel("Fuel economy (mpg)");
    input1 = new QLineEdit;
    input1->setPlaceholderText("Enter value");
    input2 = new QLineEdit;
    input2->setPlaceholderText("Enter value");
    QPushButton *calculate = new QPushButton(this);
    calculate->setText("Calculate");
    result = new QLineEdit;
    result->setDisabled(true);

    // when QComboBox selection changes, modify QLabels
    connect(selection,SIGNAL(currentIndexChanged(int)),this,SLOT(selectionChanged(int)));

    // clicking button triggers sendData(), which emits redirectData() signal with text from both QLineEdits
    connect(calculate,SIGNAL(released()),this,SLOT(sendData()));
    connect(this,SIGNAL(redirectData(int,QString,QString)),this,SLOT(calculateResult(int,QString,QString)));

    layout->addWidget(selectLabel,0,0);
    layout->addWidget(selection,1,0,1,2);
    layout->addWidget(label1,2,0);
    layout->addWidget(input1,2,1);
    layout->addWidget(label2,3,0);
    layout->addWidget(input2,3,1);
    layout->addWidget(calculate,4,0);
    layout->addWidget(result,4,1);

    setLayout(layout);

    setWindowTitle("MPG Calculator");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::selectionChanged(int index) {
    switch(index) {

    case 0:
        label1->setText("Fuel used (gallons)");
        label2->setText("Fuel economy (mpg)");
        break;
    case 1:
        label1->setText("Distance (miles)");
        label2->setText("Fuel used (gallons)");
        break;
    case 2:
        label1->setText("Distance (miles)");
        label2->setText("Fuel economy (mpg)");
        break;
    }
}

void Dialog::sendData() {
    emit redirectData(selection->currentIndex(),input1->text(),input2->text());
}

void Dialog::calculateResult(int index, QString input1, QString input2) {
    switch(index) {

    case 0:
        result->setText(QString::number(input1.toDouble()*input2.toDouble()));
        break;
    case 1:
        result->setText(QString::number(input1.toDouble()/input2.toDouble()));
        break;
    case 2:
        result->setText(QString::number(input1.toDouble()/input2.toDouble()));
        break;
    }
}
