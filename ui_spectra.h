/********************************************************************************
** Form generated from reading UI file 'spectra.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTRA_H
#define UI_SPECTRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "lcdnumber.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Spectra
{
public:
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *directory_name;
    QToolButton *toolButton;
    QPushButton *start;
    QPushButton *convert;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *sfera;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLineEdit *file_name;
    LCDNumber *lcd_display;
    QLabel *label_3;
    QTextBrowser *logger;
    QTabWidget *tabWidget;
    QWidget *Plot;
    QCustomPlot *widget;
    QWidget *Real_time;
    QCustomPlot *widget_2;
    QPushButton *set_file;

    void setupUi(QWidget *Spectra)
    {
        if (Spectra->objectName().isEmpty())
            Spectra->setObjectName(QStringLiteral("Spectra"));
        Spectra->resize(1100, 600);
        label_2 = new QLabel(Spectra);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 30, 81, 16));
        layoutWidget = new QWidget(Spectra);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 50, 281, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        directory_name = new QLineEdit(layoutWidget);
        directory_name->setObjectName(QStringLiteral("directory_name"));

        horizontalLayout->addWidget(directory_name);

        toolButton = new QToolButton(layoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        horizontalLayout->addWidget(toolButton);

        start = new QPushButton(Spectra);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(100, 140, 75, 23));
        convert = new QPushButton(Spectra);
        convert->setObjectName(QStringLiteral("convert"));
        convert->setGeometry(QRect(100, 180, 75, 23));
        layoutWidget_2 = new QWidget(Spectra);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(440, 530, 297, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        sfera = new QComboBox(layoutWidget_2);
        sfera->setObjectName(QStringLiteral("sfera"));

        horizontalLayout_2->addWidget(sfera);

        comboBox = new QComboBox(layoutWidget_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        pushButton = new QPushButton(layoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        file_name = new QLineEdit(Spectra);
        file_name->setObjectName(QStringLiteral("file_name"));
        file_name->setGeometry(QRect(350, 50, 113, 20));
        lcd_display = new LCDNumber(Spectra);
        lcd_display->setObjectName(QStringLiteral("lcd_display"));
        lcd_display->setGeometry(QRect(250, 130, 181, 71));
        label_3 = new QLabel(Spectra);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 30, 47, 13));
        logger = new QTextBrowser(Spectra);
        logger->setObjectName(QStringLiteral("logger"));
        logger->setGeometry(QRect(40, 240, 301, 321));
        tabWidget = new QTabWidget(Spectra);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(500, 30, 561, 491));
        Plot = new QWidget();
        Plot->setObjectName(QStringLiteral("Plot"));
        widget = new QCustomPlot(Plot);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 50, 391, 401));
        tabWidget->addTab(Plot, QString());
        Real_time = new QWidget();
        Real_time->setObjectName(QStringLiteral("Real_time"));
        widget_2 = new QCustomPlot(Real_time);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(30, 50, 471, 401));
        tabWidget->addTab(Real_time, QString());
        set_file = new QPushButton(Spectra);
        set_file->setObjectName(QStringLiteral("set_file"));
        set_file->setGeometry(QRect(220, 80, 75, 23));

        retranslateUi(Spectra);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Spectra);
    } // setupUi

    void retranslateUi(QWidget *Spectra)
    {
        Spectra->setWindowTitle(QApplication::translate("Spectra", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("Spectra", "Directory", Q_NULLPTR));
        directory_name->setText(QApplication::translate("Spectra", "C:/", Q_NULLPTR));
        toolButton->setText(QApplication::translate("Spectra", "...", Q_NULLPTR));
        start->setText(QApplication::translate("Spectra", "Start", Q_NULLPTR));
        convert->setText(QApplication::translate("Spectra", "Convert", Q_NULLPTR));
        sfera->clear();
        sfera->insertItems(0, QStringList()
         << QApplication::translate("Spectra", "SFERA 1", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 2", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 3", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 4", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 5", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 6", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 7", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 8", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 9", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 10", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 11", Q_NULLPTR)
         << QApplication::translate("Spectra", "SFERA 12", Q_NULLPTR)
        );
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Spectra", "Channel 1", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 2", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 3", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 4", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 5", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 6", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 7", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 8", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 9", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 10", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 11", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 12", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 13", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 14", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 15", Q_NULLPTR)
         << QApplication::translate("Spectra", "Channel 16", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("Spectra", "Refresh", Q_NULLPTR));
        file_name->setText(QApplication::translate("Spectra", "test_spectra", Q_NULLPTR));
        label_3->setText(QApplication::translate("Spectra", "File Name", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Plot), QApplication::translate("Spectra", "Plot", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Real_time), QApplication::translate("Spectra", "Real_time", Q_NULLPTR));
        set_file->setText(QApplication::translate("Spectra", "Set File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Spectra: public Ui_Spectra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTRA_H
