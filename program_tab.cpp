#include "program_tab.h"
#include "ui_program_tab.h"

Program_tab::Program_tab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Program_tab)
{
    ui->setupUi(this);
    loadSettings();
    ui->progressBar->reset();
}


Sfera_SPI_bits spi_bits;

void Program_tab::saveSettings(){

    QSettings setting("MyComp","MyApp");
    setting.beginGroup("Program_Sfera");
    setting.setValue("1",ui->ADJ->currentIndex());
    setting.setValue("2",ui->DAC_OFFSET->currentIndex());
    setting.setValue("3",ui->EN_REF_EXT->currentIndex());
    setting.setValue("4",ui->GAIN->currentIndex());
    setting.setValue("5",ui->I_REF_SCARICA_PKS->currentIndex());
    setting.setValue("6",ui->mode_of_readout->currentIndex());
    setting.setValue("7",ui->PEAKINGTIME->currentIndex());
    setting.setValue("8",ui->PKS_MIRROR->currentIndex());
    setting.setValue("9",ui->REF_PKS->currentIndex());
    setting.setValue("10",ui->TH_REAL->currentIndex());
    setting.setValue("11",ui->POL_SH->currentIndex());
    setting.setValue("12",ui->BLH_POLO_1u->currentIndex());
    setting.setValue("13",ui->BLH_SLEW_RATE_1u->currentIndex());
    setting.setValue("14",ui->BE->currentIndex());
    setting.setValue("15",ui->bit_247->isChecked());
    setting.setValue("16",ui->bit_248->isChecked());
    setting.setValue("17",ui->bit_249->isChecked());
    setting.setValue("18",ui->bit_250->isChecked());
    setting.setValue("19",ui->bit_251->isChecked());
    setting.setValue("20",ui->bit_252->isChecked());
    setting.setValue("21",ui->bit_253->isChecked());
    setting.setValue("22",ui->bit_254->isChecked());
    setting.setValue("23",ui->bit_255->isChecked());
    setting.setValue("24",ui->larg_reset_2->isChecked());
    setting.setValue("25",ui->larg_reset_1->isChecked());
    setting.setValue("26",ui->larg_reset_0->isChecked());
    setting.setValue("27",ui->larg_inhibit_2->isChecked());
    setting.setValue("28",ui->larg_inhibit_1->isChecked());
    setting.setValue("29",ui->larg_inhibit_0->isChecked());
    setting.setValue("30",ui->i_mono_pks_phase_2->isChecked());
    setting.setValue("31",ui->i_mono_pks_phase_1->isChecked());
    setting.setValue("32",ui->i_mono_pks_phase_0->isChecked());
    setting.setValue("33",ui->DAC_OFFSET_FAST->currentIndex());
    setting.setValue("34",ui->THR_CUBE->currentIndex());
    setting.setValue("35",ui->NO_SELECT->isChecked());
    setting.endGroup();
}

void Program_tab::loadSettings(){

    QSettings setting("MyComp","MyApp");
    setting.beginGroup("Program_Sfera");
    ui->ADJ->setCurrentIndex(setting.value("1").toInt());
    ui->DAC_OFFSET->setCurrentIndex(setting.value("2").toInt());
    ui->EN_REF_EXT->setCurrentIndex(setting.value("3").toInt());
    ui->GAIN->setCurrentIndex(setting.value("4").toInt());
    ui->I_REF_SCARICA_PKS->setCurrentIndex(setting.value("5").toInt());
    ui->mode_of_readout->setCurrentIndex(setting.value("6").toInt());
    ui->PEAKINGTIME->setCurrentIndex(setting.value("7").toInt());
    ui->PKS_MIRROR->setCurrentIndex(setting.value("8").toInt());
    ui->REF_PKS->setCurrentIndex(setting.value("9").toInt());
    ui->TH_REAL->setCurrentIndex(setting.value("10").toInt());
    ui->POL_SH->setCurrentIndex(setting.value("11").toInt());
    ui->BLH_POLO_1u->setCurrentIndex(setting.value("12").toInt());
    ui->BLH_SLEW_RATE_1u->setCurrentIndex(setting.value("13").toInt());
    ui->BE->setCurrentIndex(setting.value("14").toInt());
    ui->bit_247->setChecked(setting.value("15").toBool());
    ui->bit_248->setChecked(setting.value("16").toBool());
    ui->bit_249->setChecked(setting.value("17").toBool());
    ui->bit_250->setChecked(setting.value("18").toBool());
    ui->bit_251->setChecked(setting.value("19").toBool());
    ui->bit_252->setChecked(setting.value("20").toBool());
    ui->bit_253->setChecked(setting.value("21").toBool());
    ui->bit_254->setChecked(setting.value("22").toBool());
    ui->bit_255->setChecked(setting.value("23").toBool());
    ui->larg_reset_2->setChecked(setting.value("24").toBool());
    ui->larg_reset_1->setChecked(setting.value("25").toBool());
    ui->larg_reset_0->setChecked(setting.value("26").toBool());
    ui->larg_inhibit_2->setChecked(setting.value("27").toBool());
    ui->larg_inhibit_1->setChecked(setting.value("28").toBool());
    ui->larg_inhibit_0->setChecked(setting.value("29").toBool());
    ui->i_mono_pks_phase_2->setChecked(setting.value("30").toBool());
    ui->i_mono_pks_phase_1->setChecked(setting.value("31").toBool());
    ui->i_mono_pks_phase_0->setChecked(setting.value("32").toBool());
    ui->DAC_OFFSET_FAST->setCurrentIndex(setting.value("33").toInt());
    ui->THR_CUBE->setCurrentIndex(setting.value("34").toInt());
    ui->NO_SELECT->setChecked(setting.value("35").toBool());
    //ui->VBL->setValue(setting.value("1").toDouble());
    setting.endGroup();
}

void Program_tab::on_default_prog_clicked()
{
    ui->ADJ->setCurrentIndex(0);
    ui->DAC_OFFSET->setCurrentIndex(17);
    ui->EN_REF_EXT->setCurrentIndex(0);
    ui->GAIN->setCurrentIndex(1);
    ui->I_REF_SCARICA_PKS->setCurrentIndex(11);
    ui->mode_of_readout->setCurrentIndex(1);
    ui->PEAKINGTIME->setCurrentIndex(2);
    ui->PKS_MIRROR->setCurrentIndex(5);
    ui->REF_PKS->setCurrentIndex(5);
    ui->TH_REAL->setCurrentIndex(0);
    ui->POL_SH->setCurrentIndex(1);
    ui->BLH_POLO_1u->setCurrentIndex(28);
    ui->BLH_SLEW_RATE_1u->setCurrentIndex(28);
    ui->BE->setCurrentIndex(0);
    ui->bit_247->setChecked(0);
    ui->bit_248->setChecked(0);
    ui->bit_249->setChecked(0);
    ui->bit_250->setChecked(0);
    ui->bit_251->setChecked(0);
    ui->bit_252->setChecked(0);
    ui->bit_253->setChecked(0);
    ui->bit_254->setChecked(0);
    ui->bit_255->setChecked(0);
    ui->larg_reset_2->setChecked(0);
    ui->larg_reset_1->setChecked(0);
    ui->larg_reset_0->setChecked(0);
    ui->larg_inhibit_2->setChecked(0);
    ui->larg_inhibit_1->setChecked(0);
    ui->larg_inhibit_0->setChecked(0);
    ui->i_mono_pks_phase_2->setChecked(0);
    ui->i_mono_pks_phase_1->setChecked(0);
    ui->i_mono_pks_phase_0->setChecked(0);
    ui->DAC_OFFSET_FAST->setCurrentIndex(17);
    ui->THR_CUBE->setCurrentIndex(12);
    ui->NO_SELECT->setChecked(0);
}

void Program_tab::on_program_button_clicked()
{
    ui->logview->clear();
    saveSettings();
    ui->progressBar->reset();

    spi_bits.BIT_247 = ui->bit_247->isChecked();
    spi_bits.BIT_248 = ui->bit_248->isChecked();
    spi_bits.BIT_249 = ui->bit_249->isChecked();
    spi_bits.BIT_250 = ui->bit_250->isChecked();
    spi_bits.BIT_251 = ui->bit_251->isChecked();
    spi_bits.BIT_252 = ui->bit_252->isChecked();
    spi_bits.BIT_253 = ui->bit_253->isChecked();
    spi_bits.BIT_254 = ui->bit_254->isChecked();
    spi_bits.BIT_255 = ui->bit_255->isChecked();
    spi_bits.LARG_RESET_2 = ui->larg_reset_2->isChecked();
    spi_bits.LARG_RESET_1 = ui->larg_reset_1->isChecked();
    spi_bits.LARG_RESET_0 = ui->larg_reset_0->isChecked();
    spi_bits.LARG_INHIBIT_2 = ui->larg_inhibit_2->isChecked();
    spi_bits.LARG_INHIBIT_1 = ui->larg_inhibit_1->isChecked();
    spi_bits.LARG_INHIBIT_0 = ui->larg_inhibit_0->isChecked();
    spi_bits.I_MONO_PKS_PHASE_2 = ui->i_mono_pks_phase_2->isChecked();
    spi_bits.I_MONO_PKS_PHASE_1 = ui->i_mono_pks_phase_1->isChecked();
    spi_bits.I_MONO_PKS_PHASE_0 = ui->i_mono_pks_phase_0->isChecked();
    spi_bits.NO_SELECT=ui->NO_SELECT->isChecked();


    if(ui->mode_of_readout->currentText()=="Polling Gamma")
    {
    qDebug()<<"Gamma Mode\n";
    ui->logview->append("Gamma Mode\n");
            spi_bits.SEL_TIPO_MUX=1;
            spi_bits.SEL_GAMMA=1;
            spi_bits.EN_CHANNEL_GND_N=0;
            spi_bits.KILL_LOGICA_GAMMA_B=1;
            spi_bits.KILL_LOGICA_X=1;//i think it should be 1, but it's written 0 in the spi list
            spi_bits.SEL_STESSO_PAD=0;
            spi_bits.EN_HIGH_Z_LVDS_NEG=1;
            spi_bits.DELAY_TR_IN_ON=1;
            spi_bits.HALF_DELAY_TR_IN=1;
            spi_bits.EN_AUTO_TRIGGER_GAMMA=0;

    }
    if(ui->mode_of_readout->currentText()=="Sparse")
    {
    qDebug()<<"Sparse\n";
    ui->logview->append("Sparse\n");
            spi_bits.SEL_TIPO_MUX=0;
            spi_bits.SEL_GAMMA=0;
            spi_bits.EN_CHANNEL_GND_N=0;
            spi_bits.KILL_LOGICA_GAMMA_B=0;
            spi_bits.KILL_LOGICA_X=0;
            spi_bits.SEL_STESSO_PAD=1;
            spi_bits.EN_HIGH_Z_LVDS_NEG=1;
            spi_bits.DELAY_TR_IN_ON=0;
            spi_bits.HALF_DELAY_TR_IN=1;
            spi_bits.EN_AUTO_TRIGGER_GAMMA=0;

    }
    if(ui->mode_of_readout->currentText()=="Polling X")
    {
    qDebug()<<"X Mode\n";
    ui->logview->append("X Mode\n");
            spi_bits.SEL_TIPO_MUX=1;
            spi_bits.SEL_GAMMA=0;
            spi_bits.EN_CHANNEL_GND_N=1;
            spi_bits.KILL_LOGICA_GAMMA_B=0;
            spi_bits.KILL_LOGICA_X=0;
            spi_bits.SEL_STESSO_PAD=0;
            spi_bits.EN_HIGH_Z_LVDS_NEG=0;
            spi_bits.DELAY_TR_IN_ON=1;
            spi_bits.HALF_DELAY_TR_IN=1;
            spi_bits.EN_AUTO_TRIGGER_GAMMA=0;

    }
    if(ui->ADJ->currentText()=="0")
    {
        spi_bits.ADJ_0=0;
        spi_bits.ADJ_1=0;
        spi_bits.ADJ_2=0;
        spi_bits.ADJ_3=0;
        qDebug()<<ui->ADJ->currentText(); ui->logview->append(ui->ADJ->currentText());
    }
    if(ui->ADJ->currentText()=="1")
    {
        spi_bits.ADJ_0=0;
        spi_bits.ADJ_1=0;
        spi_bits.ADJ_2=0;
        spi_bits.ADJ_3=1;
        qDebug()<<ui->ADJ->currentText(); ui->logview->append(ui->ADJ->currentText());
    }
    if(ui->ADJ->currentText()=="2")
    {
        spi_bits.ADJ_0=0;
        spi_bits.ADJ_1=0;
        spi_bits.ADJ_2=1;
        spi_bits.ADJ_3=1;
        qDebug()<<ui->ADJ->currentText(); ui->logview->append(ui->ADJ->currentText());
    }
    if(ui->ADJ->currentText()=="3")
    {
        spi_bits.ADJ_0=0;
        spi_bits.ADJ_1=1;
        spi_bits.ADJ_2=1;
        spi_bits.ADJ_3=1;
        qDebug()<<ui->ADJ->currentText(); ui->logview->append(ui->ADJ->currentText());
    }
    if(ui->ADJ->currentText()=="4")
    {
        spi_bits.ADJ_0=1;
        spi_bits.ADJ_1=1;
        spi_bits.ADJ_2=1;
        spi_bits.ADJ_3=1;
        qDebug()<<ui->ADJ->currentText(); ui->logview->append(ui->ADJ->currentText());
    }

    if(ui->GAIN->currentText()=="10 keV")
    {
        spi_bits.GAIN_1=1;
        spi_bits.GAIN_2=1;
        spi_bits.GAIN_3=1;
        spi_bits.GAIN_4=1;
        qDebug()<<ui->GAIN->currentText(); ui->logview->append(ui->GAIN->currentText());
    }
    if(ui->GAIN->currentText()=="16 keV")
    {
        spi_bits.GAIN_1=1;
        spi_bits.GAIN_2=1;
        spi_bits.GAIN_3=1;
        spi_bits.GAIN_4=0;
        qDebug()<<ui->GAIN->currentText(); ui->logview->append(ui->GAIN->currentText());
    }

    if(ui->GAIN->currentText()=="36 keV")
    {
        spi_bits.GAIN_1=1;
        spi_bits.GAIN_2=1;
        spi_bits.GAIN_3=0;
        spi_bits.GAIN_4=0;
        qDebug()<<ui->GAIN->currentText(); ui->logview->append(ui->GAIN->currentText());
    }

    if(ui->GAIN->currentText()=="50 keV")
    {
        spi_bits.GAIN_1=1;
        spi_bits.GAIN_2=0;
        spi_bits.GAIN_3=0;
        spi_bits.GAIN_4=0;
        qDebug()<<ui->GAIN->currentText(); ui->logview->append(ui->GAIN->currentText());
    }

    if(ui->GAIN->currentText()=="20.000 electrons")
    {
        spi_bits.GAIN_1=0;
        spi_bits.GAIN_2=0;
        spi_bits.GAIN_3=0;
        spi_bits.GAIN_4=0;
        qDebug()<<ui->GAIN->currentText(); ui->logview->append(ui->GAIN->currentText());
    }

    if(ui->PEAKINGTIME->currentText()=="500 ns")
    {
        spi_bits.SEL_2=1;
        spi_bits.SEL_1=1;
        spi_bits.SEL_0=1;
//            spi_bits.BLH_OHM_MAIN_5=0;
//            spi_bits.BLH_OHM_MAIN_4=1;
//            spi_bits.BLH_OHM_MAIN_3=0;
//            spi_bits.BLH_OHM_MAIN_2=0;
//            spi_bits.BLH_OHM_MAIN_1=0;
//            spi_bits.BLH_OHM_MAIN_0=0;
        qDebug()<<ui->PEAKINGTIME->currentText(); ui->logview->append(ui->PEAKINGTIME->currentText());
    }
    if(ui->PEAKINGTIME->currentText()=="1 us")
    {
        spi_bits.SEL_2=1;
        spi_bits.SEL_1=1;
        spi_bits.SEL_0=0;
//            spi_bits.BLH_OHM_MAIN_5=0;
//            spi_bits.BLH_OHM_MAIN_4=0;
//            spi_bits.BLH_OHM_MAIN_3=1;
//            spi_bits.BLH_OHM_MAIN_2=0;
//            spi_bits.BLH_OHM_MAIN_1=0;
//            spi_bits.BLH_OHM_MAIN_0=1;
        qDebug()<<ui->PEAKINGTIME->currentText(); ui->logview->append(ui->PEAKINGTIME->currentText());
    }
    if(ui->PEAKINGTIME->currentText()=="2 us")
    {
        spi_bits.SEL_2=1;
        spi_bits.SEL_1=0;
        spi_bits.SEL_0=1;
//            spi_bits.BLH_OHM_MAIN_5=0;
//            spi_bits.BLH_OHM_MAIN_4=0;
//            spi_bits.BLH_OHM_MAIN_3=0;
//            spi_bits.BLH_OHM_MAIN_2=1;
//            spi_bits.BLH_OHM_MAIN_1=0;
//            spi_bits.BLH_OHM_MAIN_0=0;
        qDebug()<<ui->PEAKINGTIME->currentText(); ui->logview->append(ui->PEAKINGTIME->currentText());
    }
    if(ui->PEAKINGTIME->currentText()=="3 us")
    {
        spi_bits.SEL_2=1;
        spi_bits.SEL_1=0;
        spi_bits.SEL_0=0;
//            spi_bits.BLH_OHM_MAIN_5=0;
//            spi_bits.BLH_OHM_MAIN_4=0;
//            spi_bits.BLH_OHM_MAIN_3=0;
//            spi_bits.BLH_OHM_MAIN_2=1;
//            spi_bits.BLH_OHM_MAIN_1=0;
//            spi_bits.BLH_OHM_MAIN_0=0;
        qDebug()<<ui->PEAKINGTIME->currentText(); ui->logview->append(ui->PEAKINGTIME->currentText());
    }
    if(ui->PEAKINGTIME->currentText()=="4 us")
    {
        spi_bits.SEL_2=0;
        spi_bits.SEL_1=1;
        spi_bits.SEL_0=1;
//            spi_bits.BLH_OHM_MAIN_5=0;
//            spi_bits.BLH_OHM_MAIN_4=0;
//            spi_bits.BLH_OHM_MAIN_3=0;
//            spi_bits.BLH_OHM_MAIN_2=0;
//            spi_bits.BLH_OHM_MAIN_1=0;
//            spi_bits.BLH_OHM_MAIN_0=1;
        qDebug()<<ui->PEAKINGTIME->currentText(); ui->logview->append(ui->PEAKINGTIME->currentText());
    }
    if(ui->PEAKINGTIME->currentText()=="6 us")
    {
        spi_bits.SEL_2=0;
        spi_bits.SEL_1=1;
        spi_bits.SEL_0=0;
//            spi_bits.BLH_OHM_MAIN_5=0;
//            spi_bits.BLH_OHM_MAIN_4=0;
//            spi_bits.BLH_OHM_MAIN_3=0;
//            spi_bits.BLH_OHM_MAIN_2=0;
//            spi_bits.BLH_OHM_MAIN_1=0;
//            spi_bits.BLH_OHM_MAIN_0=1;
        qDebug()<<ui->PEAKINGTIME->currentText(); ui->logview->append(ui->PEAKINGTIME->currentText());
    }

    if(ui->PKS_MIRROR->currentText()=="2.73 V")
    {
        spi_bits.PKS_MIRROR_3=0;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="2.76 V")
    {
        spi_bits.PKS_MIRROR_3=0;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=1;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="2.8 V")
    {
        spi_bits.PKS_MIRROR_3=0;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=1;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="2.83 V")
    {
        spi_bits.PKS_MIRROR_3=0;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=1;
        spi_bits.PKS_MIRROR_0=1;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="2.87 V")
    {
        spi_bits.PKS_MIRROR_3=0;
        spi_bits.PKS_MIRROR_2=1;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="2.91 V")
    {
        spi_bits.PKS_MIRROR_3=0;
        spi_bits.PKS_MIRROR_2=1;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=1;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="2.94 V")
    {
        spi_bits.PKS_MIRROR_3=0;
        spi_bits.PKS_MIRROR_2=1;
        spi_bits.PKS_MIRROR_1=1;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="2.98 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="3.02 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="3.05 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=1;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }

    if(ui->PKS_MIRROR->currentText()=="3.09 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=1;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="3.12 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=0;
        spi_bits.PKS_MIRROR_1=1;
        spi_bits.PKS_MIRROR_0=1;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="3.16 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=1;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="3.19 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=1;
        spi_bits.PKS_MIRROR_1=0;
        spi_bits.PKS_MIRROR_0=1;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="3.23 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=1;
        spi_bits.PKS_MIRROR_1=1;
        spi_bits.PKS_MIRROR_0=0;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }
    if(ui->PKS_MIRROR->currentText()=="3.26 V")
    {
        spi_bits.PKS_MIRROR_3=1;
        spi_bits.PKS_MIRROR_2=1;
        spi_bits.PKS_MIRROR_1=1;
        spi_bits.PKS_MIRROR_0=1;
        qDebug()<<ui->PKS_MIRROR->currentText(); ui->logview->append(ui->PKS_MIRROR->currentText());
    }

    if(ui->I_REF_SCARICA_PKS->currentText()=="0")
    {
        spi_bits.I_REF_SCARICA_PKS_3=0;
        spi_bits.I_REF_SCARICA_PKS_2=0;
        spi_bits.I_REF_SCARICA_PKS_1=0;
        spi_bits.I_REF_SCARICA_PKS_0=0;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="3.5 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=0;
        spi_bits.I_REF_SCARICA_PKS_2=0;
        spi_bits.I_REF_SCARICA_PKS_1=0;
        spi_bits.I_REF_SCARICA_PKS_0=1;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="6.58 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=0;
        spi_bits.I_REF_SCARICA_PKS_2=0;
        spi_bits.I_REF_SCARICA_PKS_1=1;
        spi_bits.I_REF_SCARICA_PKS_0=0;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="10.16 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=0;
        spi_bits.I_REF_SCARICA_PKS_2=0;
        spi_bits.I_REF_SCARICA_PKS_1=1;
        spi_bits.I_REF_SCARICA_PKS_0=1;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="13.53 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=0;
        spi_bits.I_REF_SCARICA_PKS_2=1;
        spi_bits.I_REF_SCARICA_PKS_1=0;
        spi_bits.I_REF_SCARICA_PKS_0=0;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="16.77 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=0;
        spi_bits.I_REF_SCARICA_PKS_2=1;
        spi_bits.I_REF_SCARICA_PKS_1=0;
        spi_bits.I_REF_SCARICA_PKS_0=1;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="20 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=0;
        spi_bits.I_REF_SCARICA_PKS_2=1;
        spi_bits.I_REF_SCARICA_PKS_1=1;
        spi_bits.I_REF_SCARICA_PKS_0=0;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="23.21 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=0;
        spi_bits.I_REF_SCARICA_PKS_2=1;
        spi_bits.I_REF_SCARICA_PKS_1=1;
        spi_bits.I_REF_SCARICA_PKS_0=1;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="26.82 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=1;
        spi_bits.I_REF_SCARICA_PKS_2=0;
        spi_bits.I_REF_SCARICA_PKS_1=0;
        spi_bits.I_REF_SCARICA_PKS_0=0;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="30 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=1;
        spi_bits.I_REF_SCARICA_PKS_2=0;
        spi_bits.I_REF_SCARICA_PKS_1=0;
        spi_bits.I_REF_SCARICA_PKS_0=1;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="33.17 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=1;
        spi_bits.I_REF_SCARICA_PKS_2=0;
        spi_bits.I_REF_SCARICA_PKS_1=1;
        spi_bits.I_REF_SCARICA_PKS_0=0;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="36.33 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=1;
        spi_bits.I_REF_SCARICA_PKS_2=0;
        spi_bits.I_REF_SCARICA_PKS_1=1;
        spi_bits.I_REF_SCARICA_PKS_0=1;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="39.58 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=1;
        spi_bits.I_REF_SCARICA_PKS_2=1;
        spi_bits.I_REF_SCARICA_PKS_1=0;
        spi_bits.I_REF_SCARICA_PKS_0=0;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="42.72 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=1;
        spi_bits.I_REF_SCARICA_PKS_2=1;
        spi_bits.I_REF_SCARICA_PKS_1=0;
        spi_bits.I_REF_SCARICA_PKS_0=1;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="45.85 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=1;
        spi_bits.I_REF_SCARICA_PKS_2=1;
        spi_bits.I_REF_SCARICA_PKS_1=1;
        spi_bits.I_REF_SCARICA_PKS_0=0;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }
    if(ui->I_REF_SCARICA_PKS->currentText()=="48.97 uA")
    {
        spi_bits.I_REF_SCARICA_PKS_3=1;
        spi_bits.I_REF_SCARICA_PKS_2=1;
        spi_bits.I_REF_SCARICA_PKS_1=1;
        spi_bits.I_REF_SCARICA_PKS_0=1;
        qDebug()<<ui->I_REF_SCARICA_PKS->currentText(); ui->logview->append(ui->I_REF_SCARICA_PKS->currentText());
    }

    if(ui->REF_PKS->currentText()=="0")
    {
        spi_bits.REF_PKS_3=0;
        spi_bits.REF_PKS_2=0;
        spi_bits.REF_PKS_1=0;
        spi_bits.REF_PKS_0=0;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="3.3 uA")
    {
        spi_bits.REF_PKS_3=0;
        spi_bits.REF_PKS_2=0;
        spi_bits.REF_PKS_1=0;
        spi_bits.REF_PKS_0=1;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="6.4 uA")
    {
        spi_bits.REF_PKS_3=0;
        spi_bits.REF_PKS_2=0;
        spi_bits.REF_PKS_1=1;
        spi_bits.REF_PKS_0=0;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="9.5 uA")
    {
        spi_bits.REF_PKS_3=0;
        spi_bits.REF_PKS_2=0;
        spi_bits.REF_PKS_1=1;
        spi_bits.REF_PKS_0=1;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="12.76 uA")
    {
        spi_bits.REF_PKS_3=0;
        spi_bits.REF_PKS_2=1;
        spi_bits.REF_PKS_1=0;
        spi_bits.REF_PKS_0=0;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="15.9 uA")
    {
        spi_bits.REF_PKS_3=0;
        spi_bits.REF_PKS_2=1;
        spi_bits.REF_PKS_1=0;
        spi_bits.REF_PKS_0=1;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="19 uA")
    {
        spi_bits.REF_PKS_3=0;
        spi_bits.REF_PKS_2=1;
        spi_bits.REF_PKS_1=1;
        spi_bits.REF_PKS_0=0;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="22 uA")
    {
        spi_bits.REF_PKS_3=0;
        spi_bits.REF_PKS_2=1;
        spi_bits.REF_PKS_1=1;
        spi_bits.REF_PKS_0=1;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="25.6 uA")
    {
        spi_bits.REF_PKS_3=1;
        spi_bits.REF_PKS_2=0;
        spi_bits.REF_PKS_1=0;
        spi_bits.REF_PKS_0=0;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="28.7 uA")
    {
        spi_bits.REF_PKS_3=1;
        spi_bits.REF_PKS_2=0;
        spi_bits.REF_PKS_1=0;
        spi_bits.REF_PKS_0=1;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="31.8 uA")
    {
        spi_bits.REF_PKS_3=1;
        spi_bits.REF_PKS_2=0;
        spi_bits.REF_PKS_1=1;
        spi_bits.REF_PKS_0=0;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="34.8 uA")
    {
        spi_bits.REF_PKS_3=1;
        spi_bits.REF_PKS_2=0;
        spi_bits.REF_PKS_1=1;
        spi_bits.REF_PKS_0=1;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="38 uA")
    {
        spi_bits.REF_PKS_3=1;
        spi_bits.REF_PKS_2=1;
        spi_bits.REF_PKS_1=0;
        spi_bits.REF_PKS_0=0;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="41 uA")
    {
        spi_bits.REF_PKS_3=1;
        spi_bits.REF_PKS_2=1;
        spi_bits.REF_PKS_1=0;
        spi_bits.REF_PKS_0=1;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="44 uA")
    {
        spi_bits.REF_PKS_3=1;
        spi_bits.REF_PKS_2=1;
        spi_bits.REF_PKS_1=1;
        spi_bits.REF_PKS_0=0;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }
    if(ui->REF_PKS->currentText()=="47.2 uA")
    {
        spi_bits.REF_PKS_3=1;
        spi_bits.REF_PKS_2=1;
        spi_bits.REF_PKS_1=1;
        spi_bits.REF_PKS_0=1;
        qDebug()<<ui->REF_PKS->currentText(); ui->logview->append(ui->REF_PKS->currentText());
    }


    if(ui->DAC_OFFSET->currentText()=="67.48 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="74.9 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="86.04 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="103.3 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="125.6 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="152.1 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="179.2 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="207.5 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="236.6 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="265.2 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="292.9 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="321.5 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="349.0 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="377.5 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="405.1 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="433.4 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="467.8 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="496.0 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="523.4 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="551.6 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="578.7 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="606.8 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="634.0 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="661.9 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="690.4 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="718.1 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="745.1 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="772.7 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="799.3 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="826.9 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="853.5 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="880.9 mV")
    {
        spi_bits.DAC_OFFSET_5=0;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="924.5 mV")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="951.7 mV")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="978.2 mV")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.005 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.031 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.058 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.085 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.112 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.139 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.166 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.192 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.218 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.244 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.271 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.296 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.323 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=0;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.355 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.381 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.407 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.433 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.458 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.484 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.509 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.535 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=0;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.562 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.588 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.613 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.638 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=0;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.663 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.689 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=0;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.713 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=0;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }
    if(ui->DAC_OFFSET->currentText()=="1.739 V")
    {
        spi_bits.DAC_OFFSET_5=1;
        spi_bits.DAC_OFFSET_4=1;
        spi_bits.DAC_OFFSET_3=1;
        spi_bits.DAC_OFFSET_2=1;
        spi_bits.DAC_OFFSET_1=1;
        spi_bits.DAC_OFFSET_0=1;
        qDebug()<<ui->DAC_OFFSET->currentText(); ui->logview->append(ui->DAC_OFFSET->currentText());
    }

    if(ui->DAC_OFFSET_FAST->currentText()=="67.48 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="74.9 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="86.04 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="103.3 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="125.6 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="152.1 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="179.2 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="207.5 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="236.6 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="265.2 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="292.9 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="321.5 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="349.0 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="377.5 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="405.1 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="433.4 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="467.8 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="496.0 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="523.4 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="551.6 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="578.7 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="606.8 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="634.0 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="661.9 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="690.4 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="718.1 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="745.1 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="772.7 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="799.3 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="826.9 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="853.5 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="880.9 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=0;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="924.5 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="951.7 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="978.2 mV")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.005 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.031 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.058 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.085 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.112 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.139 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.166 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.192 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.218 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.244 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.271 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.296 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.323 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=0;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.355 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.381 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.407 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.433 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.458 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.484 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.509 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.535 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=0;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.562 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.588 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.613 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.638 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=0;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.663 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.689 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=0;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.713 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=0;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }
    if(ui->DAC_OFFSET_FAST->currentText()=="1.739 V")
    {
        spi_bits.DAC_OFFSET_FAST_5=1;
        spi_bits.DAC_OFFSET_FAST_4=1;
        spi_bits.DAC_OFFSET_FAST_3=1;
        spi_bits.DAC_OFFSET_FAST_2=1;
        spi_bits.DAC_OFFSET_FAST_1=1;
        spi_bits.DAC_OFFSET_FAST_0=1;
        qDebug()<<ui->DAC_OFFSET_FAST->currentText(); ui->logview->append(ui->DAC_OFFSET_FAST->currentText());
    }

    if(ui->EN_REF_EXT->currentText()=="INTERNAL")
    {
        spi_bits.EN_REF_EXT=0;
        qDebug()<<ui->EN_REF_EXT->currentText(); ui->logview->append(ui->EN_REF_EXT->currentText());
    }
    if(ui->EN_REF_EXT->currentText()=="EXTERNAL")
    {
        spi_bits.EN_REF_EXT=1;
        qDebug()<<ui->EN_REF_EXT->currentText(); ui->logview->append(ui->EN_REF_EXT->currentText());
    }
    if(ui->TH_REAL->currentText()=="76 mV")
    {
        spi_bits.TH_REAL_3=0;
        spi_bits.TH_REAL_2=0;
        spi_bits.TH_REAL_1=0;
        spi_bits.TH_REAL_0=0;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="113.5 mV")
    {
        spi_bits.TH_REAL_3=0;
        spi_bits.TH_REAL_2=0;
        spi_bits.TH_REAL_1=0;
        spi_bits.TH_REAL_0=1;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="175 mV")
    {
        spi_bits.TH_REAL_3=0;
        spi_bits.TH_REAL_2=0;
        spi_bits.TH_REAL_1=1;
        spi_bits.TH_REAL_0=0;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="241 mV")
    {
        spi_bits.TH_REAL_3=0;
        spi_bits.TH_REAL_2=0;
        spi_bits.TH_REAL_1=1;
        spi_bits.TH_REAL_0=1;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="308 mV")
    {
        spi_bits.TH_REAL_3=0;
        spi_bits.TH_REAL_2=1;
        spi_bits.TH_REAL_1=0;
        spi_bits.TH_REAL_0=0;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="374 mV")
    {
        spi_bits.TH_REAL_3=0;
        spi_bits.TH_REAL_2=1;
        spi_bits.TH_REAL_1=0;
        spi_bits.TH_REAL_0=1;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="439 mV")
    {
        spi_bits.TH_REAL_3=0;
        spi_bits.TH_REAL_2=1;
        spi_bits.TH_REAL_1=1;
        spi_bits.TH_REAL_0=0;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="504 mV")
    {
        spi_bits.TH_REAL_3=0;
        spi_bits.TH_REAL_2=1;
        spi_bits.TH_REAL_1=1;
        spi_bits.TH_REAL_0=1;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="578 mV")
    {
        spi_bits.TH_REAL_3=1;
        spi_bits.TH_REAL_2=0;
        spi_bits.TH_REAL_1=0;
        spi_bits.TH_REAL_0=0;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="642 mV")
    {
        spi_bits.TH_REAL_3=1;
        spi_bits.TH_REAL_2=0;
        spi_bits.TH_REAL_1=0;
        spi_bits.TH_REAL_0=1;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="706 mV")
    {
        spi_bits.TH_REAL_3=1;
        spi_bits.TH_REAL_2=0;
        spi_bits.TH_REAL_1=1;
        spi_bits.TH_REAL_0=0;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="770 mV")
    {
        spi_bits.TH_REAL_3=1;
        spi_bits.TH_REAL_2=0;
        spi_bits.TH_REAL_1=1;
        spi_bits.TH_REAL_0=1;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="835 mV")
    {
        spi_bits.TH_REAL_3=1;
        spi_bits.TH_REAL_2=1;
        spi_bits.TH_REAL_1=0;
        spi_bits.TH_REAL_0=0;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="898 mV")
    {
        spi_bits.TH_REAL_3=1;
        spi_bits.TH_REAL_2=1;
        spi_bits.TH_REAL_1=0;
        spi_bits.TH_REAL_0=1;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="961 mV")
    {
        spi_bits.TH_REAL_3=1;
        spi_bits.TH_REAL_2=1;
        spi_bits.TH_REAL_1=1;
        spi_bits.TH_REAL_0=0;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }
    if(ui->TH_REAL->currentText()=="1.02 V")
    {
        spi_bits.TH_REAL_3=1;
        spi_bits.TH_REAL_2=1;
        spi_bits.TH_REAL_1=1;
        spi_bits.TH_REAL_0=1;
        qDebug()<<ui->TH_REAL->currentText(); ui->logview->append(ui->TH_REAL->currentText());
    }

    if(ui->POL_SH->currentText()=="0")
    {
        spi_bits.POL_SH_2=0;
        spi_bits.POL_SH_1=0;
        spi_bits.POL_SH_0=0;

        qDebug()<<ui->POL_SH->currentText(); ui->logview->append(ui->POL_SH->currentText());
    }
    if(ui->POL_SH->currentText()=="12.8 uA")
    {
        spi_bits.POL_SH_2=0;
        spi_bits.POL_SH_1=0;
        spi_bits.POL_SH_0=1;

        qDebug()<<ui->POL_SH->currentText(); ui->logview->append(ui->POL_SH->currentText());
    }
    if(ui->POL_SH->currentText()=="25.7 uA")
    {
        spi_bits.POL_SH_2=0;
        spi_bits.POL_SH_1=1;
        spi_bits.POL_SH_0=0;

        qDebug()<<ui->POL_SH->currentText(); ui->logview->append(ui->POL_SH->currentText());
    }
    if(ui->POL_SH->currentText()=="38.3 uA")
    {
        spi_bits.POL_SH_2=0;
        spi_bits.POL_SH_1=1;
        spi_bits.POL_SH_0=1;

        qDebug()<<ui->POL_SH->currentText(); ui->logview->append(ui->POL_SH->currentText());
    }
    if(ui->POL_SH->currentText()=="51.7 uA")
    {
        spi_bits.POL_SH_2=1;
        spi_bits.POL_SH_1=0;
        spi_bits.POL_SH_0=0;

        qDebug()<<ui->POL_SH->currentText(); ui->logview->append(ui->POL_SH->currentText());
    }
    if(ui->POL_SH->currentText()=="64 uA")
    {
        spi_bits.POL_SH_2=1;
        spi_bits.POL_SH_1=0;
        spi_bits.POL_SH_0=1;

        qDebug()<<ui->POL_SH->currentText(); ui->logview->append(ui->POL_SH->currentText());
    }
    if(ui->POL_SH->currentText()=="76.8 uA")
    {
        spi_bits.POL_SH_2=1;
        spi_bits.POL_SH_1=1;
        spi_bits.POL_SH_0=0;

        qDebug()<<ui->POL_SH->currentText(); ui->logview->append(ui->POL_SH->currentText());
    }
    if(ui->POL_SH->currentText()=="89.2 uA")
    {
        spi_bits.POL_SH_2=1;
        spi_bits.POL_SH_1=1;
        spi_bits.POL_SH_0=1;

        qDebug()<<ui->POL_SH->currentText(); ui->logview->append(ui->POL_SH->currentText());
    }

    if(ui->BLH_POLO_1u->currentText()=="0")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="18.6 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="36.75 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="55.1 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="72.37 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="90.6 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="108.5 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="126.6 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="142.1 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="160.2 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="177.9 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="196 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="212.9 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="231 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="248.6 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="266.5 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="278.25 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="296 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="313.7 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="331.6 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="348.4 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="366.3 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="384 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="401 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="416.8 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="434.6 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="452 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="470 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="486.6 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="504 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="522 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="539 nA")
    {
        spi_bits.BLH_POLO_1u_5=0;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="544 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="561 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="578 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="596 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="613 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="630 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="648 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="665 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="680 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="698 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="715 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="733 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="750 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="768 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="785 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="802 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=0;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="814 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="831 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="849 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="866 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="883 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="900 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="917 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="935 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=0;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="950 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="968 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="985 nA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="1 uA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=0;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="1.02 uA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="1.04 uA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=0;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="1.05 uA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=0;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }
    if(ui->BLH_POLO_1u->currentText()=="1.07 uA")
    {
        spi_bits.BLH_POLO_1u_5=1;
        spi_bits.BLH_POLO_1u_4=1;
        spi_bits.BLH_POLO_1u_3=1;
        spi_bits.BLH_POLO_1u_2=1;
        spi_bits.BLH_POLO_1u_1=1;
        spi_bits.BLH_POLO_1u_0=1;

        qDebug()<<ui->BLH_POLO_1u->currentText(); ui->logview->append(ui->BLH_POLO_1u->currentText());
    }

    if(ui->BLH_SLEW_RATE_1u->currentText()=="0")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="18.6 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="36.75 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="55.1 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="72.37 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="90.6 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="108.5 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="126.6 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="142.1 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="160.2 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="177.9 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="196 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="212.9 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="231 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="248.6 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="266.5 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="278.25 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="296 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="313.7 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="331.6 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="348.4 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="366.3 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="384 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="401 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="416.8 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="434.6 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="452 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="470 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="486.6 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="504 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="522 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="539 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=0;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="544 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="561 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="578 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="596 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="613 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="630 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="648 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="665 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="680 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="698 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="715 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="733 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="750 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="768 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="785 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="802 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=0;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="814 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="831 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="849 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="866 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="883 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="900 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="917 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="935 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=0;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="950 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="968 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="985 nA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="1 uA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=0;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="1.02 uA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="1.04 uA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=0;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="1.05 uA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=0;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }
    if(ui->BLH_SLEW_RATE_1u->currentText()=="1.07 uA")
    {
        spi_bits.BLH_SLEW_RATE_1u_5=1;
        spi_bits.BLH_SLEW_RATE_1u_4=1;
        spi_bits.BLH_SLEW_RATE_1u_3=1;
        spi_bits.BLH_SLEW_RATE_1u_2=1;
        spi_bits.BLH_SLEW_RATE_1u_1=1;
        spi_bits.BLH_SLEW_RATE_1u_0=1;

        qDebug()<<ui->BLH_SLEW_RATE_1u->currentText(); ui->logview->append(ui->BLH_SLEW_RATE_1u->currentText());
    }

    if(ui->THR_CUBE->currentText()=="1.17 V")
    {
        spi_bits.THR_CUBE_3=0;
        spi_bits.THR_CUBE_2=0;
        spi_bits.THR_CUBE_1=0;
        spi_bits.THR_CUBE_0=0;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="1.31 V")
    {
        spi_bits.THR_CUBE_3=0;
        spi_bits.THR_CUBE_2=0;
        spi_bits.THR_CUBE_1=0;
        spi_bits.THR_CUBE_0=1;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="1.45 V")
    {
        spi_bits.THR_CUBE_3=0;
        spi_bits.THR_CUBE_2=0;
        spi_bits.THR_CUBE_1=1;
        spi_bits.THR_CUBE_0=0;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="1.59 V")
    {
        spi_bits.THR_CUBE_3=0;
        spi_bits.THR_CUBE_2=0;
        spi_bits.THR_CUBE_1=1;
        spi_bits.THR_CUBE_0=1;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="1.7 V")
    {
        spi_bits.THR_CUBE_3=0;
        spi_bits.THR_CUBE_2=1;
        spi_bits.THR_CUBE_1=0;
        spi_bits.THR_CUBE_0=0;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="1.87 V")
    {
        spi_bits.THR_CUBE_3=0;
        spi_bits.THR_CUBE_2=1;
        spi_bits.THR_CUBE_1=0;
        spi_bits.THR_CUBE_0=1;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="2 V")
    {
        spi_bits.THR_CUBE_3=0;
        spi_bits.THR_CUBE_2=1;
        spi_bits.THR_CUBE_1=1;
        spi_bits.THR_CUBE_0=0;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="2.16 V")
    {
        spi_bits.THR_CUBE_3=0;
        spi_bits.THR_CUBE_2=1;
        spi_bits.THR_CUBE_1=1;
        spi_bits.THR_CUBE_0=1;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="2.32 V")
    {
        spi_bits.THR_CUBE_3=1;
        spi_bits.THR_CUBE_2=0;
        spi_bits.THR_CUBE_1=0;
        spi_bits.THR_CUBE_0=0;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="2.46 V")
    {
        spi_bits.THR_CUBE_3=1;
        spi_bits.THR_CUBE_2=0;
        spi_bits.THR_CUBE_1=0;
        spi_bits.THR_CUBE_0=1;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="2.6 V")
    {
        spi_bits.THR_CUBE_3=1;
        spi_bits.THR_CUBE_2=0;
        spi_bits.THR_CUBE_1=1;
        spi_bits.THR_CUBE_0=0;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="2.74 V")
    {
        spi_bits.THR_CUBE_3=1;
        spi_bits.THR_CUBE_2=0;
        spi_bits.THR_CUBE_1=1;
        spi_bits.THR_CUBE_0=1;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="2.89 V")
    {
        spi_bits.THR_CUBE_3=1;
        spi_bits.THR_CUBE_2=1;
        spi_bits.THR_CUBE_1=0;
        spi_bits.THR_CUBE_0=0;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="3.03 V")
    {
        spi_bits.THR_CUBE_3=1;
        spi_bits.THR_CUBE_2=1;
        spi_bits.THR_CUBE_1=0;
        spi_bits.THR_CUBE_0=1;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="3.17 V")
    {
        spi_bits.THR_CUBE_3=1;
        spi_bits.THR_CUBE_2=1;
        spi_bits.THR_CUBE_1=1;
        spi_bits.THR_CUBE_0=0;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }
    if(ui->THR_CUBE->currentText()=="3.29 V")
    {
        spi_bits.THR_CUBE_3=1;
        spi_bits.THR_CUBE_2=1;
        spi_bits.THR_CUBE_1=1;
        spi_bits.THR_CUBE_0=1;

        qDebug()<<ui->THR_CUBE->currentText(); ui->logview->append(ui->THR_CUBE->currentText());
    }

    switch (ui->BE->currentIndex()) {
    case 0:
        spi_bits.BE_1=0; spi_bits.BE_2=0; spi_bits.BE_3=0; spi_bits.BE_4=0;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 1:
        spi_bits.BE_1=0; spi_bits.BE_2=0; spi_bits.BE_3=0; spi_bits.BE_4=1;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 2:
        spi_bits.BE_1=0; spi_bits.BE_2=0; spi_bits.BE_3=1; spi_bits.BE_4=0;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 3:
        spi_bits.BE_1=0; spi_bits.BE_2=0; spi_bits.BE_3=1; spi_bits.BE_4=1;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 4:
        spi_bits.BE_1=0; spi_bits.BE_2=1; spi_bits.BE_3=0; spi_bits.BE_4=0;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 5:
        spi_bits.BE_1=0; spi_bits.BE_2=1; spi_bits.BE_3=0; spi_bits.BE_4=1;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 6:
        spi_bits.BE_1=0; spi_bits.BE_2=1; spi_bits.BE_3=1; spi_bits.BE_4=0;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 7:
        spi_bits.BE_1=0; spi_bits.BE_2=1; spi_bits.BE_3=1; spi_bits.BE_4=1;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 8:
        spi_bits.BE_1=1; spi_bits.BE_2=0; spi_bits.BE_3=0; spi_bits.BE_4=0;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 9:
        spi_bits.BE_1=1; spi_bits.BE_2=0; spi_bits.BE_3=0; spi_bits.BE_4=1;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 10:
        spi_bits.BE_1=1; spi_bits.BE_2=0; spi_bits.BE_3=1; spi_bits.BE_4=0;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 11:
        spi_bits.BE_1=1; spi_bits.BE_2=0; spi_bits.BE_3=1; spi_bits.BE_4=1;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 12:
        spi_bits.BE_1=1; spi_bits.BE_2=1; spi_bits.BE_3=0; spi_bits.BE_4=0;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 13:
        spi_bits.BE_1=1; spi_bits.BE_2=1; spi_bits.BE_3=0; spi_bits.BE_4=1;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 14:
        spi_bits.BE_1=1; spi_bits.BE_2=1; spi_bits.BE_3=1; spi_bits.BE_4=0;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    case 15:
        spi_bits.BE_1=1; spi_bits.BE_2=1; spi_bits.BE_3=1; spi_bits.BE_4=1;
        qDebug()<<"Channel "<<ui->BE->currentText(); ui->logview->append("Channel "+ ui->BE->currentText());
        break;
    default:
        break;
    }



    spi_bits.create_bitstream();
    ui->logview->append(QByteArray(reinterpret_cast<char *>(spi_bits.bit_stream),43).toHex());
    ui->progressBar->setValue(10);


    FT_HANDLE ftHandle;
    FT_STATUS res;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    DWORD num;
    UCHAR LatencyTimer = 2; //our default setting is 16


    DWORD RxBytes=25; //numero bytes ricevuti
    DWORD TxBytes=0; //numero bytes trasmessi
    //unsigned char division = 100/(2* ui->lineEdit->text().toUInt()) - 1;

    uint8_t rom_on[8]= {'C','O','M','M','A','N','D','R'};
    uint8_t rom_off[8]= {'C','O','M','M','A','N','D','T'};
    uint8_t TxBuffer_prog[50]= {'C','O','M','M','A','N','D','P'};
    char TxBuffer_sprog[8]= {'C','O','M','M','A','N','D','Q'};

    for (int i=8;i<51;i++)
    {
        TxBuffer_prog[i]=spi_bits.bit_stream[i-8];
         ui->progressBar->setValue(20);
    }

    res = FT_CreateDeviceInfoList(&num);

    if(res == FT_OK)
    {
        ui->logview->append( QString::number(num) + " connected FTDI devices.");

        if(num > 0)
        {
            devInfo = static_cast <FT_DEVICE_LIST_INFO_NODE*>(malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*num));
            res = FT_GetDeviceInfoList(devInfo, &num);
            //qDebug()<<devInfo[1].Description;

            if(num >1)
            {
                char description[]="Kerberos";
                res = FT_OpenEx(description,FT_OPEN_BY_DESCRIPTION, &ftHandle);
                //qDebug()<<"Entrato";
                //qDebug()<<res;
            }
            else
                res = FT_Open(0,&ftHandle);
        }
    }


    res= FT_Purge (ftHandle, FT_PURGE_RX | FT_PURGE_TX);
    //qDebug()<<res;
    ui->logview->append(QString::number(res));
    res =FT_SetBaudRate(ftHandle, FT_BAUD_9600);
    res= FT_SetDataCharacteristics(ftHandle,FT_BITS_8,FT_STOP_BITS_1,FT_PARITY_NONE);
    res = FT_SetBitMode(ftHandle,0xff, 0x40);
    res = FT_SetLatencyTimer(ftHandle, LatencyTimer);
    res = FT_SetUSBParameters(ftHandle, 0x10000, 0x10000);
    res = FT_SetFlowControl(ftHandle, FT_FLOW_RTS_CTS, 0x0, 0x0);
    res =FT_ClrDtr(ftHandle);
    res= FT_SetDtr(ftHandle);
    res= FT_Purge (ftHandle, FT_PURGE_RX | FT_PURGE_TX);

    res = FT_Write(ftHandle,TxBuffer_sprog,sizeof(TxBuffer_sprog),&TxBytes);
        if(res == FT_OK)
        {
            qDebug()<<" SPROG Write Ok, transmitted bytes:  "<<TxBytes;
            ui->logview->append("SPROG Write Ok, transmitted bytes:  " + QString::number(TxBytes));
        }
        else
        {
            qDebug()<<" SPROG Write failed!";
            ui->logview->append("SPROG Write failed!");
        }

    res= FT_Purge (ftHandle, FT_PURGE_RX | FT_PURGE_TX);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    res = FT_Write(ftHandle,TxBuffer_prog,sizeof(TxBuffer_prog),&TxBytes);
        if(res == FT_OK)
        {
            qDebug()<<" PROG Write Ok, transmitted bytes:  "<<TxBytes;
            ui->logview->append("PROG Write Ok, transmitted bytes:  " +QString::number(TxBytes));
            ui->progressBar->setValue(100);
        }
        else
        {
            qDebug()<<" PROG Write failed!";
            ui->logview->append("PROG Write failed!");
        }

    res= FT_Purge (ftHandle, FT_PURGE_RX | FT_PURGE_TX);

    FT_Close(ftHandle);

}



Program_tab::~Program_tab()
{
    delete ui;
}


