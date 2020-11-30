#include "frame_checker.h"
#include "ui_frame_checker.h"

frame_checker::frame_checker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frame_checker)
{
    ui->setupUi(this);
}

frame_checker::~frame_checker()
{
    delete ui;
}

void frame_checker::on_pushButton_clicked()
{
    std::string filename="C:/Users/Tesista/OneDrive - Politecnico di Milano/Tristan/Pietro King/Misure/20201123_Kerb_inhibit_test_ardesia/missing events/long_00000002.bin";
    FILE* pFile;
    pFile = fopen ( filename.c_str(), "rb");
    fseeko64 (pFile, 0 , SEEK_END);
    long long lSize = ftello64 (pFile);
    rewind (pFile);
    qDebug()<<lSize<<"bytes\n";
    int count=0;
    int j=0;
    unsigned int *temp; //cambiato in int per avere 32 bit
    unsigned int *canale;
    unsigned int *timestamp;
    unsigned int *valore;
    unsigned int *sfera_address;
    unsigned char *buffer_memory_char;

    temp= new unsigned int[1000];
    canale= new unsigned int[1000];
    timestamp= new unsigned int[1000];
    valore= new unsigned int[1000];
    sfera_address= new unsigned int[1000];
    buffer_memory_char= new unsigned char[1000];
    int comparison=1;
    int tracker=0;
    int intermedio=0;

    fread(buffer_memory_char,16,1,pFile);
    while(count<lSize/100)
    {
        j=0;
        fread(buffer_memory_char,1000,1,pFile);

        for(int i=0;i<1000;i+=4)
        {
            temp[j] = ((int(buffer_memory_char[i])<<24) | (int(buffer_memory_char[i+1]) <<16) |  (int(buffer_memory_char[i+2])<<8) |  (int(buffer_memory_char[i+3])));

            sfera_address[j]=temp[j]>>24;
            canale[j]=temp[j]<<8;
            canale[j]=canale[j]>>24;
            valore[j]=temp[j]<<16;
            valore[j]=valore[j]>>18;  //rebinning da 16 a 14bit


            if(tracker==3)
                comparison++;
            if(tracker==6)
                comparison++;
            if(tracker==9)
                comparison++;
            if(tracker==12)
                comparison++;
            if(tracker==15)
                comparison++;

            if(tracker==20)
                comparison++;
            if(tracker==23)
                comparison++;
            if(tracker==26)
                comparison++;
            if(tracker==29)
                comparison++;
            if(tracker==32)
                comparison++;
            if(tracker==35)
                comparison++;
            if(tracker==38)
                comparison++;
            if(tracker==41)
                comparison++;
            if(tracker==44)
                comparison++;
            if(tracker==47)
                comparison++;
            if(tracker==50)
            {
                comparison=1;
                tracker=0;
            }

            if(tracker!=15 && tracker!=16)
            {
            intermedio=canale[j]-comparison;
            if (intermedio!=0)
                qDebug()<<intermedio;
            }

            tracker++;

            j++;
        }
        count++;
    }
    qDebug()<<"finito";
}
