/********************************************************************************
** Form generated from reading UI file 'plotsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTSETTINGS_H
#define UI_PLOTSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotSettings
{
public:
    QGroupBox *xAxisGroupBox;
    QGridLayout *gridLayout;
    QLabel *xAxisLabel;
    QLabel *xAxisRangeLabel;
    QLineEdit *xAxisRangeLowEdit;
    QLineEdit *xAxisRangeHighEdit;
    QLineEdit *xAxisLabelEdit;
    QGroupBox *yAxisGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *yAxisLabel;
    QLineEdit *yAxisLabelEdit;
    QLabel *yAxisRangeLabel;
    QLineEdit *yAxisRangeLowEdit;
    QLineEdit *yAxisRangeHighEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveSettingsPushButton;
    QPushButton *cancelSettingsPushButton;

    void setupUi(QDialog *PlotSettings)
    {
        if (PlotSettings->objectName().isEmpty())
            PlotSettings->setObjectName(QStringLiteral("PlotSettings"));
        PlotSettings->resize(353, 217);
        xAxisGroupBox = new QGroupBox(PlotSettings);
        xAxisGroupBox->setObjectName(QStringLiteral("xAxisGroupBox"));
        xAxisGroupBox->setGeometry(QRect(10, 10, 333, 79));
        gridLayout = new QGridLayout(xAxisGroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        xAxisLabel = new QLabel(xAxisGroupBox);
        xAxisLabel->setObjectName(QStringLiteral("xAxisLabel"));

        gridLayout->addWidget(xAxisLabel, 0, 0, 1, 1);

        xAxisRangeLabel = new QLabel(xAxisGroupBox);
        xAxisRangeLabel->setObjectName(QStringLiteral("xAxisRangeLabel"));

        gridLayout->addWidget(xAxisRangeLabel, 1, 0, 1, 1);

        xAxisRangeLowEdit = new QLineEdit(xAxisGroupBox);
        xAxisRangeLowEdit->setObjectName(QStringLiteral("xAxisRangeLowEdit"));

        gridLayout->addWidget(xAxisRangeLowEdit, 1, 1, 1, 1);

        xAxisRangeHighEdit = new QLineEdit(xAxisGroupBox);
        xAxisRangeHighEdit->setObjectName(QStringLiteral("xAxisRangeHighEdit"));

        gridLayout->addWidget(xAxisRangeHighEdit, 1, 2, 1, 1);

        xAxisLabelEdit = new QLineEdit(xAxisGroupBox);
        xAxisLabelEdit->setObjectName(QStringLiteral("xAxisLabelEdit"));

        gridLayout->addWidget(xAxisLabelEdit, 0, 1, 1, 2);

        yAxisGroupBox = new QGroupBox(PlotSettings);
        yAxisGroupBox->setObjectName(QStringLiteral("yAxisGroupBox"));
        yAxisGroupBox->setGeometry(QRect(10, 90, 333, 79));
        gridLayout_2 = new QGridLayout(yAxisGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        yAxisLabel = new QLabel(yAxisGroupBox);
        yAxisLabel->setObjectName(QStringLiteral("yAxisLabel"));

        gridLayout_2->addWidget(yAxisLabel, 0, 0, 1, 1);

        yAxisLabelEdit = new QLineEdit(yAxisGroupBox);
        yAxisLabelEdit->setObjectName(QStringLiteral("yAxisLabelEdit"));

        gridLayout_2->addWidget(yAxisLabelEdit, 0, 1, 1, 2);

        yAxisRangeLabel = new QLabel(yAxisGroupBox);
        yAxisRangeLabel->setObjectName(QStringLiteral("yAxisRangeLabel"));

        gridLayout_2->addWidget(yAxisRangeLabel, 1, 0, 1, 1);

        yAxisRangeLowEdit = new QLineEdit(yAxisGroupBox);
        yAxisRangeLowEdit->setObjectName(QStringLiteral("yAxisRangeLowEdit"));

        gridLayout_2->addWidget(yAxisRangeLowEdit, 1, 1, 1, 1);

        yAxisRangeHighEdit = new QLineEdit(yAxisGroupBox);
        yAxisRangeHighEdit->setObjectName(QStringLiteral("yAxisRangeHighEdit"));

        gridLayout_2->addWidget(yAxisRangeHighEdit, 1, 2, 1, 1);

        widget = new QWidget(PlotSettings);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 180, 331, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveSettingsPushButton = new QPushButton(widget);
        saveSettingsPushButton->setObjectName(QStringLiteral("saveSettingsPushButton"));

        horizontalLayout->addWidget(saveSettingsPushButton);

        cancelSettingsPushButton = new QPushButton(widget);
        cancelSettingsPushButton->setObjectName(QStringLiteral("cancelSettingsPushButton"));

        horizontalLayout->addWidget(cancelSettingsPushButton);


        retranslateUi(PlotSettings);

        QMetaObject::connectSlotsByName(PlotSettings);
    } // setupUi

    void retranslateUi(QDialog *PlotSettings)
    {
        PlotSettings->setWindowTitle(QApplication::translate("PlotSettings", "Dialog", 0));
        xAxisGroupBox->setTitle(QApplication::translate("PlotSettings", "X Axis", 0));
        xAxisLabel->setText(QApplication::translate("PlotSettings", "Label:", 0));
        xAxisRangeLabel->setText(QApplication::translate("PlotSettings", "Range:", 0));
        xAxisRangeLowEdit->setPlaceholderText(QApplication::translate("PlotSettings", "Low", 0));
        xAxisRangeHighEdit->setPlaceholderText(QApplication::translate("PlotSettings", "High", 0));
        xAxisLabelEdit->setPlaceholderText(QApplication::translate("PlotSettings", "X Axis Label", 0));
        yAxisGroupBox->setTitle(QApplication::translate("PlotSettings", "Y Axis", 0));
        yAxisLabel->setText(QApplication::translate("PlotSettings", "Label:", 0));
        yAxisLabelEdit->setText(QString());
        yAxisLabelEdit->setPlaceholderText(QApplication::translate("PlotSettings", "Y Axis Label", 0));
        yAxisRangeLabel->setText(QApplication::translate("PlotSettings", "Range:", 0));
        yAxisRangeLowEdit->setPlaceholderText(QApplication::translate("PlotSettings", "Low", 0));
        yAxisRangeHighEdit->setPlaceholderText(QApplication::translate("PlotSettings", "High", 0));
        saveSettingsPushButton->setText(QApplication::translate("PlotSettings", "Save Settings", 0));
        cancelSettingsPushButton->setText(QApplication::translate("PlotSettings", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotSettings: public Ui_PlotSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTSETTINGS_H
