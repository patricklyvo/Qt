#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
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
