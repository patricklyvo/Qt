#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QLineEdit *input1;
    QLineEdit *input2;

signals:
    void redirectData(QString input1, QString input2);

public slots:
    void sendData();
    void calculateResult(QString input1, QString input2);

};

#endif // DIALOG_H
