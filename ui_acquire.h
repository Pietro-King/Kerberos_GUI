/********************************************************************************
** Form generated from reading UI file 'acquire.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACQUIRE_H
#define UI_ACQUIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Acquire
{
public:

    void setupUi(QWidget *Acquire)
    {
        if (Acquire->objectName().isEmpty())
            Acquire->setObjectName(QStringLiteral("Acquire"));
        Acquire->resize(400, 300);

        retranslateUi(Acquire);

        QMetaObject::connectSlotsByName(Acquire);
    } // setupUi

    void retranslateUi(QWidget *Acquire)
    {
        Acquire->setWindowTitle(QApplication::translate("Acquire", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Acquire: public Ui_Acquire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACQUIRE_H
