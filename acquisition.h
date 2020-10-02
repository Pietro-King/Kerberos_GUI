#ifndef ACQUISITION_H
#define ACQUISITION_H


#include <Windows.h>
#include <ftd2xx.h>
#include <chrono>
#include <thread>
#include <QDebug>

#define bytes_num 8
#define DIM_QUEUE 300000
#define _FILE_OFFSET_BITS 64 //in order to be able to read file larger than 2GB

class acquisition;

class acquisition:public QObject
{

    Q_OBJECT

public:
    explicit acquisition(QObject *parent= 0);

    std::string filename;
    std::string dirname;
    double queue_num=0;
    unsigned char *RxBuffer_char;
    int acquisition_flag=0;
    int realtime_flag=0;

    char TxBuffer_start[bytes_num]= {'C','O','M','M','A','N','D','X'};
    char TxBuffer_stop[bytes_num]= {'C','O','M','M','A','N','D','@'};
    double num_of_samples;


    void start();
    void stop();
    void getFileNames(std::string a,std::string b);
    double getBytesAcquired();
    void realtimePlot_call();


signals:
    void refresh_plot(int realtime_channel_a, int realtime_sfera_a);


};

#endif // ACQUISITION_H
