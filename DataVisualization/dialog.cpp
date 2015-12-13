#include "dialog.h"
#include "ui_dialog.h"

struct excel {
    int columnCount;
    QString columnName = "";
    QVector<QString> columns[1];
    QVector<QVector<QString>> data;
};

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // setting up QSqlDatabase with QODBC to read excel worksheet
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //excel.setDatabaseName("DRIVER={Microsoft Excel Driver (*.xlsx)};DBQ=" + QString("C:\Temp\Sample.xlsx"));
    db.setDatabaseName("exceldsn64");

    if (db.open()) {
        qDebug() << "Opened worksheet succesfully!";

        QSqlQuery query("select * from [" + QString("Sheet1") + "$A1:B9]"); // Select range, place A1:B5 after $

        qDebug() << "Columns: " << query.record().count();

        for (int i = 0; i < query.record().count(); i++) {
            qDebug() << "Column Name: " << query.record().fieldName(i);
            while (query.next()) {
                QString column1 = query.value(i).toString();
                qDebug() << column1;
            }
        }

        /*while (query.next()) {
            QString column1 = query.value(0).toString();
            qDebug() << column1;
        }*/

        db.close();
    } else {
        // if file cound't be opened, output last error that occured on the database
        qDebug() << db.lastError().text();
    }
}

Dialog::~Dialog()
{
    delete ui;
}
