/****************************************************************************
**
** This file was written by Patrick Ly-Vo.
**
****************************************************************************/

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void printExcel(const QVector<QString> &columnNames, const QVector<QVector<double> > &data);
    void loadExcel(QString sheet, QString range);
    void plot();
    const double &findMin(const QVector<double> &data);
    const double &findMax(const QVector<double> &data);

private:
    Ui::Dialog *ui;
    QVector<QString> *columnNames;
    QVector<QVector<double> > *data;

private slots:
    void on_loadPushButton_clicked();
    void on_plotPushButton_clicked();
};

#endif // DIALOG_H
