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

private:
    Ui::Dialog *ui;
    QVector<QString> *columnNames;
    QVector<QVector<double> > *data;

private slots:
    void on_loadPushButton_clicked();
};

#endif // DIALOG_H
