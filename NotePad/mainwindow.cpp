#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // to fill entire window
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    fileName = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open");

    if (!file.isEmpty())
    {
        QFile openFile(file);
        if (openFile.open(QFile::ReadOnly | QFile::Text))
        {
            fileName = file;
            QTextStream ts(&openFile);
            QString text = ts.readAll();
            openFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile saveFile(fileName);

    if (saveFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream ts(&saveFile);

        ts << ui->textEdit->toPlainText();

        saveFile.flush();
        saveFile.close();
    }
}

void MainWindow::on_actionSave_As_triggered()
{

}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
