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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
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
    QComboBox *write_mode;
    QLabel *label;
    QCheckBox *overwrite_box;
    QCheckBox *timing_box;
    QTextEdit *comment_box;
    QLabel *label_10;

    void setupUi(QWidget *Spectra)
    {
        if (Spectra->objectName().isEmpty())
            Spectra->setObjectName(QStringLiteral("Spectra"));
        Spectra->resize(1280, 720);
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
        start->setGeometry(QRect(90, 200, 75, 23));
        convert = new QPushButton(Spectra);
        convert->setObjectName(QStringLiteral("convert"));
        convert->setGeometry(QRect(90, 240, 75, 23));
        layoutWidget_2 = new QWidget(Spectra);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(570, 660, 431, 30));
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
        lcd_display->setGeometry(QRect(240, 190, 181, 71));
        label_3 = new QLabel(Spectra);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 30, 47, 13));
        logger = new QTextBrowser(Spectra);
        logger->setObjectName(QStringLiteral("logger"));
        logger->setGeometry(QRect(70, 380, 351, 321));
        tabWidget = new QTabWidget(Spectra);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(480, 20, 800, 600));
        Plot = new QWidget();
        Plot->setObjectName(QStringLiteral("Plot"));
        widget = new QCustomPlot(Plot);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 700, 500));
        tabWidget->addTab(Plot, QString());
        Real_time = new QWidget();
        Real_time->setObjectName(QStringLiteral("Real_time"));
        widget_2 = new QCustomPlot(Real_time);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(30, 30, 700, 500));
        tabWidget->addTab(Real_time, QString());
        set_file = new QPushButton(Spectra);
        set_file->setObjectName(QStringLiteral("set_file"));
        set_file->setGeometry(QRect(210, 100, 75, 23));
        write_mode = new QComboBox(Spectra);
        write_mode->setObjectName(QStringLiteral("write_mode"));
        write_mode->setGeometry(QRect(210, 130, 144, 22));
        label = new QLabel(Spectra);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 130, 42, 22));
        overwrite_box = new QCheckBox(Spectra);
        overwrite_box->setObjectName(QStringLiteral("overwrite_box"));
        overwrite_box->setGeometry(QRect(350, 80, 101, 17));
        overwrite_box->setChecked(true);
        timing_box = new QCheckBox(Spectra);
        timing_box->setObjectName(QStringLiteral("timing_box"));
        timing_box->setGeometry(QRect(350, 100, 101, 17));
        timing_box->setChecked(true);
        comment_box = new QTextEdit(Spectra);
        comment_box->setObjectName(QStringLiteral("comment_box"));
        comment_box->setGeometry(QRect(70, 310, 351, 41));
        label_10 = new QLabel(Spectra);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 290, 47, 13));

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
        write_mode->clear();
        write_mode->insertItems(0, QStringList()
         << QApplication::translate("Spectra", "List Mode", Q_NULLPTR)
         << QApplication::translate("Spectra", "Spectra Mode", Q_NULLPTR)
        );
        label->setText(QApplication::translate("Spectra", "Write in:", Q_NULLPTR));
        overwrite_box->setText(QApplication::translate("Spectra", "Overwrite Alert", Q_NULLPTR));
        timing_box->setText(QApplication::translate("Spectra", "Timing Header", Q_NULLPTR));
        comment_box->setHtml(QApplication::translate("Spectra", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("Spectra", "Comment:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Spectra: public Ui_Spectra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTRA_H
