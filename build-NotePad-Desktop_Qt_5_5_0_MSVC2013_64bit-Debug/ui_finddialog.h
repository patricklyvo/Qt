/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *upRadioButton;
    QRadioButton *downRadioButton;
    QCheckBox *checkBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *findPushButton;
    QPushButton *cancelPushButton;
    QLineEdit *findLineEdit;
    QLabel *label;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QStringLiteral("FindDialog"));
        FindDialog->resize(329, 100);
        groupBox = new QGroupBox(FindDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(130, 40, 114, 52));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        upRadioButton = new QRadioButton(groupBox);
        upRadioButton->setObjectName(QStringLiteral("upRadioButton"));

        horizontalLayout_2->addWidget(upRadioButton);

        downRadioButton = new QRadioButton(groupBox);
        downRadioButton->setObjectName(QStringLiteral("downRadioButton"));
        downRadioButton->setChecked(true);

        horizontalLayout_2->addWidget(downRadioButton);


        verticalLayout->addLayout(horizontalLayout_2);

        checkBox = new QCheckBox(FindDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 70, 77, 17));
        widget = new QWidget(FindDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(250, 10, 71, 54));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        findPushButton = new QPushButton(widget);
        findPushButton->setObjectName(QStringLiteral("findPushButton"));

        verticalLayout_2->addWidget(findPushButton);

        cancelPushButton = new QPushButton(widget);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));

        verticalLayout_2->addWidget(cancelPushButton);

        findLineEdit = new QLineEdit(FindDialog);
        findLineEdit->setObjectName(QStringLiteral("findLineEdit"));
        findLineEdit->setGeometry(QRect(67, 10, 171, 20));
        label = new QLabel(FindDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 51, 16));
        label->raise();
        findLineEdit->raise();
        findLineEdit->raise();
        label->raise();
        findPushButton->raise();
        cancelPushButton->raise();
        groupBox->raise();
        checkBox->raise();

        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QApplication::translate("FindDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("FindDialog", "Direction", 0));
        upRadioButton->setText(QApplication::translate("FindDialog", "Up", 0));
        downRadioButton->setText(QApplication::translate("FindDialog", "Down", 0));
        checkBox->setText(QApplication::translate("FindDialog", "Match case", 0));
        findPushButton->setText(QApplication::translate("FindDialog", "Find Next", 0));
        cancelPushButton->setText(QApplication::translate("FindDialog", "Cancel", 0));
        label->setText(QApplication::translate("FindDialog", "Find what:", 0));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
