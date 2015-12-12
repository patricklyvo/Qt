#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // setting up QSqlDatabase with QODBC to read excel worksheet
    QSqlDatabase excel = QSqlDatabase::addDatabase("QODBC");
    //excel.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xlsx)};DBQ=" + QString("C:\Temp\Sample.xlsx"));
    excel.setDatabaseName("exceldsn64");

    if (excel.open()) {
        qDebug() << "Opened.";

        QSqlQuery query("select * from [" + QString("Sheet1") + "$A1:A9]"); // Select range, place A1:B5 after $
        while (query.next()) {
            QString column1= query.value(0).toString();
            qDebug() << column1;
        }

        excel.close();
    } else {
        // if file cound't be opened, output last error that occured on the database
        qDebug() << excel.lastError().text();
    }
}

Dialog::~Dialog()
{
    delete ui;
}
