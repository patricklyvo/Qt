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
    // saving settings

    // make sure range fields are not empty
    if (ui->xAxisRangeLowEdit->text().isEmpty() || ui->xAxisRangeHighEdit->text().isEmpty()) {
        QMessageBox::warning(this,tr("X Axis Range Warning"),tr("Please specify a range for the X axis."));
        return;
    }
    if (ui->yAxisRangeLowEdit->text().isEmpty() || ui->yAxisRangeHighEdit->text().isEmpty()) {
        QMessageBox::warning(this,tr("Y Axis Range Warning"),tr("Please specify a range for the Y axis."));
        return;
    }

    // check if x axis label changed
    if (ui->xAxisLabelEdit->text() != this->xAxisLabelText) {
        emit xAxisLabelChanged(ui->xAxisLabelEdit->text());
    }

    // check if y axis label changed
    if (ui->yAxisLabelEdit->text() != this->yAxisLabelText) {
        emit yAxisLabelChanged(ui->yAxisLabelEdit->text());
    }

    // check if x axis range changed
    if (ui->xAxisRangeLowEdit->text() != QString::number(this->xRangeLow) || ui->xAxisRangeHighEdit->text() != QString::number(this->xRangeHigh)) {
        emit xAxisRangechanged(ui->xAxisRangeLowEdit->text().toDouble(), ui->xAxisRangeHighEdit->text().toDouble());
    }

    // check if y axis range changed
    if (ui->yAxisRangeLowEdit->text() != QString::number(this->yRangeLow) || ui->yAxisRangeHighEdit->text() != QString::number(this->yRangeHigh)) {
        emit yAxisRangechanged(ui->yAxisRangeLowEdit->text().toDouble(), ui->yAxisRangeHighEdit->text().toDouble());
    }

    this->close();
}

void PlotSettings::on_cancelSettingsPushButton_clicked()
{
    this->close();
}
