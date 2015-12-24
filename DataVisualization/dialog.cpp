/****************************************************************************
**
** This file was written by Patrick Ly-Vo.
**
****************************************************************************/

#include "dialog.h"
#include "ui_dialog.h"

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

    // no data loaded to plot
    dataLoaded = false;

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
    // setting up QSqlDatabase with QODBC to read excel workbook
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("exceldsn64");

    if (db.open()) {
        qDebug() << "Opened worksheet succesfully!";

        QSqlQuery query("select * from [" + sheet + "$" + range + "]"); // Select range, place A1:B5 after $

        int columnCount = query.record().count();
        columnNames = new QVector<QString>;
        data = new QVector<QVector<double> > (columnCount);
        dateTimeData = new QVector<bool> (columnCount);

        // store column names
        for (int i = 0; i < columnCount; i++) {
            columnNames->push_back(query.record().fieldName(i));
        }

        // store data
        while (query.next()) {
            for (int j = 0; j < columnCount; j++) {
                if (query.record().field(j).type() == QVariant::DateTime) {
                    // mark as dateTime as true
                    if (query.at() == 0) (*dateTimeData)[j] = true;

                    (*data)[j].push_back(((query.value(j)).toDateTime()).toTime_t());
                }
                else if (query.record().field(j).type() == QVariant::Double) {
                    (*data)[j].push_back((query.value(j)).toDouble());
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

        // finished loaded Excel sheet
        dataLoaded = true;
    } else {
        // if file cound't be opened, output last error that occured on the database
        qDebug() << db.lastError().text();
    }
}

void Dialog::plot()
{
    QPen plotPen;
    // set graph color: Black,Blue,Red,Green,Yellow,Magenta,Cyan:
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

    int xIndex = ui->xComboBox->currentIndex();
    int yIndex = ui->yComboBox->currentIndex();
    // check for type of graph:
    if (ui->lineRadioButton->isChecked()) {
        // creating line graph and assigning data:
        QCPGraph *graph1 = ui->customPlot->addGraph();
        graph1->setPen(plotPen);
        graph1->setData((*data)[xIndex], (*data)[yIndex]);
    } else {
        // creating bar chart and assigning data:
        QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
        bars1->setPen(plotPen);
        ui->customPlot->addPlottable(bars1);
        bars1->setData((*data)[xIndex], (*data)[yIndex]);
    }

    // if axis is datetime:
    if ((*dateTimeData)[xIndex]) {
        ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
        ui->customPlot->xAxis->setDateTimeFormat("MMMM\nyyyy");
    }
    if ((*dateTimeData)[yIndex]) {
        ui->customPlot->yAxis->setTickLabelType(QCPAxis::ltDateTime);
        ui->customPlot->yAxis->setDateTimeFormat("MMMM\nyyyy");
    }
    if (!(*dateTimeData)[xIndex]) {
        ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltNumber);
    }
    if (!(*dateTimeData)[yIndex]) {
        ui->customPlot->yAxis->setTickLabelType(QCPAxis::ltNumber);
    }

    // setting axes labels:
    ui->customPlot->xAxis->setLabel((*columnNames)[xIndex]);
    ui->customPlot->yAxis->setLabel((*columnNames)[yIndex]);

    // setting axes ranges:
    ui->customPlot->xAxis->setRange(findMin((*data)[xIndex]), findMax((*data)[xIndex]));
    ui->customPlot->yAxis->setRange(findMin((*data)[yIndex]), findMax((*data)[yIndex]));

    // show legend:
    ui->customPlot->legend->setVisible(true);

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
    if (!dataLoaded){
        QMessageBox::warning(this,tr("No Data Warning"),tr("Please load an Excel worksheet before attempting to plot."));
    }
    else if (((*data)[ui->xComboBox->currentIndex()].isEmpty() && !(*dateTimeData)[ui->xComboBox->currentIndex()]) ||
            ((*data)[ui->yComboBox->currentIndex()].isEmpty() && !(*dateTimeData)[ui->yComboBox->currentIndex()])) {
        QMessageBox::warning(this,tr("Data Warning"),tr("Only columns with value type 'double' or 'DateTime' can be plotted."));
    }
    else {
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

void Dialog::on_plotSettingsPushButton_clicked()
{
    // show PlotSettings
    plotSettings = new PlotSettings(this, ui->customPlot->xAxis->label(), ui->customPlot->yAxis->label(),
                                    ui->customPlot->xAxis->range().lower, ui->customPlot->xAxis->range().upper,
                                    ui->customPlot->yAxis->range().lower, ui->customPlot->yAxis->range().upper);
    plotSettings->setAttribute(Qt::WA_DeleteOnClose, true);
    plotSettings->show();

    // connecting signal and slot to update x or y axis labels
    connect(plotSettings, SIGNAL(xAxisLabelChanged(QString)), this, SLOT(updateLabelX(QString)));
    connect(plotSettings, SIGNAL(yAxisLabelChanged(QString)), this, SLOT(updateLabelY(QString)));
    // connecting signal and slot to update x or y axis ranges
    connect(plotSettings, SIGNAL(xAxisRangechanged(double,double)), this, SLOT(updateRangeX(double,double)));
    connect(plotSettings, SIGNAL(yAxisRangechanged(double,double)), this, SLOT(updateRangeY(double,double)));
}

void Dialog::updateLabelX(QString label)
{
    ui->customPlot->xAxis->setLabel(label);
    ui->customPlot->replot();
}

void Dialog::updateLabelY(QString label)
{
    ui->customPlot->yAxis->setLabel(label);
    ui->customPlot->replot();
}

void Dialog::updateRangeX(double low, double high)
{
    ui->customPlot->xAxis->setRange(low, high);
    ui->customPlot->replot();
}

void Dialog::updateRangeY(double low, double high)
{
    ui->customPlot->yAxis->setRange(low, high);
    ui->customPlot->replot();
}
