/********************************************************************************
** Form generated from reading UI file 'pong.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PONG_H
#define UI_PONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Pong
{
public:
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Pong)
    {
        if (Pong->objectName().isEmpty())
            Pong->setObjectName(QStringLiteral("Pong"));
        Pong->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Pong);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QGraphicsView(Pong);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout->addWidget(graphicsView);


        retranslateUi(Pong);

        QMetaObject::connectSlotsByName(Pong);
    } // setupUi

    void retranslateUi(QDialog *Pong)
    {
        Pong->setWindowTitle(QApplication::translate("Pong", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Pong: public Ui_Pong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PONG_H
