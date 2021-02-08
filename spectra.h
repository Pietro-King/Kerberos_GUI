#ifndef SPECTRA_H
#define SPECTRA_H

#include <QWidget>
#include <acquire.h>
#include <QFuture>
#include <QtConcurrent/QtConcurrentRun>
#include <QtConcurrent/QtConcurrent>
#include <stdio.h>
#include <string>
#include <vector>
#include <QVector>
#include <iostream>
#include <QMessageBox>
#include <QInputDialog>


namespace Ui {
class Spectra;
}

class Spectra : public QWidget
{
    Q_OBJECT

public:
    explicit Spectra(QWidget *parent = 0);
    std::string filename;
    std::string dirname;
    int tristate_button=0;
    double bytesaquired;
    //Acquire acquisition;
    int realtime_sfera;
    int realtime_channel;
    long temp_spectra[16384];
    int temp_bin=0;
    int cifra_old=0;
    int cifra_new=0;
    QVector<double> x_rt,y_rt;
    std::array < std::array <double,16384>,17> spectra1_rt;
    std::array < std::array <double,16384>,17> spectra2_rt;
    std::array < std::array <double,16384>,17> spectra3_rt;

    int real_time_called=0;





    //parte di acq
    double queue_num=0;

    int acquisition_flag=0;
    int realtime_flag=0;

    char TxBuffer_start[bytes_num]= {'C','O','M','M','A','N','D','X'};
    char TxBuffer_stop[bytes_num]= {'C','O','M','M','A','N','D','@'};
    double num_of_samples;


    //


    unsigned int *temp; //cambiato in int per avere 32 bit
    unsigned int *canale;
    unsigned int *timestamp;
    unsigned int *valore;
    unsigned int *sfera_address;
    unsigned char *buffer_memory_char;
    unsigned char *RxBuffer_char;

    unsigned int *no_timestamp;
    float volt;
    int j=0;
    long long count=1;
    FILE * pFile_write_01;
    FILE * pFile_write_02;
    FILE * pFile_write_03;
    FILE * pFile_write_04;
    FILE * pFile_write_05;
    FILE * pFile_write_06;
    FILE * pFile_write_07;
    FILE * pFile_write_08;
    FILE * pFile_write_09;
    FILE * pFile_write_10;
    FILE * pFile_write_11;
    FILE * pFile_write_12;
    FILE * pFile_write_13;
    FILE * pFile_write_14;
    FILE * pFile_write_15;
    FILE * pFile_write_16;
    FILE * pFile_write_17;
    FILE * pFile_write_18;
    FILE * pFile_write_19;
    FILE * pFile_write_20;
    FILE * pFile_write_21;
    FILE * pFile_write_22;
    FILE * pFile_write_23;
    FILE * pFile_write_24;
    FILE * pFile_write_25;
    FILE * pFile_write_26;
    FILE * pFile_write_27;
    FILE * pFile_write_28;
    FILE * pFile_write_29;
    FILE * pFile_write_30;
    FILE * pFile_write_31;
    FILE * pFile_write_32;
    FILE * pFile_write_33;
    FILE * pFile_write_34;
    FILE * pFile_write_35;
    FILE * pFile_write_36;
    FILE * pFile_write_37;
    FILE * pFile_write_38;
    FILE * pFile_write_39;
    FILE * pFile_write_40;
    FILE * pFile_write_41;
    FILE * pFile_write_42;
    FILE * pFile_write_43;
    FILE * pFile_write_44;
    FILE * pFile_write_45;
    FILE * pFile_write_46;
    FILE * pFile_write_47;
    FILE * pFile_write_48;
    FILE * pFile_timestamp;
    FILE * pFile_read;

    ~Spectra();

    void realtimePlot_call();
    void acquire();
    void stop();
    void rt_spectra_creation(unsigned char *RxBuffer_char,int numbytes);

signals:
    void refresh_plot();

private slots:
    void on_start_clicked();

    void on_convert_clicked();

    void on_set_file_clicked();

    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void realtimePlot();

private:
    Ui::Spectra *ui;
};

#endif // SPECTRA_H
