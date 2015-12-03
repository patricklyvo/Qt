#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finddialog.h"
#include <QtWidgets>

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

// font
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this, "Font");
    if (ok)
    {
        ui->textEdit->setFont(font);
    }
}

// find dialog
void MainWindow::on_actionFind_triggered()
{
    // set find direction to down and match case to 0
    findDirectionDown = true;
    findMatchCaseState = 0;
    // show FindDialog
    findDialog = new FindDialog(this);
    findDialog->show();

    // connecting signal and slot to start finding the specified string
    connect(findDialog, SIGNAL(findClicked(QString)), this, SLOT(findString(QString)));
    // connecting signal and slot to change find direction
    connect(findDialog, SIGNAL(directionClicked(bool)), this, SLOT(changeFindDirection(bool)));
    // connecting signal and slot to change match case state
    connect(findDialog, SIGNAL(matchCaseClicked(int)), this, SLOT(changeMatchCase(int)));
}

// find string
void MainWindow::findString(QString searchString)
{
    if (findMatchCaseState == 0)
    {
        if (findDirectionDown)
        {
            ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
        }
        else
        {
            ui->textEdit->find(searchString, QTextDocument::FindWholeWords | QTextDocument::FindBackward);
        }
    }
    else
    {
        if (findDirectionDown)
        {
            ui->textEdit->find(searchString, QTextDocument::FindWholeWords | QTextDocument::FindCaseSensitively);
        }
        else
        {
            ui->textEdit->find(searchString, QTextDocument::FindWholeWords | QTextDocument::FindBackward | QTextDocument::FindCaseSensitively);
        }
    }
}

// find direction
void MainWindow::changeFindDirection(bool down)
{
    findDirectionDown = down;
}

// find match case
void MainWindow::changeMatchCase(int state)
{
    findMatchCaseState = state;
}
