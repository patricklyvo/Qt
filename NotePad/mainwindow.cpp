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

    setWindowTitle("Untitled - Notepad");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// new text file
void MainWindow::on_actionNew_triggered()
{
    fileName = "";
    ui->textEdit->setPlainText("");
    setWindowTitle("Untitled - Notepad");
}

// open text file
void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open");

    if (!file.isEmpty())
    {
        QFile openFile(file);
        if (openFile.open(QFile::ReadOnly | QFile::Text))
        {
            fileName = file;

            QFileInfo fileInfo(openFile.fileName());
            setWindowTitle(fileInfo.fileName() + " - Notepad");

            QTextStream in(&openFile);
            QString text = in.readAll();
            openFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}


// save text file
void MainWindow::on_actionSave_triggered()
{
    // make sure user doesn't save over file
    if (fileName.isEmpty())
    {
        on_actionSave_As_triggered();
    }

    QFile saveFile(fileName);

    if (saveFile.open(QFile::WriteOnly | QFile::Text))
    {
        QFileInfo fileInfo(saveFile.fileName());
        setWindowTitle(fileInfo.fileName() + " - Notepad");

        QTextStream out(&saveFile);

        out << ui->textEdit->toPlainText();

        saveFile.flush();
        saveFile.close();
    }
}

// save text file as
void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save As", "*.txt");

    // call save function now that file name is provided
    if (!file.isEmpty())
    {
        fileName = file;
        on_actionSave_triggered();
    }
}

// undo
void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

// redo
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

// cut
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

// copy
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

// paste
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
