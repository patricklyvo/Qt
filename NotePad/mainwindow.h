#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include "finddialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionUndo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionFont_triggered();

    void on_actionFind_triggered();

public slots:
    void findString(QString searchString);
    void changeFindDirection(bool down);
    void changeMatchCase(int state);

private:
    Ui::MainWindow *ui;
    QString fileName;

    FindDialog *findDialog;
    bool findDirectionDown;
    int findMatchCaseState;
};

#endif // MAINWINDOW_H
