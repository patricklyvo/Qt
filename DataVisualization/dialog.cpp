#include "dialog.h"
#include "ui_dialog.h"

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

        QSqlQuery query("select * from [" + QString("Sheet1") + "$A1:G44]"); // Select range, place A1:B5 after $

        int columnCount = query.record().count();
        QVector<QString> columnNames;
        QVector< QVector<QString> > data(columnCount);

        for (int i = 0; i < columnCount; i++) {
            columnNames.push_back(query.record().fieldName(i));
        }

        while (query.next()) {
            //QString column1 = query.value(0).toString();
            //QString column2 = query.value(1).toString();
            //qDebug() << column1 << " " << column2;
            for (int j = 0; j < columnCount; j++) {
                data[j].push_back(query.value(j).toString());
            }
        }

        // verify information
        qDebug() << "Columns: " << columnCount;
        for (int k = 0; k < columnCount; k++) {
            qDebug() << "Column Name: " << columnNames[k];
            for (int l = 0; l < data[k].size(); l++) {
                qDebug() << data[k][l];
            }
        }

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
