#include "dialog.h"
#include "ui_dialog.h"

#include "qcustomplot.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // setting up QSqlDatabase with QODBC to read excel worksheet
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("exceldsn64");

    if (db.open()) {
        qDebug() << "Opened worksheet succesfully!";

        QSqlQuery query("select * from [" + QString("Sheet1") + "$A1:G44]"); // Select range, place A1:B5 after $

        int columnCount = query.record().count();
        QVector<QString> columnNames;
        QVector< QVector<QString> > data(columnCount);

        // store column names
        for (int i = 0; i < columnCount; i++) {
            columnNames.push_back(query.record().fieldName(i));
        }

        // store data
        while (query.next()) {
            for (int j = 0; j < columnCount; j++) {
                data[j].push_back(query.value(j).toString());
            }
        }

        // verify information
        printExcel(columnNames, data);

        // set up axis combo box
        for (int j = 0; j < columnCount; j++) {
            ui->xComboBox->addItem(columnNames[j]);
            ui->yComboBox->addItem(columnNames[j]);
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

// prints stored excel data
void Dialog::printExcel(const QVector<QString> &columnNames, const QVector<QVector<QString> > &data)
{
    int numColumns = columnNames.size();
    qDebug() << "Columns: " << numColumns;

    for (int i = 0; i < numColumns; i++) {
        qDebug() << "Column Name: " << columnNames[i];

        for (int j = 0; j < data[i].size(); j++) {
            qDebug() << data[i][j];
        }
    }
}
