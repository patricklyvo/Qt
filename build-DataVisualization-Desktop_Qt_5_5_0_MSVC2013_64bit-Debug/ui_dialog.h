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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(551, 329);
        customPlot = new QCustomPlot(Dialog);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 10, 381, 311));
        yComboBox = new QComboBox(Dialog);
        yComboBox->setObjectName(QStringLiteral("yComboBox"));
        yComboBox->setGeometry(QRect(440, 180, 101, 22));
        xComboBox = new QComboBox(Dialog);
        xComboBox->setObjectName(QStringLiteral("xComboBox"));
        xComboBox->setGeometry(QRect(440, 150, 101, 22));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(400, 160, 47, 13));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 180, 47, 13));
        rangeLabel = new QLabel(Dialog);
        rangeLabel->setObjectName(QStringLiteral("rangeLabel"));
        rangeLabel->setGeometry(QRect(400, 60, 141, 16));
        rangeLineEdit = new QLineEdit(Dialog);
        rangeLineEdit->setObjectName(QStringLiteral("rangeLineEdit"));
        rangeLineEdit->setGeometry(QRect(400, 80, 121, 20));
        loadPushButton = new QPushButton(Dialog);
        loadPushButton->setObjectName(QStringLiteral("loadPushButton"));
        loadPushButton->setGeometry(QRect(400, 110, 121, 23));
        sheetLabel = new QLabel(Dialog);
        sheetLabel->setObjectName(QStringLiteral("sheetLabel"));
        sheetLabel->setGeometry(QRect(400, 10, 91, 16));
        sheetLineEdit = new QLineEdit(Dialog);
        sheetLineEdit->setObjectName(QStringLiteral("sheetLineEdit"));
        sheetLineEdit->setGeometry(QRect(400, 30, 121, 20));

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
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
