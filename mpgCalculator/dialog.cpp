#include "dialog.h"
#include "ui_dialog.h"

#include <QLabel>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout;
    layout->setSizeConstraint(QLayout::SetFixedSize);

    QLabel *selectLabel = new QLabel("Select the value you want to calculate");
    QComboBox *selection = new QComboBox;
    selection->addItem("Fuel economy (mpg)");
    selection->addItem("Distance (miles)");
    selection->addItem("Fuel used (gallons)");
    QLabel *distanceLabel = new QLabel("Distance(miles)");
    QLabel *fuelLabel = new QLabel("Fuel used(gallons)");
    input1 = new QLineEdit;
    input1->setPlaceholderText("Enter value");
    input2 = new QLineEdit;
    input2->setPlaceholderText("Enter value");
    QPushButton *calculate = new QPushButton(this);
    calculate->setText("Calculate");
    QLineEdit *result = new QLineEdit;
    result->setDisabled(true);

    // Clicking button triggers sendData(), which emits redirectData() signal with text from both QLineEdits
    connect(calculate,SIGNAL(released()),this,SLOT(sendData()));
    connect(this,SIGNAL(redirectData(QString,QString)),this,SLOT(calculateResult(QString,QString)));

    layout->addWidget(selectLabel,0,0);
    layout->addWidget(selection,1,0,1,2);
    layout->addWidget(distanceLabel,2,0);
    layout->addWidget(input1,2,1);
    layout->addWidget(fuelLabel,3,0);
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

void Dialog::sendData() {
    emit redirectData(input1->text(),input2->text());
}

void Dialog::calculateResult(QString input1, QString input2) {
    QMessageBox::information(this,"Title",input1 + input2);
}
