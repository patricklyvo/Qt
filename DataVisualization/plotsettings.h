#ifndef PLOTSETTINGS_H
#define PLOTSETTINGS_H

#include <QDialog>

namespace Ui {
class PlotSettings;
}

class PlotSettings : public QDialog
{
    Q_OBJECT

public:
    PlotSettings(QWidget *parent, QString xAxisLabelText, QString yAxisLabelText, double xRangeLow, double xRangeHigh, double yRangeLow, double yRangeHigh);
    ~PlotSettings();

private slots:
    void on_saveSettingsPushButton_clicked();

    void on_cancelSettingsPushButton_clicked();

private:
    Ui::PlotSettings *ui;

    QString xAxisLabelText;
    QString yAxisLabelText;

    double xRangeLow;
    double xRangeHigh;
    double yRangeLow;
    double yRangeHigh;
};

#endif // PLOTSETTINGS_H
