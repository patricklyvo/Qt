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
    explicit PlotSettings(QWidget *parent = 0);
    ~PlotSettings();

private:
    Ui::PlotSettings *ui;
};

#endif // PLOTSETTINGS_H
