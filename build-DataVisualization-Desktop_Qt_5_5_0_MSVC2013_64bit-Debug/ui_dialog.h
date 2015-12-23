/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QCustomPlot *customPlot;
    QComboBox *yComboBox;
    QComboBox *xComboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *rangeLabel;
    QLineEdit *rangeLineEdit;
    QPushButton *loadPushButton;
    QLabel *sheetLabel;
    QLineEdit *sheetLineEdit;
    QPushButton *plotPushButton;
    QGroupBox *typeGroupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *lineRadioButton;
    QRadioButton *barRadioButton;
    QPushButton *clearPushButton;
    QComboBox *colorComboBox;
    QLabel *label_3;
    QPushButton *plotSettingsPushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(619, 469);
        customPlot = new QCustomPlot(Dialog);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 10, 450, 450));
        yComboBox = new QComboBox(Dialog);
        yComboBox->setObjectName(QStringLiteral("yComboBox"));
        yComboBox->setGeometry(QRect(508, 180, 101, 20));
        xComboBox = new QComboBox(Dialog);
        xComboBox->setObjectName(QStringLiteral("xComboBox"));
        xComboBox->setGeometry(QRect(508, 150, 101, 20));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 150, 33, 16));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(470, 180, 33, 16));
        rangeLabel = new QLabel(Dialog);
        rangeLabel->setObjectName(QStringLiteral("rangeLabel"));
        rangeLabel->setGeometry(QRect(469, 59, 141, 16));
        rangeLineEdit = new QLineEdit(Dialog);
        rangeLineEdit->setObjectName(QStringLiteral("rangeLineEdit"));
        rangeLineEdit->setGeometry(QRect(469, 79, 141, 20));
        loadPushButton = new QPushButton(Dialog);
        loadPushButton->setObjectName(QStringLiteral("loadPushButton"));
        loadPushButton->setGeometry(QRect(469, 109, 141, 23));
        sheetLabel = new QLabel(Dialog);
        sheetLabel->setObjectName(QStringLiteral("sheetLabel"));
        sheetLabel->setGeometry(QRect(469, 9, 91, 16));
        sheetLineEdit = new QLineEdit(Dialog);
        sheetLineEdit->setObjectName(QStringLiteral("sheetLineEdit"));
        sheetLineEdit->setGeometry(QRect(469, 29, 141, 20));
        plotPushButton = new QPushButton(Dialog);
        plotPushButton->setObjectName(QStringLiteral("plotPushButton"));
        plotPushButton->setGeometry(QRect(469, 319, 141, 23));
        typeGroupBox = new QGroupBox(Dialog);
        typeGroupBox->setObjectName(QStringLiteral("typeGroupBox"));
        typeGroupBox->setGeometry(QRect(469, 209, 141, 71));
        layoutWidget = new QWidget(typeGroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 76, 42));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineRadioButton = new QRadioButton(layoutWidget);
        lineRadioButton->setObjectName(QStringLiteral("lineRadioButton"));
        lineRadioButton->setChecked(true);

        verticalLayout->addWidget(lineRadioButton);

        barRadioButton = new QRadioButton(layoutWidget);
        barRadioButton->setObjectName(QStringLiteral("barRadioButton"));

        verticalLayout->addWidget(barRadioButton);

        clearPushButton = new QPushButton(Dialog);
        clearPushButton->setObjectName(QStringLiteral("clearPushButton"));
        clearPushButton->setGeometry(QRect(469, 349, 141, 23));
        colorComboBox = new QComboBox(Dialog);
        colorComboBox->setObjectName(QStringLiteral("colorComboBox"));
        colorComboBox->setGeometry(QRect(509, 289, 101, 22));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(469, 289, 31, 16));
        plotSettingsPushButton = new QPushButton(Dialog);
        plotSettingsPushButton->setObjectName(QStringLiteral("plotSettingsPushButton"));
        plotSettingsPushButton->setGeometry(QRect(469, 379, 141, 23));
        QWidget::setTabOrder(sheetLineEdit, rangeLineEdit);
        QWidget::setTabOrder(rangeLineEdit, loadPushButton);
        QWidget::setTabOrder(loadPushButton, xComboBox);
        QWidget::setTabOrder(xComboBox, yComboBox);
        QWidget::setTabOrder(yComboBox, lineRadioButton);
        QWidget::setTabOrder(lineRadioButton, barRadioButton);
        QWidget::setTabOrder(barRadioButton, plotPushButton);
        QWidget::setTabOrder(plotPushButton, clearPushButton);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        label->setText(QApplication::translate("Dialog", "X Axis:", 0));
        label_2->setText(QApplication::translate("Dialog", "Y Axis:", 0));
        rangeLabel->setText(QApplication::translate("Dialog", "Enter Excel data range:", 0));
        rangeLineEdit->setPlaceholderText(QApplication::translate("Dialog", "ex. A1:B5", 0));
        loadPushButton->setText(QApplication::translate("Dialog", "Load Data", 0));
        sheetLabel->setText(QApplication::translate("Dialog", "Enter Excel sheet:", 0));
        sheetLineEdit->setPlaceholderText(QApplication::translate("Dialog", "ex. Sheet1", 0));
        plotPushButton->setText(QApplication::translate("Dialog", "Plot", 0));
        typeGroupBox->setTitle(QApplication::translate("Dialog", "Graph Type", 0));
        lineRadioButton->setText(QApplication::translate("Dialog", "Line Graph", 0));
        barRadioButton->setText(QApplication::translate("Dialog", "Bar Chart", 0));
        clearPushButton->setText(QApplication::translate("Dialog", "Clear Graphs", 0));
        label_3->setText(QApplication::translate("Dialog", "Color:", 0));
        plotSettingsPushButton->setText(QApplication::translate("Dialog", "Plot Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
