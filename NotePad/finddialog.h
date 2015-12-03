#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();

private slots:
    void on_findPushButton_clicked();

    void on_cancelPushButton_clicked();

signals:
    void findClicked(QString searchString);

private:
    Ui::FindDialog *ui;
};

#endif // FINDDIALOG_H
