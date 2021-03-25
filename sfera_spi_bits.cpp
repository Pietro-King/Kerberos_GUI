#include "sfera_spi_bits.h"

Sfera_SPI_bits::Sfera_SPI_bits()
{

}

Sfera_SPI_bits::create_bitstream()
{
    uint8_t temp[43];

    temp[0]=(SEL_TIPO_MUX<<7) |(SEL_MUX_1<<6) | SEL_MUX_2<<5 |  SEL_GAMMA<<4 |SEL_EX_TRIGGER<<3 | EN_OPEN_DRAIN<<2 | ADJF<<1 | ADJ_0;
    temp[1]=ADJ_1<<7 |ADJ_2<<6 |ADJ_3<<5 |GAIN_1<<4 |GAIN_2<<3 |GAIN_3<<2 |GAIN_4<<1 | SEL_2;
    temp[2]=SEL_1<<7 |SEL_0<<6 |T_PW_0<<5 |T_PW_1<<4 |EN_CHANNEL_GND_N<<3 |EN_SEL_17<<2 |PILEUP_CORR<<1 |KILL_LOGICA_GAMMA_B ;
    temp[3]=TH_REAL_3<<7 |TH_REAL_2<<6 |TH_REAL_1<<5 |TH_REAL_0<<4 |PKS_MIRROR_3<<3 |PKS_MIRROR_2<<2 |PKS_MIRROR_1<<1 |PKS_MIRROR_0;
    temp[4]=I_REF_SCARICA_PKS_3<<7 |I_REF_SCARICA_PKS_2<<6 |I_REF_SCARICA_PKS_1<<5 |I_REF_SCARICA_PKS_0<<4 |REF_PKS_3<<3 |REF_PKS_2<<2 |REF_PKS_1<<1 |REF_PKS_0 ;
    temp[5]=POL_SH_2<<7 |POL_SH_1<<6 |POL_SH_0<<5 |BLH_OHM_FAST_5<<4 |BLH_OHM_FAST_4<<3 |BLH_OHM_FAST_3<<2 |BLH_OHM_FAST_2<<1 |BLH_OHM_FAST_1 ;
    temp[6]=BLH_OHM_FAST_0<<7 |BLH_OHM_MAIN_5<<6 |BLH_OHM_MAIN_4<<5 |BLH_OHM_MAIN_3<<4 |BLH_OHM_MAIN_2<<3 |BLH_OHM_MAIN_1<<2 |BLH_OHM_MAIN_0<<1 |I_MONO_TR_DELAY_2 ;
    temp[7]=I_MONO_TR_DELAY_1<<7 |I_MONO_TR_DELAY_0<<6 |LARG_RESET_2<<5 |LARG_RESET_1<<4 |LARG_RESET_0<<3 |I_MONO_PKS_PHASE_2<<2 |I_MONO_PKS_PHASE_1<<1 |I_MONO_PKS_PHASE_0 ;
    temp[8]=LARG_INHIBIT_2<<7 |LARG_INHIBIT_1<<6 |LARG_INHIBIT_0<<5 |I_MONO_T2_2<<4 |I_MONO_T2_1<<3 |I_MONO_T2_0<<2 |I_MONO_CLR_2<<1 |I_MONO_CLR_1 ;
    temp[9]=I_MONO_CLR_0<<7 |DAC_OFFSET_5<<6 |DAC_OFFSET_4<<5 |DAC_OFFSET_3<<4 |DAC_OFFSET_2<<3 |DAC_OFFSET_1<<2 |DAC_OFFSET_0<<1 |BLH_POLO_1u_5 ;
    temp[10]=BLH_POLO_1u_4<<7 |BLH_POLO_1u_3<<6 |BLH_POLO_1u_2<<5 |BLH_POLO_1u_1<<4 |BLH_POLO_1u_0<<3 |BLH_SLEW_RATE_1u_5<<2 |BLH_SLEW_RATE_1u_4<<1 |BLH_SLEW_RATE_1u_3 ;
    temp[11]=BLH_SLEW_RATE_1u_2<<7 |BLH_SLEW_RATE_1u_1<<6 |BLH_SLEW_RATE_1u_0<<5 |DAC_OFFSET_FAST_5<<4 |DAC_OFFSET_FAST_4<<3 |DAC_OFFSET_FAST_3<<2 |DAC_OFFSET_FAST_2<<1 |DAC_OFFSET_FAST_1 ;
    temp[12]=DAC_OFFSET_FAST_0<<7 |THR_CUBE_3<<6 |THR_CUBE_2<<5 |THR_CUBE_1<<4 |THR_CUBE_0<<3 |EN_REF_EXT<<2 |BIT_SEL_FINE_MAIN<<1 |BIT_SEL_FINE_FAST;


    temp[13]=0;
    temp[14]=0;
    temp[15]=0;
    temp[16]=0;
    temp[17]=0;
    temp[18]=0;
    temp[19]=0;
    temp[20]=0;
    temp[21]=0;
    temp[22]=0;
    temp[23]=0;
    temp[24]=0;

    temp[25]=KILL_CH_B_1<<7 |KILL_CH_B_2<<6 |KILL_CH_B_3<<5 |KILL_CH_B_4<<4 |KILL_CH_B_5<<3 |KILL_CH_B_6<<2 |KILL_CH_B_7<<1 | KILL_CH_B_8;
    temp[26]=KILL_CH_B_9<<7 |KILL_CH_B_10<<6 |KILL_CH_B_11<<5 |KILL_CH_B_12<<4 |KILL_CH_B_13<<3 |KILL_CH_B_14<<2 |KILL_CH_B_15<<1 | KILL_CH_B_16;
    temp[27]=BIT_EN_EXT_SINGLE<<7 |BIT_BUF_OUT_NOT_CONNECTED<<6 |KILL_ADC_B<<5 |ADD_DEL<<4 |LATCH_DEL_1<<3 |LATCH_DEL_0<<2 |BE_1<<1 |BE_2 ;
    temp[28]=BE_3<<7 |BE_4<<6 |NO_SELECT<<5 |EN_DEAD_TIME_N<<4 |SEL_STESSO_PAD<<3 |DISABLE_OUT_DIG_NEG<<2 |EN_HIGH_Z_LVDS_NEG<<1 |C_EXTRA_ON ;
    temp[29]=KILL_BUFFER_TESTS<<7 |KILL_LOGICA_X<<6 |EN_RESET_ON_BOMBA<<5 |ADC_TEST_EN<<4 |DELAY_TR_IN_ON<<3 |HALF_DELAY_TR_IN<<2 |EN_AUTO_TRIGGER_GAMMA<<1 |SERIAL_OUT_ENABLE_NEG ;
    temp[30]=PROG_CHECK_5<<7 |PROG_CHECK_4<<6 |PROG_CHECK_3<<5 |PROG_CHECK_2<<4 |PROG_CHECK_1<<3 |PROG_CHECK_0<<2 |BIT_247<<1 | BIT_248 ;
    temp[31]=BIT_249<<7 | BIT_250<<6 | BIT_251<<5 |BIT_252<<4 | BIT_253<<3 | BIT_254<<2 | BIT_255<<1 |BIT_256;

    temp[32]=INH_DURATION_2<<7 |INH_DURATION_1<<6 |INH_DURATION_0<<5 |bool(0)<<4 |bool(0)<<3 |bool(0)<<2 |bool(0)<<1 |bool(0);
    temp[33]=0;
    temp[34]=0;
    temp[35]=0;
    temp[36]=0;
    temp[37]=0;
    temp[38]=0;
    temp[39]=0;
    temp[40]=0;
    temp[41]=0;

    temp[42]=1;//finishing character



    for (int i=0;i<43;i++)
    {
        bit_stream[i]=temp[i];
    }
    return 0;

}
