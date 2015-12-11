#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Find"));
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_findPushButton_clicked()
{
    emit findClicked(ui->findLineEdit->text());
}

void FindDialog::on_cancelPushButton_clicked()
{
    this->close();
}

void FindDialog::on_upRadioButton_clicked()
{
    emit directionClicked(false);
}

void FindDialog::on_downRadioButton_clicked()
{
    emit directionClicked(true);
}

void FindDialog::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        emit matchCaseClicked(1);
    }
    else
    {
        emit matchCaseClicked(0);
    }
}
