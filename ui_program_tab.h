/********************************************************************************
** Form generated from reading UI file 'program_tab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAM_TAB_H
#define UI_PROGRAM_TAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Program_tab
{
public:
    QLabel *title;
    QComboBox *mode_of_readout;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_16;
    QComboBox *ADJ;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_17;
    QComboBox *GAIN;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_18;
    QComboBox *PEAKINGTIME;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_19;
    QComboBox *PKS_MIRROR;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_20;
    QComboBox *I_REF_SCARICA_PKS;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_21;
    QComboBox *REF_PKS;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_22;
    QComboBox *DAC_OFFSET;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_23;
    QComboBox *DAC_OFFSET_FAST;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_24;
    QComboBox *EN_REF_EXT;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_25;
    QComboBox *TH_REAL;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_26;
    QComboBox *POL_SH;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_27;
    QComboBox *BLH_POLO_1u;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_28;
    QComboBox *BLH_SLEW_RATE_1u;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_29;
    QComboBox *BE;
    QLabel *label_29;
    QComboBox *THR_CUBE;
    QLabel *label_30;
    QLabel *label_31;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *i_mono_pks_phase_2;
    QCheckBox *i_mono_pks_phase_1;
    QCheckBox *i_mono_pks_phase_0;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *bit_247;
    QCheckBox *bit_248;
    QCheckBox *bit_249;
    QCheckBox *bit_250;
    QCheckBox *bit_251;
    QCheckBox *bit_252;
    QCheckBox *bit_253;
    QCheckBox *bit_254;
    QCheckBox *bit_255;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout;
    QCheckBox *larg_reset_2;
    QCheckBox *larg_reset_1;
    QCheckBox *larg_reset_0;
    QLabel *label;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *larg_inhibit_2;
    QCheckBox *larg_inhibit_1;
    QCheckBox *larg_inhibit_0;
    QTextBrowser *logview;
    QPushButton *default_prog;
    QPushButton *program_button;
    QProgressBar *progressBar;
    QCheckBox *NO_SELECT;

    void setupUi(QWidget *Program_tab)
    {
        if (Program_tab->objectName().isEmpty())
            Program_tab->setObjectName(QStringLiteral("Program_tab"));
        Program_tab->resize(1100, 621);
        title = new QLabel(Program_tab);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(380, 10, 351, 41));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);
        mode_of_readout = new QComboBox(Program_tab);
        mode_of_readout->setObjectName(QStringLiteral("mode_of_readout"));
        mode_of_readout->setGeometry(QRect(40, 70, 207, 39));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setKerning(true);
        mode_of_readout->setFont(font1);
        layoutWidget = new QWidget(Program_tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 120, 214, 429));
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        ADJ = new QComboBox(layoutWidget);
        ADJ->setObjectName(QStringLiteral("ADJ"));

        horizontalLayout_16->addWidget(ADJ);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        horizontalLayout_16->addWidget(label_16);


        verticalLayout_8->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        GAIN = new QComboBox(layoutWidget);
        GAIN->setObjectName(QStringLiteral("GAIN"));

        horizontalLayout_17->addWidget(GAIN);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_17->addWidget(label_17);


        verticalLayout_8->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        PEAKINGTIME = new QComboBox(layoutWidget);
        PEAKINGTIME->setObjectName(QStringLiteral("PEAKINGTIME"));

        horizontalLayout_18->addWidget(PEAKINGTIME);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_18->addWidget(label_18);


        verticalLayout_8->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        PKS_MIRROR = new QComboBox(layoutWidget);
        PKS_MIRROR->setObjectName(QStringLiteral("PKS_MIRROR"));

        horizontalLayout_19->addWidget(PKS_MIRROR);

        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_19->addWidget(label_19);


        verticalLayout_8->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        I_REF_SCARICA_PKS = new QComboBox(layoutWidget);
        I_REF_SCARICA_PKS->setObjectName(QStringLiteral("I_REF_SCARICA_PKS"));

        horizontalLayout_20->addWidget(I_REF_SCARICA_PKS);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_20->addWidget(label_20);


        verticalLayout_8->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        REF_PKS = new QComboBox(layoutWidget);
        REF_PKS->setObjectName(QStringLiteral("REF_PKS"));

        horizontalLayout_21->addWidget(REF_PKS);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_21->addWidget(label_21);


        verticalLayout_8->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        DAC_OFFSET = new QComboBox(layoutWidget);
        DAC_OFFSET->setObjectName(QStringLiteral("DAC_OFFSET"));

        horizontalLayout_22->addWidget(DAC_OFFSET);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_22->addWidget(label_22);


        verticalLayout_8->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        DAC_OFFSET_FAST = new QComboBox(layoutWidget);
        DAC_OFFSET_FAST->setObjectName(QStringLiteral("DAC_OFFSET_FAST"));

        horizontalLayout_23->addWidget(DAC_OFFSET_FAST);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_23->addWidget(label_23);


        verticalLayout_8->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        EN_REF_EXT = new QComboBox(layoutWidget);
        EN_REF_EXT->setObjectName(QStringLiteral("EN_REF_EXT"));

        horizontalLayout_24->addWidget(EN_REF_EXT);

        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_24->addWidget(label_24);


        verticalLayout_8->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        TH_REAL = new QComboBox(layoutWidget);
        TH_REAL->setObjectName(QStringLiteral("TH_REAL"));

        horizontalLayout_25->addWidget(TH_REAL);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_25->addWidget(label_25);


        verticalLayout_8->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        POL_SH = new QComboBox(layoutWidget);
        POL_SH->setObjectName(QStringLiteral("POL_SH"));

        horizontalLayout_26->addWidget(POL_SH);

        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_26->addWidget(label_26);


        verticalLayout_8->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        BLH_POLO_1u = new QComboBox(layoutWidget);
        BLH_POLO_1u->setObjectName(QStringLiteral("BLH_POLO_1u"));

        horizontalLayout_27->addWidget(BLH_POLO_1u);

        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_27->addWidget(label_27);


        verticalLayout_8->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        BLH_SLEW_RATE_1u = new QComboBox(layoutWidget);
        BLH_SLEW_RATE_1u->setObjectName(QStringLiteral("BLH_SLEW_RATE_1u"));

        horizontalLayout_28->addWidget(BLH_SLEW_RATE_1u);

        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_28->addWidget(label_28);


        verticalLayout_8->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        BE = new QComboBox(layoutWidget);
        BE->setObjectName(QStringLiteral("BE"));

        horizontalLayout_29->addWidget(BE);

        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QStringLiteral("label_29"));

        horizontalLayout_29->addWidget(label_29);


        verticalLayout_8->addLayout(horizontalLayout_29);

        THR_CUBE = new QComboBox(Program_tab);
        THR_CUBE->setObjectName(QStringLiteral("THR_CUBE"));
        THR_CUBE->setGeometry(QRect(40, 560, 102, 20));
        label_30 = new QLabel(Program_tab);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(150, 560, 102, 23));
        label_31 = new QLabel(Program_tab);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(359, 70, 141, 16));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_31->setFont(font2);
        layoutWidget_2 = new QWidget(Program_tab);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(360, 484, 140, 65));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        i_mono_pks_phase_2 = new QCheckBox(layoutWidget_2);
        i_mono_pks_phase_2->setObjectName(QStringLiteral("i_mono_pks_phase_2"));

        verticalLayout_5->addWidget(i_mono_pks_phase_2);

        i_mono_pks_phase_1 = new QCheckBox(layoutWidget_2);
        i_mono_pks_phase_1->setObjectName(QStringLiteral("i_mono_pks_phase_1"));

        verticalLayout_5->addWidget(i_mono_pks_phase_1);

        i_mono_pks_phase_0 = new QCheckBox(layoutWidget_2);
        i_mono_pks_phase_0->setObjectName(QStringLiteral("i_mono_pks_phase_0"));

        verticalLayout_5->addWidget(i_mono_pks_phase_0);

        layoutWidget_3 = new QWidget(Program_tab);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(360, 90, 65, 203));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        bit_247 = new QCheckBox(layoutWidget_3);
        bit_247->setObjectName(QStringLiteral("bit_247"));

        verticalLayout_3->addWidget(bit_247);

        bit_248 = new QCheckBox(layoutWidget_3);
        bit_248->setObjectName(QStringLiteral("bit_248"));

        verticalLayout_3->addWidget(bit_248);

        bit_249 = new QCheckBox(layoutWidget_3);
        bit_249->setObjectName(QStringLiteral("bit_249"));

        verticalLayout_3->addWidget(bit_249);

        bit_250 = new QCheckBox(layoutWidget_3);
        bit_250->setObjectName(QStringLiteral("bit_250"));

        verticalLayout_3->addWidget(bit_250);

        bit_251 = new QCheckBox(layoutWidget_3);
        bit_251->setObjectName(QStringLiteral("bit_251"));

        verticalLayout_3->addWidget(bit_251);

        bit_252 = new QCheckBox(layoutWidget_3);
        bit_252->setObjectName(QStringLiteral("bit_252"));

        verticalLayout_3->addWidget(bit_252);

        bit_253 = new QCheckBox(layoutWidget_3);
        bit_253->setObjectName(QStringLiteral("bit_253"));

        verticalLayout_3->addWidget(bit_253);

        bit_254 = new QCheckBox(layoutWidget_3);
        bit_254->setObjectName(QStringLiteral("bit_254"));

        verticalLayout_3->addWidget(bit_254);

        bit_255 = new QCheckBox(layoutWidget_3);
        bit_255->setObjectName(QStringLiteral("bit_255"));

        verticalLayout_3->addWidget(bit_255);

        layoutWidget_4 = new QWidget(Program_tab);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(360, 330, 100, 65));
        verticalLayout = new QVBoxLayout(layoutWidget_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        larg_reset_2 = new QCheckBox(layoutWidget_4);
        larg_reset_2->setObjectName(QStringLiteral("larg_reset_2"));

        verticalLayout->addWidget(larg_reset_2);

        larg_reset_1 = new QCheckBox(layoutWidget_4);
        larg_reset_1->setObjectName(QStringLiteral("larg_reset_1"));

        verticalLayout->addWidget(larg_reset_1);

        larg_reset_0 = new QCheckBox(layoutWidget_4);
        larg_reset_0->setObjectName(QStringLiteral("larg_reset_0"));

        verticalLayout->addWidget(larg_reset_0);

        label = new QLabel(Program_tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(359, 310, 101, 16));
        label->setFont(font2);
        layoutWidget_5 = new QWidget(Program_tab);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(360, 410, 107, 65));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        larg_inhibit_2 = new QCheckBox(layoutWidget_5);
        larg_inhibit_2->setObjectName(QStringLiteral("larg_inhibit_2"));

        verticalLayout_4->addWidget(larg_inhibit_2);

        larg_inhibit_1 = new QCheckBox(layoutWidget_5);
        larg_inhibit_1->setObjectName(QStringLiteral("larg_inhibit_1"));

        verticalLayout_4->addWidget(larg_inhibit_1);

        larg_inhibit_0 = new QCheckBox(layoutWidget_5);
        larg_inhibit_0->setObjectName(QStringLiteral("larg_inhibit_0"));

        verticalLayout_4->addWidget(larg_inhibit_0);

        logview = new QTextBrowser(Program_tab);
        logview->setObjectName(QStringLiteral("logview"));
        logview->setGeometry(QRect(760, 60, 291, 511));
        default_prog = new QPushButton(Program_tab);
        default_prog->setObjectName(QStringLiteral("default_prog"));
        default_prog->setGeometry(QRect(570, 420, 121, 41));
        program_button = new QPushButton(Program_tab);
        program_button->setObjectName(QStringLiteral("program_button"));
        program_button->setGeometry(QRect(520, 180, 211, 211));
        QFont font3;
        font3.setPointSize(25);
        program_button->setFont(font3);
        progressBar = new QProgressBar(Program_tab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 590, 761, 23));
        progressBar->setValue(24);
        NO_SELECT = new QCheckBox(Program_tab);
        NO_SELECT->setObjectName(QStringLiteral("NO_SELECT"));
        NO_SELECT->setGeometry(QRect(260, 530, 63, 17));

        retranslateUi(Program_tab);

        QMetaObject::connectSlotsByName(Program_tab);
    } // setupUi

    void retranslateUi(QWidget *Program_tab)
    {
        Program_tab->setWindowTitle(QApplication::translate("Program_tab", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("Program_tab", "SFERA PROGRAM", Q_NULLPTR));
        mode_of_readout->clear();
        mode_of_readout->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "Sparse", Q_NULLPTR)
         << QApplication::translate("Program_tab", "Polling Gamma", Q_NULLPTR)
         << QApplication::translate("Program_tab", "Polling X", Q_NULLPTR)
        );
        ADJ->clear();
        ADJ->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "0", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3", Q_NULLPTR)
         << QApplication::translate("Program_tab", "4", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        ADJ->setToolTip(QApplication::translate("Program_tab", "Used for the GAIN Trimming", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("Program_tab", "ADJ", Q_NULLPTR));
        GAIN->clear();
        GAIN->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "10 keV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "16 keV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "36 keV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "50 keV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "20.000 electrons", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        GAIN->setToolTip(QApplication::translate("Program_tab", "Sets the Gain of the Output Stage Signal", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_17->setText(QApplication::translate("Program_tab", "GAIN", Q_NULLPTR));
        PEAKINGTIME->clear();
        PEAKINGTIME->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "500 ns", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1 us", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2 us", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3 us", Q_NULLPTR)
         << QApplication::translate("Program_tab", "4 us", Q_NULLPTR)
         << QApplication::translate("Program_tab", "6 us", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        PEAKINGTIME->setToolTip(QApplication::translate("Program_tab", "Shaper's Peaking Time", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_18->setText(QApplication::translate("Program_tab", "PEAKING TIME", Q_NULLPTR));
        PKS_MIRROR->clear();
        PKS_MIRROR->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "2.73 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.76 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.8 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.83 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.87 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.91 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.94 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.98 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.02 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.05 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.09 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.12 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.16 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.19 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.23 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.26 V", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        PKS_MIRROR->setToolTip(QApplication::translate("Program_tab", "TR_MIRROR threshold. Is dependent to the Gaussian peak.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_19->setText(QApplication::translate("Program_tab", "PKS MIRROR", Q_NULLPTR));
        I_REF_SCARICA_PKS->clear();
        I_REF_SCARICA_PKS->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "0", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.5 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "6.85 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "10.16 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "13.53 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "16.77 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "20 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "23.21 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "26.82 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "30 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "33.17 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "36.33 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "39.58 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "42.72 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "45.85 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "48.97 uA", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        I_REF_SCARICA_PKS->setToolTip(QApplication::translate("Program_tab", "Current of the signal discharge", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_20->setText(QApplication::translate("Program_tab", "SCARICA PKS", Q_NULLPTR));
        REF_PKS->clear();
        REF_PKS->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "0", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.3 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "6.4 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "9.5 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "12.76 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "15.9 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "19 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "22 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "25.6 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "28.7 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "31.8 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "34.8 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "38 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "41 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "44 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "47.2 uA", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        REF_PKS->setToolTip(QApplication::translate("Program_tab", "Position of the PKS OTA pole", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_21->setText(QApplication::translate("Program_tab", "REF PKS", Q_NULLPTR));
        DAC_OFFSET->clear();
        DAC_OFFSET->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "67.48 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "74.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "86.04 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "103.3 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "125.6 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "152.1 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "179.2 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "207.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "236.6 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "265.2 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "292.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "321.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "349.0 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "377.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "405.1 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "433.4 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "467.8 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "496.0 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "523.4 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "551.6 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "578.7 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "606.8 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "634.0 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "661.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "690.4 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "718.1 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "745.1 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "772.7 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "799.3 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "826.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "853.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "880.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "924.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "951.7 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "978.2 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.005 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.031 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.058 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.085 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.112 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.139 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.166 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.192 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.218 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.244 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.271 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.296 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.323 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.355 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.381 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.407 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.433 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.458 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.509 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.535 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.562 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.588 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.613 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.638 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.663 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.689 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.713 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.739 V", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        DAC_OFFSET->setToolTip(QApplication::translate("Program_tab", "LT Threshold", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_22->setText(QApplication::translate("Program_tab", "DAC OFFSET", Q_NULLPTR));
        DAC_OFFSET_FAST->clear();
        DAC_OFFSET_FAST->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "67.48 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "74.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "86.04 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "103.3 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "125.6 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "152.1 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "179.2 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "207.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "236.6 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "265.2 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "292.2 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "321.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "349.0 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "377.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "405.1 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "433.4 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "467.8 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "496.0 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "523.4 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "551.6mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "578.7 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "606.8 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "634.0 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "661.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "690.4 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "718.1 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "745.1 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "772.7 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "799.3 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "826.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "853.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "880.9 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "924.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "951.7 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "978.2 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.005 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.031 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.058 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.085 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.112 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.139 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.166 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.192 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.218 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.244 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.271 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.296 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.323 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.355 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.381 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.407 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.433 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.458 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.484 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.509 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.535 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.562 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.588 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.613 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.638 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.663 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.689 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.713 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.739 V", Q_NULLPTR)
        );
        label_23->setText(QApplication::translate("Program_tab", "DAC OFFSET FAST", Q_NULLPTR));
        EN_REF_EXT->clear();
        EN_REF_EXT->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "INTERNAL", Q_NULLPTR)
         << QApplication::translate("Program_tab", "EXTERNAL", Q_NULLPTR)
        );
        label_24->setText(QApplication::translate("Program_tab", "EN EXT REFERENCE", Q_NULLPTR));
        TH_REAL->clear();
        TH_REAL->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "76 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "113.5 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "175 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "241 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "308 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "374 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "439 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "504 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "578 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "642 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "706 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "770 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "835 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "898 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "961 mV", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.02 V", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        TH_REAL->setToolTip(QApplication::translate("Program_tab", "HT Inhibit. Put High to inhibit HT events", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_25->setText(QApplication::translate("Program_tab", "TH REAL", Q_NULLPTR));
        POL_SH->clear();
        POL_SH->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "0", Q_NULLPTR)
         << QApplication::translate("Program_tab", "12.8 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "25.7 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "38.3 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "51.7 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "64 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "76.8 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "89.2 uA", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        POL_SH->setToolTip(QApplication::translate("Program_tab", "Default is fine", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_26->setText(QApplication::translate("Program_tab", "POL SH", Q_NULLPTR));
        BLH_POLO_1u->clear();
        BLH_POLO_1u->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "0", Q_NULLPTR)
         << QApplication::translate("Program_tab", "18.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "36.75 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "55.1 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "72.37 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "90.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "108.5 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "126.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "142.1 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "160.2 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "177.9 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "196 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "212.9 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "231 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "248.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "266.5 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "278.25 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "296 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "313.7 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "331.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "348.4 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "366.3 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "384 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "401 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "416.8 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "434.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "452 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "470 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "486.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "504 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "522 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "539 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "544 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "561 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "578 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "596 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "613 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "630 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "648 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "665 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "680 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "698 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "715 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "733 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "750 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "768 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "785 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "802 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "814 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "831 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "849 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "866 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "883 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "900 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "917 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "935 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "950 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "968 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "985 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.02 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.04 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.05 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.07 uA", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        BLH_POLO_1u->setToolTip(QApplication::translate("Program_tab", "Default is fine. For High Peaking times you can increase it.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_27->setText(QApplication::translate("Program_tab", "BLH POLO 1U", Q_NULLPTR));
        BLH_SLEW_RATE_1u->clear();
        BLH_SLEW_RATE_1u->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "0", Q_NULLPTR)
         << QApplication::translate("Program_tab", "18.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "36.75 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "55.1 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "72.37 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "90.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "108.5 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "126.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "142.1 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "160.2 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "177.9 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "196 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "212.9 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "231 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "248.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "266.5 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "278.25 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "296 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "313.7 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "331.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "348.4 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "366.3 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "384 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "401 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "416.8 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "434.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "452 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "470 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "486.6 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "504 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "522 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "539 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "544 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "561 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "578 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "596 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "613 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "630 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "648 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "665 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "680 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "698 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "715 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "733 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "750 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "768 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "785 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "802 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "814 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "831 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "849 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "866 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "883 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "900 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "917 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "935 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "950 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "968 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "985 nA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.02 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.04 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.05 uA", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.07 uA", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        BLH_SLEW_RATE_1u->setToolTip(QApplication::translate("Program_tab", "Default is fine. For High Peaking times you can increase it.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_28->setText(QApplication::translate("Program_tab", "BLH SLEW RATE 1u", Q_NULLPTR));
        BE->clear();
        BE->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "1", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3", Q_NULLPTR)
         << QApplication::translate("Program_tab", "4", Q_NULLPTR)
         << QApplication::translate("Program_tab", "5", Q_NULLPTR)
         << QApplication::translate("Program_tab", "6", Q_NULLPTR)
         << QApplication::translate("Program_tab", "7", Q_NULLPTR)
         << QApplication::translate("Program_tab", "8", Q_NULLPTR)
         << QApplication::translate("Program_tab", "9", Q_NULLPTR)
         << QApplication::translate("Program_tab", "10", Q_NULLPTR)
         << QApplication::translate("Program_tab", "11", Q_NULLPTR)
         << QApplication::translate("Program_tab", "12", Q_NULLPTR)
         << QApplication::translate("Program_tab", "13", Q_NULLPTR)
         << QApplication::translate("Program_tab", "14", Q_NULLPTR)
         << QApplication::translate("Program_tab", "15", Q_NULLPTR)
         << QApplication::translate("Program_tab", "16", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        BE->setToolTip(QApplication::translate("Program_tab", "Channel that is shown at the buffer output testpoints", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_29->setText(QApplication::translate("Program_tab", "SHAPER CHANNEL", Q_NULLPTR));
        THR_CUBE->clear();
        THR_CUBE->insertItems(0, QStringList()
         << QApplication::translate("Program_tab", "1.17 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.31 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.45 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.59 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.7 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "1.87 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.16 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.32 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.46 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.6 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.74 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "2.89 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.03 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.17 V", Q_NULLPTR)
         << QApplication::translate("Program_tab", "3.29 V", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        THR_CUBE->setToolTip(QApplication::translate("Program_tab", "HT Inhibit. Put High to inhibit HT events", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_30->setText(QApplication::translate("Program_tab", "THR CUBE", Q_NULLPTR));
        label_31->setText(QApplication::translate("Program_tab", "SFERA ADDITIONAL BITS", Q_NULLPTR));
        i_mono_pks_phase_2->setText(QApplication::translate("Program_tab", "I_MONO_PKS_PHASE_2", Q_NULLPTR));
        i_mono_pks_phase_1->setText(QApplication::translate("Program_tab", "I_MONO_PKS_PHASE_1", Q_NULLPTR));
        i_mono_pks_phase_0->setText(QApplication::translate("Program_tab", "I_MONO_PKS_PHASE_0", Q_NULLPTR));
        bit_247->setText(QApplication::translate("Program_tab", "BIT_247", Q_NULLPTR));
        bit_248->setText(QApplication::translate("Program_tab", "BIT_248", Q_NULLPTR));
        bit_249->setText(QApplication::translate("Program_tab", "BIT_249", Q_NULLPTR));
        bit_250->setText(QApplication::translate("Program_tab", "BIT_250", Q_NULLPTR));
        bit_251->setText(QApplication::translate("Program_tab", "BIT_251", Q_NULLPTR));
        bit_252->setText(QApplication::translate("Program_tab", "BIT_252", Q_NULLPTR));
        bit_253->setText(QApplication::translate("Program_tab", "BIT_253", Q_NULLPTR));
        bit_254->setText(QApplication::translate("Program_tab", "BIT_254", Q_NULLPTR));
        bit_255->setText(QApplication::translate("Program_tab", "BIT_255", Q_NULLPTR));
        larg_reset_2->setText(QApplication::translate("Program_tab", "LARG_RESET_2", Q_NULLPTR));
        larg_reset_1->setText(QApplication::translate("Program_tab", "LARG_RESET_1", Q_NULLPTR));
        larg_reset_0->setText(QApplication::translate("Program_tab", "LARG_RESET_0", Q_NULLPTR));
        label->setText(QApplication::translate("Program_tab", "INHIBIT TIMINGS", Q_NULLPTR));
        larg_inhibit_2->setText(QApplication::translate("Program_tab", "LARG_INHIBIT_2", Q_NULLPTR));
        larg_inhibit_1->setText(QApplication::translate("Program_tab", "LARG_INHIBIT_1", Q_NULLPTR));
        larg_inhibit_0->setText(QApplication::translate("Program_tab", "LARG_INHIBIT_0", Q_NULLPTR));
        default_prog->setText(QApplication::translate("Program_tab", "DEFAULT", Q_NULLPTR));
        program_button->setText(QApplication::translate("Program_tab", "PROGRAM", Q_NULLPTR));
        NO_SELECT->setText(QApplication::translate("Program_tab", "NO_SEL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Program_tab: public Ui_Program_tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAM_TAB_H
