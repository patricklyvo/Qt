/****************************************************************************
**
** This file was written by Patrick Ly-Vo.
**
****************************************************************************/

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QDebug>

#include "qcustomplot.h"
#include "plotsettings.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void printExcel(const QVector<QString> &columnNames, const QVector<QVector<double> > &data);
    void loadExcel(QString sheet, QString range);
    void plot();
    const double &findMin(const QVector<double> &data);
    const double &findMax(const QVector<double> &data);

private:
    Ui::Dialog *ui;
    QVector<QString> *columnNames;
    QVector<QVector<double> > *data;
    QVector<bool> *dateTimeData;
    bool dataLoaded;

    PlotSettings *plotSettings;

private slots:
    // main data visualization dialog slots
    void on_loadPushButton_clicked();

    void on_plotPushButton_clicked();

    void on_clearPushButton_clicked();

    void on_plotSettingsPushButton_clicked();

    // plot settings slots
    void updateLabelX(QString label);

    void updateLabelY(QString label);

    void updateRangeX(double low, double high);

    void updateRangeY(double low, double high);
};

#endif // DIALOG_H
