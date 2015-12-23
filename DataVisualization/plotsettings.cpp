#include "plotsettings.h"
#include "ui_plotsettings.h"

PlotSettings::PlotSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotSettings)
{
    ui->setupUi(this);

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
