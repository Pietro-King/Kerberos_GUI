#include "acquire.h"
#include "ui_acquire.h"

Acquire::Acquire(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Acquire)
{
    ui->setupUi(this);
}

Acquire::~Acquire()
{
    delete ui;
}

void Acquire::start()
{
     qDebug()<< "iniziata acquisizione";

     FILE * pFile;
     FILE * rFile;
     FT_HANDLE ftHandle;
     FT_STATUS res;
     DWORD num;
     FT_DEVICE_LIST_INFO_NODE *devInfo;
     UCHAR LatencyTimer = 2; //our default setting is 16

     DWORD RxBytes=10000; //numero bytes ricevuti
     DWORD TxBytes=bytes_num; //numero bytes trasmessi
     DWORD numDevs;
     DWORD bytes_in_queue;

     res = FT_CreateDeviceInfoList(&num);
    queue_num=0;
     if(res == FT_OK)
     {
         if(num > 0)
         {
             devInfo = static_cast <FT_DEVICE_LIST_INFO_NODE*>(malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*num));
             res = FT_GetDeviceInfoList(devInfo, &num);

             if(num >1)
             {
                 char description[]="Kerberos";
                 res = FT_OpenEx(description,FT_OPEN_BY_DESCRIPTION, &ftHandle);
             }
             else
                 res = FT_Open(0,&ftHandle);
         }
     }
     res= FT_Purge (ftHandle, FT_PURGE_RX | FT_PURGE_TX);
     qDebug ()<<res;

     // OPEN DEVICE
     if(res==FT_OK)
     {
         qDebug()<< "device found and opened   ";
     }
     else
     {
         qDebug ()<< "ALARM no device found";
     }

     // SET PARAMETERS
     res = FT_SetBitMode(ftHandle,0xff, 0x40);
     res = FT_SetLatencyTimer(ftHandle, LatencyTimer);
     res = FT_SetUSBParameters(ftHandle, 0x10000, 0x10000);
     res = FT_SetFlowControl(ftHandle, FT_FLOW_RTS_CTS, 0x0, 0x0);

     res =FT_ClrDtr(ftHandle);
     res= FT_SetDtr(ftHandle);

     std::string binfile=dirname+"/"+filename+".bin";
     pFile = fopen ( binfile.c_str(), "w+b");
     rFile = fopen ( binfile.c_str(), "w+b");

    RxBuffer_char= new unsigned char[DIM_QUEUE];
    queue_num=0;

     res = FT_Write(ftHandle,TxBuffer_start,sizeof(TxBuffer_start),&TxBytes);

     if(TxBytes==8)
     {
        qDebug()<<"Start Acquisition";
     }
     acquisition_flag=1;

     while(acquisition_flag==1)
     {
         FT_GetQueueStatus (ftHandle, &bytes_in_queue); //scrive in bytes_in_queue il numero di bytes sul buffer di ricezione

         if(bytes_in_queue>=1000)
         {
             res = FT_Read(ftHandle,RxBuffer_char,bytes_in_queue,&RxBytes); //leggo il buffer di ricezione e lo scrive in RxBuffer
             fwrite(RxBuffer_char, bytes_in_queue*sizeof(char),1,pFile);
             queue_num= queue_num+bytes_in_queue;
         }
     }

     qDebug()<<queue_num;

     res = FT_Write(ftHandle,TxBuffer_stop,sizeof(TxBuffer_stop),&TxBytes);
     if(TxBytes==8)
     {
         qDebug()<<"Acquisition ended";
     }
         qDebug()<<"";
         qDebug()<<"";
     FT_Close(ftHandle);
     fclose(pFile);

}


void Acquire::stop()
{
    acquisition_flag=0;
    realtime_flag=0;
}

void Acquire::getFileNames(std::string a,std::string b)
{

    filename=a;
    dirname=b;

}

double Acquire::getBytesAcquired()
{

    return queue_num;
}


void Acquire::realtimePlot_call()
{
    realtime_flag=1;

    while(realtime_flag==1)
    {
        qDebug()<<"entrato2";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        int realtime_sfera=1;
        int realtime_channel=10;

        emit refresh_plot(realtime_channel,realtime_sfera);
    }

}
