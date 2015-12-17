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
    void printExcel(const QVector<QString> &columnNames, const QVector<QVector<QString> > &data);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
