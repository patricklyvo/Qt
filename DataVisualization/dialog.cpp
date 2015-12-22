/****************************************************************************
**
** This file was written by Patrick Ly-Vo.
**
****************************************************************************/

#include "dialog.h"
#include "ui_dialog.h"

#include "qcustomplot.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // validate range input
    QRegExp rangeRegExp("^((([A-Z])|([A-Z][A-Z]))(([0-9])|([0-9][0-9])|([0-9][0-9][0-9]))):((([A-Z])|([A-Z][A-Z]))(([0-9])|([0-9][0-9])|([0-9][0-9][0-9])))$");
    QRegExpValidator *rangeValidator = new QRegExpValidator(rangeRegExp, this);
    ui->rangeLineEdit->setValidator(rangeValidator);

    // for chart line colors
    QString colorString = "Black,Blue,Red,Green,Yellow,Magenta,Cyan";
    QStringList colors = colorString.split(",");
    ui->colorComboBox->addItems(colors);
    ui->colorComboBox->setCurrentIndex(0);

    setWindowTitle(tr("Data Visualization"));
}

Dialog::~Dialog()
{
    delete ui;
}

// prints stored excel data
void Dialog::printExcel(const QVector<QString> &columnNames, const QVector<QVector<double> > &data)
{
    int numColumns = columnNames.size();
    qDebug() << "Columns Count: " << numColumns;

    for (int i = 0; i < numColumns; i++) {
        qDebug() << "Column Name: " << columnNames[i];

        for (int j = 0; j < data[i].size(); j++) {
            qDebug() << data[i][j];
        }
    }
}

void Dialog::loadExcel(QString sheet, QString range)
{
    // setting up QSqlDatabase with QODBC to read excel worksheet
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("exceldsn64");

    if (db.open()) {
        qDebug() << "Opened worksheet succesfully!";

        QSqlQuery query("select * from [" + sheet + "$" + range + "]"); // Select range, place A1:B5 after $

        int columnCount = query.record().count();
        columnNames = new QVector<QString>;
        data = new QVector<QVector<double> > (columnCount);

        //qDebug() << query.record().field("OrderDate").type(); // only store ints and doubles and dates, multiple 2D vectors - filled depending on field.type

        // store column names
        for (int i = 0; i < columnCount; i++) {
            columnNames->push_back(query.record().fieldName(i));
        }

        // store data
        while (query.next()) {
            for (int j = 0; j < columnCount; j++) {
                if (query.record().field(j).type() == QVariant::DateTime) {
                    // to implement
                }
                else if (query.record().field(j).type() == QVariant::Double) {
                    (*data)[j].push_back(query.value(j).toDouble());
                }
            }
        }

        // verify information
        //printExcel(*columnNames, *data);

        // clear up axis combo box
        ui->xComboBox->clear();
        ui->yComboBox->clear();

        // fill axis combo box
        for (int k = 0; k < columnNames->size(); ++k) {
            ui->xComboBox->addItem((*columnNames)[k]);
            ui->yComboBox->addItem((*columnNames)[k]);
        }

        db.close();
    } else {
        // if file cound't be opened, output last error that occured on the database
        qDebug() << db.lastError().text();
    }
}

void Dialog::plot()
{
    QPen plotPen;
    // set graph color: Black,Blue,Red,Green,Yellow,Magenta,Cyan
    switch (ui->colorComboBox->currentIndex()) {
    case 0:
      plotPen.setColor(Qt::black);
      break;
    case 1:
      plotPen.setColor(Qt::blue);
      break;
    case 2:
      plotPen.setColor(Qt::red);
      break;
    case 3:
      plotPen.setColor(Qt::green);
      break;
    case 4:
      plotPen.setColor(Qt::yellow);
      break;
    case 5:
      plotPen.setColor(Qt::magenta);
      break;
    case 6:
      plotPen.setColor(Qt::cyan);
      break;
    default:
      plotPen.setColor(Qt::black);
      break;
    }

    // check for type of graph
    if (ui->lineRadioButton->isChecked()) {
        // creating line graph and assigning data
        QCPGraph *graph1 = ui->customPlot->addGraph();
        graph1->setPen(plotPen);
        graph1->setData((*data)[ui->xComboBox->currentIndex()], (*data)[ui->yComboBox->currentIndex()]);
    } else {
        // creating bar chart and assigning data
        QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
        bars1->setPen(plotPen);
        ui->customPlot->addPlottable(bars1);
        bars1->setData((*data)[ui->xComboBox->currentIndex()], (*data)[ui->yComboBox->currentIndex()]);
    }

    // setting axes labels
    ui->customPlot->xAxis->setLabel((*columnNames)[ui->xComboBox->currentIndex()]);
    ui->customPlot->yAxis->setLabel((*columnNames)[ui->yComboBox->currentIndex()]);

    // setting axes ranges
    ui->customPlot->xAxis->setRange(findMin((*data)[ui->xComboBox->currentIndex()]), findMax((*data)[ui->xComboBox->currentIndex()]));
    ui->customPlot->yAxis->setRange(findMin((*data)[ui->yComboBox->currentIndex()]), findMax((*data)[ui->yComboBox->currentIndex()]));

    ui->customPlot->replot();
}

const double &Dialog::findMin(const QVector<double> &data)
{
    int minIndex = 0;

    for (double i = 1; i < data.size(); i++) {
        if (data[minIndex] > data[i])
            minIndex = i;
    }

    return data[minIndex];
}

const double &Dialog::findMax(const QVector<double> &data)
{
    int maxIndex = 0;

    for (double i = 1; i < data.size(); i++) {
        if (data[maxIndex] < data[i])
            maxIndex = i;
    }

    return data[maxIndex];
}

void Dialog::on_loadPushButton_clicked()
{
    // make sure user filled in line edits
    if (ui->sheetLineEdit->text().isEmpty()) {
        QMessageBox::warning(this,tr("Sheet Warning"),tr("Please enter which Excel sheet to load."));
    }
    else if (ui->rangeLineEdit->text().isEmpty()) {
        QMessageBox::warning(this,tr("Range Warning"),tr("Please enter the range of data to load."));
    }
    else {
        loadExcel(ui->sheetLineEdit->text(), ui->rangeLineEdit->text());
    }
}

void Dialog::on_plotPushButton_clicked()
{
    // only allow plotting of columns with valid data
    if ((*data)[ui->yComboBox->currentIndex()].isEmpty() || (*data)[ui->yComboBox->currentIndex()].isEmpty()) {
        QMessageBox::warning(this,tr("Data Warning"),tr("Only columns with value type 'double' can be plotted."));
    } else {
        plot();
    }
}

void Dialog::on_clearPushButton_clicked()
{
    // remove old graphs
    ui->customPlot->clearGraphs();
    ui->customPlot->clearPlottables();
    ui->customPlot->replot();
}
