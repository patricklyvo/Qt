/****************************************************************************
**
** This file was written by Patrick Ly-Vo.
**
****************************************************************************/

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
    QComboBox *selection;
    QLabel *label1;
    QLabel *label2;
    QLineEdit *input1;
    QLineEdit *input2;
    QLineEdit *result;

signals:
    void redirectData(int index, QString input1, QString input2);

public slots:
    void selectionChanged(int index);
    void sendData();
    void calculateResult(int index, QString input1, QString input2);

};

#endif // DIALOG_H
