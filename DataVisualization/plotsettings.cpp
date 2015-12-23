#include "plotsettings.h"
#include "ui_plotsettings.h"

PlotSettings::PlotSettings(QWidget *parent, QString xAxisLabelText, QString yAxisLabelText, double xRangeLow, double xRangeHigh, double yRangeLow, double yRangeHigh) :
    QDialog(parent),
    ui(new Ui::PlotSettings)
{
    ui->setupUi(this);

    // saving and loading data into dialog
    this->xAxisLabelText = xAxisLabelText;
    this->yAxisLabelText = yAxisLabelText;
    this->xRangeLow = xRangeLow;
    this->xRangeHigh = xRangeHigh;
    this->yRangeLow = yRangeLow;
    this->yRangeHigh = yRangeHigh;

    if ((this->xAxisLabelText).length() > 0) {
        ui->xAxisLabelEdit->setText(xAxisLabelText);
    }

    if ((this->yAxisLabelText).length() > 0) {
        ui->yAxisLabelEdit->setText(yAxisLabelText);
    }

    ui->xAxisRangeLowEdit->setText(QString::number(xRangeLow));
    ui->xAxisRangeHighEdit->setText(QString::number(xRangeHigh));
    ui->yAxisRangeLowEdit->setText(QString::number(yRangeLow));
    ui->yAxisRangeHighEdit->setText(QString::number(yRangeHigh));

    setWindowTitle(tr("Data Visualization - Plot Settings"));
}

PlotSettings::~PlotSettings()
{
    delete ui;
}

void PlotSettings::on_saveSettingsPushButton_clicked()
{
    // check valid input

    // save settings
}

void PlotSettings::on_cancelSettingsPushButton_clicked()
{
    this->close();
}
