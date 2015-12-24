#ifndef PLOTSETTINGS_H
#define PLOTSETTINGS_H

#include <QDialog>
#include <QDebug>
#include <QtWidgets>

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

signals:
    void xAxisLabelChanged(QString label);

    void yAxisLabelChanged(QString label);

    void xAxisRangechanged(double low, double high);

    void yAxisRangechanged(double low, double high);

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
