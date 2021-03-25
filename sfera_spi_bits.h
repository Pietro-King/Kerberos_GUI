#ifndef SFERA_SPI_BITS_H
#define SFERA_SPI_BITS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
class Sfera_SPI_bits
{
public:
    Sfera_SPI_bits();
    create_bitstream();
    uint8_t bit_stream[43];
    //BYTE 0
    bool SEL_TIPO_MUX; //0 sparse, 1 polling
    bool SEL_MUX_1=0;//16:1 MODALITY
    bool SEL_MUX_2=0;
    bool SEL_GAMMA; //0 disabled, 1 gamma enabled
    bool SEL_EX_TRIGGER=0;//i dont use reset_cube pad
    bool EN_OPEN_DRAIN=0; //i'm not using other chips
    bool ADJF=0;//gain adj fast shaper
    bool ADJ_0; //gain adj main shaper. each one adds 200fF
    //BYTE 1
    bool ADJ_1;
    bool ADJ_2;
    bool ADJ_3;
    bool GAIN_1;//shaper gain. in the GUI hard code the combinations
    bool GAIN_2;
    bool GAIN_3;
    bool GAIN_4;
    bool SEL_2; //peaking time. hard code
    //BYTE 2
    bool SEL_1;
    bool SEL_0;
    bool T_PW_0=1; //preamp reset logic. change in sparse   //18_06
    bool T_PW_1=0; //preamp reset logic. change in sparse
    bool EN_CHANNEL_GND_N; //0 in sparse 1 in others
    bool EN_SEL_17 =0; //17th mux
    bool PILEUP_CORR =1; //always 1
    bool KILL_LOGICA_GAMMA_B; //another control for the mode of operation. set high to use gamma
    //BYTE 3
    bool TH_REAL_3; //reference for the first shaper out. hard coded
    bool TH_REAL_2;//default value for the moment
    bool TH_REAL_1;
    bool TH_REAL_0;
    bool PKS_MIRROR_3;//reference for the peak strecher
    bool PKS_MIRROR_2;//2.94 to 3.12
    bool PKS_MIRROR_1;
    bool PKS_MIRROR_0;
    //BYTE 4
    bool I_REF_SCARICA_PKS_3; //peak stretcher discharging
    bool I_REF_SCARICA_PKS_2; //3.5 - 10.16 - 20 - 30 - 36
    bool I_REF_SCARICA_PKS_1;
    bool I_REF_SCARICA_PKS_0;
    bool REF_PKS_3;//peak stretcher current reference
    bool REF_PKS_2;// 3.3 9.5
    bool REF_PKS_1;
    bool REF_PKS_0;
    //BYTE 5
    bool POL_SH_2=0;//blh reference //default
    bool POL_SH_1=0;
    bool POL_SH_0=1;
    bool BLH_OHM_FAST_5=0;//dafult. never change//18_06
    bool BLH_OHM_FAST_4=1;
    bool BLH_OHM_FAST_3=0;
    bool BLH_OHM_FAST_2=0;
    bool BLH_OHM_FAST_1=0;
    //BYTE 6
    bool BLH_OHM_FAST_0=0;
    bool BLH_OHM_MAIN_5=0;//should be hardcoded with peaking time-otherwise use the 2.5 option
    bool BLH_OHM_MAIN_4=1;
    bool BLH_OHM_MAIN_3=0;
    bool BLH_OHM_MAIN_2=0;
    bool BLH_OHM_MAIN_1=0;
    bool BLH_OHM_MAIN_0=0;
    bool I_MONO_TR_DELAY_2=0;//default
    //BYTE 7
    bool I_MONO_TR_DELAY_1=1;
    bool I_MONO_TR_DELAY_0=1;
    bool LARG_RESET_2;//default 011  //18_06
    bool LARG_RESET_1;
    bool LARG_RESET_0;
    bool I_MONO_PKS_PHASE_2;//default
    bool I_MONO_PKS_PHASE_1;
    bool I_MONO_PKS_PHASE_0;
    //BYTE 8
    bool LARG_INHIBIT_2;//default 011, but change in sparse //18_06 100 in gamma
    bool LARG_INHIBIT_1;
    bool LARG_INHIBIT_0;
    bool I_MONO_T2_2=0;//default
    bool I_MONO_T2_1=1;
    bool I_MONO_T2_0=1;
    bool I_MONO_CLR_2=0;//ask
    bool I_MONO_CLR_1=1;
    //BYTE 9
    bool I_MONO_CLR_0=1;
    bool DAC_OFFSET_5; //496 to 634
    bool DAC_OFFSET_4;
    bool DAC_OFFSET_3;
    bool DAC_OFFSET_2;
    bool DAC_OFFSET_1;
    bool DAC_OFFSET_0;
    bool BLH_POLO_1u_5;//default
    //BYTE 10
    bool BLH_POLO_1u_4;
    bool BLH_POLO_1u_3;
    bool BLH_POLO_1u_2;
    bool BLH_POLO_1u_1;
    bool BLH_POLO_1u_0;
    bool BLH_SLEW_RATE_1u_5;//default
    bool BLH_SLEW_RATE_1u_4;
    bool BLH_SLEW_RATE_1u_3;
    //BYTE 11
    bool BLH_SLEW_RATE_1u_2;
    bool BLH_SLEW_RATE_1u_1;
    bool BLH_SLEW_RATE_1u_0;
    bool DAC_OFFSET_FAST_5;//496 to 606
    bool DAC_OFFSET_FAST_4;
    bool DAC_OFFSET_FAST_3;
    bool DAC_OFFSET_FAST_2;
    bool DAC_OFFSET_FAST_1;
    //BYTE 12
    bool DAC_OFFSET_FAST_0;
    bool THR_CUBE_3=1;//default
    bool THR_CUBE_2=0;
    bool THR_CUBE_1=1;
    bool THR_CUBE_0=0;
    bool EN_REF_EXT;// . 0 internal ref, 1 external reference
    bool BIT_SEL_FINE_MAIN=0; //default. step amplitude
    bool BIT_SEL_FINE_FAST=0; //default
    //BYTE 13 TO BIT 24 STUFF

    //BIT 25
    bool KILL_CH_B_1=1;//not killed channel
    bool KILL_CH_B_2=1;
    bool KILL_CH_B_3=1;
    bool KILL_CH_B_4=1;
    bool KILL_CH_B_5=1;
    bool KILL_CH_B_6=1;
    bool KILL_CH_B_7=1;
    bool KILL_CH_B_8=1;
    //BIT 26
    bool KILL_CH_B_9=1;
    bool KILL_CH_B_10=1;
    bool KILL_CH_B_11=1;
    bool KILL_CH_B_12=1;
    bool KILL_CH_B_13=1;
    bool KILL_CH_B_14=1;
    bool KILL_CH_B_15=1;
    bool KILL_CH_B_16=1;
    //BIT 27
    bool BIT_EN_EXT_SINGLE=0; //adc testing
    bool BIT_BUF_OUT_NOT_CONNECTED=0; //adc testing
    bool KILL_ADC_B=0; //adc  enabled
    bool ADD_DEL=1;//adc delay
    bool LATCH_DEL_1=1;
    bool LATCH_DEL_0=1;
    bool BE_1; //code of the selected channel to be seen at the main out
    bool BE_2;//programmable in the future
    //BIT 28
    bool BE_3;
    bool BE_4;
    bool NO_SELECT=0;//0 validates BE
    bool EN_DEAD_TIME_N=0;
    bool SEL_STESSO_PAD;//0 gamma, 1 sparse
    bool DISABLE_OUT_DIG_NEG=1;
    bool EN_HIGH_Z_LVDS_NEG; //18_06
    bool C_EXTRA_ON=0;//extra capacitance in the pks
   //BIT 29
        bool KILL_BUFFER_TESTS=0;
    bool KILL_LOGICA_X;//change based tyo the modality
    bool EN_RESET_ON_BOMBA=0;//to reset the cube in case of a high energy event
    bool ADC_TEST_EN=0;// adc
    bool DELAY_TR_IN_ON;//ASK wait for check
    bool HALF_DELAY_TR_IN;
    bool EN_AUTO_TRIGGER_GAMMA;//careful. look if u need tr_in
    bool SERIAL_OUT_ENABLE_NEG=0;
    //BIT 30
    bool PROG_CHECK_5=1;
    bool PROG_CHECK_4=0;
    bool PROG_CHECK_3=1;
    bool PROG_CHECK_2=0;
    bool PROG_CHECK_1=1;
    bool PROG_CHECK_0=0;

    bool BIT_247=1;
    bool BIT_248=1;
    bool BIT_249=1;
    bool BIT_250=1;
    bool BIT_251=1;
    bool BIT_252=1;
    bool BIT_253=1;
    bool BIT_254=1;
    bool BIT_255=0;
    bool BIT_256=1;

    bool INH_DURATION_2=0;
    bool INH_DURATION_1=0;
    bool INH_DURATION_0=0;


private:

};

#endif // SFERA_SPI_BITS_H
