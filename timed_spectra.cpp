#include "timed_spectra.h"
#include "ui_timed_spectra.h"

timed_spectra::timed_spectra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::timed_spectra)
{
    ui->setupUi(this);

    ui->lcd_display->setDigitCount(9);
    ui->lcd_display->setFixedSize(185, 100);
    ui->lcd_display->display(ui->lcd_display->timeValue->toString("HH:mm:ss"));

    ui->widget->addGraph();
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget_2->addGraph();
    ui->widget_2->setInteraction(QCP::iRangeDrag, true);
    ui->widget_2->setInteraction(QCP::iRangeZoom, true);

    QObject::connect(this,SIGNAL(refresh_plot()),this,SLOT(realtimePlot()));


    QSettings setting("MyComp","MyApp");
    setting.beginGroup("Filenames");
    ui->file_name->setText(setting.value("1").toString());
    ui->directory_name->setText(setting.value("2").toString());
    setting.endGroup();
    x_rt.resize(16384);
    y_rt.resize(16384);


    ui->spin_repetitions->setValue(1);
    ui->spin_repetitions->setRange(1,1000000);
    ui->spin_h->setMaximum(23);
    ui->spin_m->setMaximum(59);
    ui->spin_s->setMaximum(59);
    ui->spin_delay_rep->setMinimum(2);
    ui->spin_delay_rep->setMaximum(1000000);
    ui->lcd_display->forward_reverse=1;

    ui->set_file->setVisible(false);
    ui->set_time->setVisible(true);
    ui->set_time->setText("Set time");
    ui->set_repetitions->setVisible(false);
    ui->pushButton_2->setVisible(false);

    timer_start = new QTimer();

    QObject::connect(timer_start,SIGNAL(timeout()),this,SLOT(startstopreset_repetionsFunction()));


    for (int i=0; i<16384; ++i)
    {
        x_rt[i] = i;
        y_rt[i] = 0;
    }

    for (int x=0;x<17;x++)
        for(int y=0;y<16384;y++)
        {
            spectra1_rt[x][y]=0;
            spectra2_rt[x][y]=0;
            spectra3_rt[x][y]=0;
        }
    filename=ui->file_name->text().toStdString();
    dirname=ui->directory_name->text().toStdString();

}

timed_spectra::~timed_spectra()
{
    delete ui;
}

void timed_spectra::on_start_clicked()
{
    if (ui->lcd_display->timeValue->second() + ui->lcd_display->timeValue->minute()*60 + ui->lcd_display->timeValue->hour()*3600 !=0)
    {
        if(ui->overwrite_box->isChecked()==1 && filename==ui->file_name->text().toStdString() && dirname==ui->directory_name->text().toStdString() && repetion_counter<2)
        {
            switch( QMessageBox::question(
                        this,
                        tr("Overwriting File"),
                        tr("You are overwriting a previously created file. ")+ QString::fromStdString(dirname)+"/"+QString::fromStdString(filename) + tr(". Do you want to continue?."),

                        QMessageBox::Yes |
                        QMessageBox::No  ) )
            {
            case QMessageBox::Yes:
                break;
            case QMessageBox::No:
                return;
                break;
            default:
                return;
                break;
            }
        }

        filename=ui->file_name->text().toStdString();
        dirname=ui->directory_name->text().toStdString();
        QSettings setting("MyComp","MyApp");
        setting.beginGroup("Filenames");
        setting.setValue("1",ui->file_name->text());
        setting.setValue("2",ui->directory_name->text());
        setting.endGroup();

        on_set_repetitions_clicked();
        on_pushButton_2_clicked();

        time_of_measure=(ui->lcd_display->timeValue->second() + ui->lcd_display->timeValue->minute()*60 + ui->lcd_display->timeValue->hour()*3600)*1000;
        timer_start->start(10);
    }
    else
        ui->logger->append("Set a time value first!");
}


void timed_spectra::startstopresetFunction()
{

//    if (tristate_button==0)
//    {
//        if (ui->lcd_display->timeValue->second() + ui->lcd_display->timeValue->minute()*60 + ui->lcd_display->timeValue->hour()*3600 !=0)
//        {
//            ui->start->setText("Stop");
//            tristate_button=1;


//            ui->lcd_display->start_stop_reverse_lcdnumber();
//            ui->lcd_display->stopping_flag=0;
//            ui->logger->append("Acquisition " + QString::number(repetion_counter)+ " Started\n");
//            QFuture<void> reverse_timing_thread = QtConcurrent::run([&]{timing0stopper();});
//            QFuture<void> acq_thread = QtConcurrent::run([&]{acquire_timed();});
//            QFuture<void> rt_plot = QtConcurrent::run([&]{realtimePlot_call();});
//        }
//        else
//            ui->logger->append("Set a time value first!");

//    }
//    else if (tristate_button==1)
//    {
//            stop();
//            ui->start->setText("Reset");
//            ui->lcd_display->timer->stop();
//            ui->logger->append("Acquisition " + QString::number(repetion_counter)+ " Stopped\n"+"Acquired "+QString::number(queue_num)+" bytes\n"+QString::number(floor(queue_num/196))+" burst events (if using 3 SFERA)");
//            //ui->logger->append("Acquired "+QString::number(queue_num)+" bytes");
//            //ui->logger->append(QString::number(floor(queue_num/196))+" burst events (if using 3 SFERA)");
//            tristate_button=2;
//    }

//    else if (tristate_button==2)
//    {
//        ui->start->setText("Start");
//        tristate_button=0;
//        ui->lcd_display->timeValue->setHMS(ui->spin_h->value(),ui->spin_m->value(),ui->spin_s->value());
//        ui->lcd_display->display(ui->lcd_display->timeValue->toString("HH:mm:ss"));
//        ui->logger->append("Resetting");

//        for (int x=0;x<17;x++)
//            for(int y=0;y<16384;y++)
//            {
//                spectra1_rt[x][y]=0;
//                spectra2_rt[x][y]=0;
//                spectra3_rt[x][y]=0;
//            }
//    }
}

void timed_spectra::startstopreset_repetionsFunction()
{

    if (tristate_button==0)
    {
        rt_write=1;
        timer_start->stop();
        timer_start->start(time_of_measure);
        ui->start->setText("Start");
        tristate_button=1;
        ui->lcd_display->start_stop_reverse_lcdnumber();
        ui->logger->append("Acquisition " + QString::number(repetion_counter)+ " Started");
        ui->logger->append("Current time:"+ QDateTime::currentDateTime().toString()+"\n");
        QFuture<void> acq_thread = QtConcurrent::run([&]{acquire_timed();});
        QFuture<void> rt_plot = QtConcurrent::run([&]{realtimePlot_call();});
    }
    else if (tristate_button==1)
    {
        stop();
        timer_start->stop();
        ui->lcd_display->timer->stop();


        ui->start->setText("Start");
        ui->logger->append("Acquisition " + QString::number(repetion_counter)+ " Stopped");
        tristate_button=0;
        ui->lcd_display->timeValue->setHMS(ui->spin_h->value(),ui->spin_m->value(),ui->spin_s->value());
        ui->lcd_display->display(ui->lcd_display->timeValue->toString("HH:mm:ss"));

        for (int x=0;x<17;x++)
            for(int y=0;y<16384;y++)
            {
                spectra1_rt[x][y]=0;
                spectra2_rt[x][y]=0;
                spectra3_rt[x][y]=0;
            }



        repetion_counter++;

        if (repetion_counter <= num_of_repetitions)
        {
            timer_start->start(delay_rep*1000);
            ui->logger->append("Waiting " + QString::number(delay_rep)+ " seconds before next measuremnt.");
        }
        else
        {
            ui->logger->append("Measurement Finished");
            repetion_counter=1;
            rt_write=0;
        }

    }

}


void timed_spectra::timing0stopper()
{

    while(ui->lcd_display->stopping_flag==0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    if(tristate_button==1)
        on_start_clicked();
}

void timed_spectra::on_convert_clicked()
{

    long **bin = new long*[17];
    for(int i = 0; i < 17; ++i)
        bin[i] = new long[16384];
    for (int x=0;x<17;x++)
        for(int y=0;y<16384;y++)
            bin[x][y]=0;

    long **bin2 = new long*[17];
    for(int i = 0; i < 17; ++i)
        bin2[i] = new long[16384];
    for (int x=0;x<17;x++)
        for(int y=0;y<16384;y++)
            bin2[x][y]=0;

    long **bin3 = new long*[17];
    for(int i = 0; i < 17; ++i)
        bin3[i] = new long[16384];
    for (int x=0;x<17;x++)
        for(int y=0;y<16384;y++)
            bin3[x][y]=0;

    int timestamp_spectra[1024];
    for(int i=0;i<1024;i++)
        timestamp_spectra[i]=0;

    temp= new unsigned int[DIM_QUEUE];
    canale= new unsigned int[DIM_QUEUE];
    timestamp= new unsigned int[DIM_QUEUE];
    valore= new unsigned int[DIM_QUEUE];
    sfera_address= new unsigned int[DIM_QUEUE];
    buffer_memory_char= new unsigned char[DIM_QUEUE];
    RxBuffer_char= new unsigned char[DIM_QUEUE];
    int n_files_convert=0;
    std::string file_number_string_convert= std::string(8,'0');


    std::string binfile=dirname+"/"+filename+"_timed_"+file_number_string_convert+".bin";
    std::string txtfile01=dirname+"/"+filename+"_timed_01.txt";
    std::string txtfile02=dirname+"/"+filename+"_timed_02.txt";
    std::string txtfile03=dirname+"/"+filename+"_timed_03.txt";
    std::string txtfile04=dirname+"/"+filename+"_timed_04.txt";
    std::string txtfile05=dirname+"/"+filename+"_timed_05.txt";
    std::string txtfile06=dirname+"/"+filename+"_timed_06.txt";
    std::string txtfile07=dirname+"/"+filename+"_timed_07.txt";
    std::string txtfile08=dirname+"/"+filename+"_timed_08.txt";
    std::string txtfile09=dirname+"/"+filename+"_timed_09.txt";
    std::string txtfile10=dirname+"/"+filename+"_timed_10.txt";
    std::string txtfile11=dirname+"/"+filename+"_timed_11.txt";
    std::string txtfile12=dirname+"/"+filename+"_timed_12.txt";
    std::string txtfile13=dirname+"/"+filename+"_timed_13.txt";
    std::string txtfile14=dirname+"/"+filename+"_timed_14.txt";
    std::string txtfile15=dirname+"/"+filename+"_timed_15.txt";
    std::string txtfile16=dirname+"/"+filename+"_timed_16.txt";
    std::string txtfile17=dirname+"/"+filename+"_timed_17.txt";
    std::string txtfile18=dirname+"/"+filename+"_timed_18.txt";
    std::string txtfile19=dirname+"/"+filename+"_timed_19.txt";
    std::string txtfile20=dirname+"/"+filename+"_timed_20.txt";
    std::string txtfile21=dirname+"/"+filename+"_timed_21.txt";
    std::string txtfile22=dirname+"/"+filename+"_timed_22.txt";
    std::string txtfile23=dirname+"/"+filename+"_timed_23.txt";
    std::string txtfile24=dirname+"/"+filename+"_timed_24.txt";
    std::string txtfile25=dirname+"/"+filename+"_timed_25.txt";
    std::string txtfile26=dirname+"/"+filename+"_timed_26.txt";
    std::string txtfile27=dirname+"/"+filename+"_timed_27.txt";
    std::string txtfile28=dirname+"/"+filename+"_timed_28.txt";
    std::string txtfile29=dirname+"/"+filename+"_timed_29.txt";
    std::string txtfile30=dirname+"/"+filename+"_timed_30.txt";
    std::string txtfile31=dirname+"/"+filename+"_timed_31.txt";
    std::string txtfile32=dirname+"/"+filename+"_timed_32.txt";
    std::string txtfile33=dirname+"/"+filename+"_timed_33.txt";
    std::string txtfile34=dirname+"/"+filename+"_timed_34.txt";
    std::string txtfile35=dirname+"/"+filename+"_timed_35.txt";
    std::string txtfile36=dirname+"/"+filename+"_timed_36.txt";
    std::string txtfile37=dirname+"/"+filename+"_timed_37.txt";
    std::string txtfile38=dirname+"/"+filename+"_timed_38.txt";
    std::string txtfile39=dirname+"/"+filename+"_timed_39.txt";
    std::string txtfile40=dirname+"/"+filename+"_timed_40.txt";
    std::string txtfile41=dirname+"/"+filename+"_timed_41.txt";
    std::string txtfile42=dirname+"/"+filename+"_timed_42.txt";
    std::string txtfile43=dirname+"/"+filename+"_timed_43.txt";
    std::string txtfile44=dirname+"/"+filename+"_timed_44.txt";
    std::string txtfile45=dirname+"/"+filename+"_timed_45.txt";
    std::string txtfile46=dirname+"/"+filename+"_timed_46.txt";
    std::string txtfile47=dirname+"/"+filename+"_timed_47.txt";
    std::string txtfile48=dirname+"/"+filename+"_timed_48.txt";


    std::string txtfile_timestamp=dirname+"/"+filename+"_timed_timestamp.txt";



     pFile_timestamp = fopen(txtfile_timestamp.c_str(), "wb");
     pFile_write_01 = fopen ( txtfile01.c_str(), "wb");
     pFile_write_02 = fopen ( txtfile02.c_str(), "wb");
     pFile_write_03 = fopen ( txtfile03.c_str(), "wb");
     pFile_write_04 = fopen ( txtfile04.c_str(), "wb");
     pFile_write_05 = fopen ( txtfile05.c_str(), "wb");
     pFile_write_06 = fopen ( txtfile06.c_str(), "wb");
     pFile_write_07 = fopen ( txtfile07.c_str(), "wb");
     pFile_write_08 = fopen ( txtfile08.c_str(), "wb");
     pFile_write_09 = fopen ( txtfile09.c_str(), "wb");
     pFile_write_10 = fopen ( txtfile10.c_str(), "wb");
     pFile_write_11 = fopen ( txtfile11.c_str(), "wb");
     pFile_write_12 = fopen ( txtfile12.c_str(), "wb");
     pFile_write_13 = fopen ( txtfile13.c_str(), "wb");
     pFile_write_14 = fopen ( txtfile14.c_str(), "wb");
     pFile_write_15 = fopen ( txtfile15.c_str(), "wb");
     pFile_write_16 = fopen ( txtfile16.c_str(), "wb");
     pFile_write_17 = fopen ( txtfile17.c_str(), "wb");
     pFile_write_18 = fopen ( txtfile18.c_str(), "wb");
     pFile_write_19 = fopen ( txtfile19.c_str(), "wb");
     pFile_write_20 = fopen ( txtfile20.c_str(), "wb");
     pFile_write_21 = fopen ( txtfile21.c_str(), "wb");
     pFile_write_22 = fopen ( txtfile22.c_str(), "wb");
     pFile_write_23 = fopen ( txtfile23.c_str(), "wb");
     pFile_write_24 = fopen ( txtfile24.c_str(), "wb");
     pFile_write_25 = fopen ( txtfile25.c_str(), "wb");
     pFile_write_26 = fopen ( txtfile26.c_str(), "wb");
     pFile_write_27 = fopen ( txtfile27.c_str(), "wb");
     pFile_write_28 = fopen ( txtfile28.c_str(), "wb");
     pFile_write_29 = fopen ( txtfile29.c_str(), "wb");
     pFile_write_30 = fopen ( txtfile30.c_str(), "wb");
     pFile_write_31 = fopen ( txtfile31.c_str(), "wb");
     pFile_write_32 = fopen ( txtfile32.c_str(), "wb");
     pFile_write_33 = fopen ( txtfile33.c_str(), "wb");
     pFile_write_34 = fopen ( txtfile34.c_str(), "wb");
     pFile_write_35 = fopen ( txtfile35.c_str(), "wb");
     pFile_write_36 = fopen ( txtfile36.c_str(), "wb");
     pFile_write_37 = fopen ( txtfile37.c_str(), "wb");
     pFile_write_38 = fopen ( txtfile38.c_str(), "wb");
     pFile_write_39 = fopen ( txtfile39.c_str(), "wb");
     pFile_write_40 = fopen ( txtfile40.c_str(), "wb");
     pFile_write_41 = fopen ( txtfile41.c_str(), "wb");
     pFile_write_42 = fopen ( txtfile42.c_str(), "wb");
     pFile_write_43 = fopen ( txtfile43.c_str(), "wb");
     pFile_write_44 = fopen ( txtfile44.c_str(), "wb");
     pFile_write_45 = fopen ( txtfile45.c_str(), "wb");
     pFile_write_46 = fopen ( txtfile46.c_str(), "wb");
     pFile_write_47 = fopen ( txtfile47.c_str(), "wb");
     pFile_write_48 = fopen ( txtfile48.c_str(), "wb");


     qDebug()<<binfile.c_str();
     pFile_read = fopen (binfile.c_str(), "rb");

     while(pFile_read!=NULL)
     {

     ui->logger->append("Reading file"+QString::fromStdString(binfile));
     fseeko64 (pFile_read , 0 , SEEK_END);
     long long lSize = ftello64 (pFile_read);
     rewind (pFile_read);
     qDebug()<<lSize<<"byte da convertire\n";
     ui->logger->append(QString::number(lSize)+"Byte da convertire\n");
     count=0;
     while(count<lSize/100)
     {
         j=0;
         fread(buffer_memory_char,100,1,pFile_read);

         for(int i=0;i<100;i+=4)
         {
             temp[j] = ((int(buffer_memory_char[i])<<24) | (int(buffer_memory_char[i+1]) <<16) |  (int(buffer_memory_char[i+2])<<8) |  (int(buffer_memory_char[i+3])));

             sfera_address[j]=temp[j]>>24;
             canale[j]=temp[j]<<8;
             canale[j]=canale[j]>>24;
             valore[j]=temp[j]<<16;
             valore[j]=valore[j]>>18;  //rebinning da 16 a 14bit

             j++;
         }

         for(int q=0;q<j;q++)
         {
             if (sfera_address[q]==1)
                 bin[int(canale[q])][int(valore[q])]++;

             if (sfera_address[q]==2)
                 bin2[int(canale[q])][int(valore[q])]++;

             if (sfera_address[q]==3)
                 bin3[int(canale[q])][int(valore[q])]++;
         }
         count++;
     }

     double n_eventi=0;
     n_eventi=lSize/192;
     qDebug()<<"eventi catturati:"<<n_eventi;

      fclose(pFile_read);

     n_files_convert++;
     std::string number_no_leading_zeros_convert= std::to_string(n_files_convert);
     file_number_string_convert = std::string(8 - number_no_leading_zeros_convert.length(), '0') + number_no_leading_zeros_convert;
     binfile=binfile=dirname+"/"+filename+"_timed_"+file_number_string_convert+".bin";

     pFile_read = fopen (binfile.c_str(), "rb");

    }
     n_files_convert=0;

     for(int y=0;y<16384;y++)
         fprintf (pFile_write_01, "%li, ",bin[1][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_02, "%li, ",bin[2][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_03, "%li, ",bin[3][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_04, "%li, ",bin[4][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_05, "%li, ",bin[5][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_06, "%li, ",bin[6][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_07, "%li, ",bin[7][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_08, "%li, ",bin[8][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_09, "%li, ",bin[9][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_10, "%li, ",bin[10][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_11, "%li, ",bin[11][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_12, "%li, ",bin[12][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_13, "%li, ",bin[13][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_14, "%li, ",bin[14][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_15, "%li, ",bin[15][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_16, "%li, ",bin[16][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_17, "%li, ",bin2[1][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_18, "%li, ",bin2[2][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_19, "%li, ",bin2[3][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_20, "%li, ",bin2[4][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_21, "%li, ",bin2[5][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_22, "%li, ",bin2[6][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_23, "%li, ",bin2[7][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_24, "%li, ",bin2[8][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_25, "%li, ",bin2[9][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_26, "%li, ",bin2[10][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_27, "%li, ",bin2[11][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_28, "%li, ",bin2[12][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_29, "%li, ",bin2[13][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_30, "%li, ",bin2[14][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_31, "%li, ",bin2[15][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_32, "%li, ",bin2[16][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_33, "%li, ",bin3[1][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_34, "%li, ",bin3[2][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_35, "%li, ",bin3[3][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_36, "%li, ",bin3[4][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_37, "%li, ",bin3[5][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_38, "%li, ",bin3[6][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_39, "%li, ",bin3[7][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_40, "%li, ",bin3[8][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_41, "%li, ",bin3[9][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_42, "%li, ",bin3[10][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_43, "%li, ",bin3[11][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_44, "%li, ",bin3[12][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_45, "%li, ",bin3[13][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_46, "%li, ",bin3[14][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_47, "%li, ",bin3[15][y]);
     for(int y=0;y<16384;y++)
         fprintf (pFile_write_48, "%li, ",bin3[16][y]);




     qDebug()<<"finito";
     ui->logger->append("Finito");


     fclose(pFile_write_01);
     fclose(pFile_write_02);
     fclose(pFile_write_03);
     fclose(pFile_write_04);
     fclose(pFile_write_05);
     fclose(pFile_write_06);
     fclose(pFile_write_07);
     fclose(pFile_write_08);
     fclose(pFile_write_09);
     fclose(pFile_write_10);
     fclose(pFile_write_11);
     fclose(pFile_write_12);
     fclose(pFile_write_13);
     fclose(pFile_write_14);
     fclose(pFile_write_15);
     fclose(pFile_write_16);
     fclose(pFile_write_17);
     fclose(pFile_write_18);
     fclose(pFile_write_19);
     fclose(pFile_write_20);
     fclose(pFile_write_21);
     fclose(pFile_write_22);
     fclose(pFile_write_23);
     fclose(pFile_write_24);
     fclose(pFile_write_25);
     fclose(pFile_write_26);
     fclose(pFile_write_27);
     fclose(pFile_write_28);
     fclose(pFile_write_29);
     fclose(pFile_write_30);
     fclose(pFile_write_31);
     fclose(pFile_write_32);
     fclose(pFile_write_33);
     fclose(pFile_write_34);
     fclose(pFile_write_35);
     fclose(pFile_write_36);
     fclose(pFile_write_37);
     fclose(pFile_write_38);
     fclose(pFile_write_39);
     fclose(pFile_write_40);
     fclose(pFile_write_41);
     fclose(pFile_write_42);
     fclose(pFile_write_43);
     fclose(pFile_write_44);
     fclose(pFile_write_45);
     fclose(pFile_write_46);
     fclose(pFile_write_47);
     fclose(pFile_write_48);
     //fclose(pFile_read);
     fclose(pFile_timestamp);
}

void timed_spectra::on_set_file_clicked()
{
    filename=ui->file_name->text().toStdString();
    dirname=ui->directory_name->text().toStdString();
    QSettings setting("MyComp","MyApp");
    setting.beginGroup("Filenames");
    setting.setValue("1",ui->file_name->text());
    setting.setValue("2",ui->directory_name->text());
    setting.endGroup();
}

void timed_spectra::on_pushButton_clicked()//refresh button
{
    int n_sfera=ui->sfera->currentIndex();
    int n_channel=ui->comboBox->currentIndex();
    int pixel= ((n_sfera)*16)+(n_channel+1);
    std::string convertfile;
    FILE * pFile_convert;
    unsigned char *buffer_memory_char;
    buffer_memory_char= new unsigned char[100000];
    QVector<double> x(16384),y(16384);


    if (pixel<49)
    {
        if (pixel <10)
            convertfile=dirname+"/"+filename+"_0"+std::to_string(pixel)+".txt";
        else
             convertfile=dirname+"/"+filename+"_"+std::to_string(pixel)+".txt";

        ui->logger->append("reading "+QString::fromStdString(convertfile));


        pFile_convert=fopen(convertfile.c_str(),"rt");
        if (pFile_convert==NULL)
        {
            //qDebug()<<"nope";
            ui->logger->append("File non esistente");
            //fputs ("File error",stderr);
            return;
        }
        else{
            qDebug()<<"ok";
            fputs ("File ok\n",stderr);}

        fseeko64 (pFile_convert , 0 , SEEK_END);
        long long lSize = ftello64 (pFile_convert);
        rewind (pFile_convert);
        fread(buffer_memory_char,sizeof(char),(int)lSize,pFile_convert);

        for (int i=0;i<lSize;i++)
        {
            if (buffer_memory_char[i]==44)
            {
                temp_spectra[temp_bin]=cifra_new;
                temp_bin+=1;
                i++;//serve per saltare gli spazi
                cifra_new=0;
                cifra_old=0;
            }
            else
            {

                cifra_old=cifra_old*10;
                cifra_new=cifra_old+(int)buffer_memory_char[i]-48;
                cifra_old=cifra_new;
            }

        }

        for (int i=0; i<16384; ++i)
        {
          x[i] = i;
          y[i] = temp_spectra[i];
        }
        ui->widget->graph(0)->setData(x, y);
        ui->widget->rescaleAxes();
        // give the axes some labels:
        ui->widget->xAxis->setLabel("Bin");
        ui->widget->yAxis->setLabel("Channel "+QString::number(ui->comboBox->currentIndex() +1 ));
        ui->widget->replot();

        fclose(pFile_convert);
    }
    else
         ui->logger->append("Not existing file");

}

void timed_spectra::on_toolButton_clicked()
{
    QString directory=QFileDialog::getExistingDirectory(this,tr("Open Directory"),"C://",QFileDialog::ShowDirsOnly);
    ui->directory_name->setText(directory);
}

void timed_spectra::acquire_timed()
{
    qDebug()<< "iniziata acquisizione";

    FILE * pFile;
    int n_files=0;
    int bytes_threshold_files=0;
    int first_frame=1;
    unsigned int temp_rt;
    unsigned int sfera_address_rt;
    unsigned int canale_rt;
    unsigned int valore_rt;

    FT_HANDLE ftHandle;
    FT_STATUS res;
    DWORD num;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    UCHAR LatencyTimer = 2; //our default setting is 16

    DWORD RxBytes=10000; //numero bytes ricevuti
    DWORD TxBytes=bytes_num; //numero bytes trasmessi
    DWORD numDevs;
    DWORD bytes_in_queue;
    int write_mode=ui->write_mode->currentIndex();

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
    std::string file_number_string= std::string(8,'0');
    std::string number_no_leading_zeros= std::to_string(repetion_counter-1);
    file_number_string = std::string(8 - number_no_leading_zeros.length(), '0') + number_no_leading_zeros;
    std::string binfile=dirname+"/"+filename+"_timed_"+file_number_string+".bin";

    if (write_mode==0)
        pFile = fopen ( binfile.c_str(), "w+b");


   RxBuffer_char= new unsigned char[DIM_QUEUE];
   queue_num=0;

    res = FT_Write(ftHandle,TxBuffer_start,sizeof(TxBuffer_start),&TxBytes);

    if(TxBytes==8)
    {
       qDebug()<<"Start Acquisition";
    }
    acquisition_flag=1;
    start_time=QDateTime::currentDateTime().toString(Qt::ISODate).toStdString();
    start_time_ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    while(acquisition_flag==1)
    {

        FT_GetQueueStatus (ftHandle, &bytes_in_queue); //scrive in bytes_in_queue il numero di bytes sul buffer di ricezione

        if(bytes_in_queue>=8000 && (bytes_in_queue%4==0))
        {

            res = FT_Read(ftHandle,RxBuffer_char,bytes_in_queue,&RxBytes); //leggo il buffer di ricezione e lo scrive in RxBuffer
            //QFuture<void> spectra_creation = QtConcurrent::run([&]{rt_spectra_creation(RxBuffer_char,(int)bytes_in_queue);});

            for(int i=0;i<bytes_in_queue;i+=4)
            {

                temp_rt = ((int(RxBuffer_char[i])<<24) | (int(RxBuffer_char[i+1]) <<16) |  (int(RxBuffer_char[i+2])<<8) |  (int(RxBuffer_char[i+3])));


                sfera_address_rt=temp_rt>>24;
                canale_rt=temp_rt<<8;
                canale_rt=canale_rt>>24;
                valore_rt=temp_rt<<16;
                valore_rt=valore_rt>>18;  //rebinning da 16 a 14bit


                switch (sfera_address_rt) {
                case 1:
                    spectra1_rt[canale_rt][valore_rt]++;
                    break;
                case 2:
                    spectra2_rt[canale_rt][valore_rt]++;
                    break;
                case 3:
                    spectra3_rt[canale_rt][valore_rt]++;
                    break;
                default:
                    break;
                }
            }
            if(first_frame)
            {
                RxBuffer_char=RxBuffer_char+12;
                bytes_in_queue=bytes_in_queue-12;
                first_frame=0;
            }

            if (write_mode==0)
            {
                fwrite(RxBuffer_char, bytes_in_queue*sizeof(char),1,pFile);
            }

            queue_num= queue_num+bytes_in_queue;
            bytes_threshold_files=bytes_threshold_files+bytes_in_queue;
            //qDebug()<<"bla:"+QString::number(bytes_in_queue);

        }

    }


    res = FT_Write(ftHandle,TxBuffer_stop,sizeof(TxBuffer_stop),&TxBytes);
    if(TxBytes==8)
    {
        qDebug()<<"Acquisition ended";
    }
        qDebug()<<"";
        qDebug()<<"";
    FT_Close(ftHandle);
    if (write_mode==0)
        fclose(pFile);
}

void timed_spectra::stop()
{
    acquisition_flag=0;
    realtime_flag=0;
    ui->lcd_display->stopping_flag=1;
}

void timed_spectra::realtimePlot_call()
{
    realtime_flag=1;

    while(realtime_flag==1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));

        emit refresh_plot();
    }

}

void timed_spectra::realtimePlot()
{


    if(ui->sfera->currentIndex()==0)
    {
        std::vector<double> temp_rt1 (spectra1_rt[ui->comboBox->currentIndex()+1].begin(),spectra1_rt[ui->comboBox->currentIndex()+1].end());
        y_rt=y_rt.fromStdVector(temp_rt1);

    }
    else if(ui->sfera->currentIndex()==1)
    {

        std::vector<double> temp_rt2 (spectra2_rt[ui->comboBox->currentIndex()+1].begin(),spectra2_rt[ui->comboBox->currentIndex()+1].end());
        y_rt=y_rt.fromStdVector(temp_rt2);

    }
    else if(ui->sfera->currentIndex()==2)
    {
        std::vector<double> temp_rt3 (spectra3_rt[ui->comboBox->currentIndex()+1].begin(),spectra3_rt[ui->comboBox->currentIndex()+1].end());
        y_rt=y_rt.fromStdVector(temp_rt3);

    }

    ui->widget_2->xAxis->setLabel("Bin");
    ui->widget_2->yAxis->setLabel("Channel "+QString::number(ui->comboBox->currentIndex() +1 ));

    ui->widget_2->yAxis->setScaleType(QCPAxis::stLogarithmic);
    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
    ui->widget_2->yAxis->setTicker(logTicker);
    ui->widget_2->yAxis->setNumberFormat("eb"); // e = exponential, b = beautiful decimal powers
    ui->widget_2->yAxis->setNumberPrecision(0); // makes sure "1*10^4" is displayed only as "10^4"


    ui->widget_2->graph(0)->setData(x_rt, y_rt);
    ui->widget_2->rescaleAxes();
    ui->widget_2->replot();

    if (ui->write_mode->currentIndex()==1 & rt_write==1)
    {
        std::string spectra_filename[49];
        FILE * fileSpectra[49];
        std::string file_number_string_rt= std::string(8,'0');
        std::string number_no_leading_zeros_rt= std::to_string(repetion_counter-1);
        file_number_string_rt = std::string(8 - number_no_leading_zeros_rt.length(), '0') + number_no_leading_zeros_rt;
        for (int i=1;i<49;i++)
        {
            if (i<10)
                spectra_filename[i]=dirname+"/"+filename+"_timed_"+file_number_string_rt+"_ch_0"+std::to_string(i)+".txt";
            else
                spectra_filename[i]=dirname+"/"+filename+"_timed_"+file_number_string_rt+"_ch_"+std::to_string(i)+".txt";

            fileSpectra[i] =fopen( spectra_filename[i].c_str(), "wb");
        }


        finish_time=QDateTime::currentDateTime().toString(Qt::ISODate).toStdString();
        finish_time_ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
        time_duration_ms = finish_time_ms-start_time_ms;
        comment_box=ui->comment_box->toPlainText().toStdString();

            spectra1_rt_temp=spectra1_rt;
            spectra2_rt_temp=spectra2_rt;
            spectra3_rt_temp=spectra3_rt;



        QSettings setting2("MyComp","MyApp2");
        setting2.beginGroup("Program_Sfera2");
        if(ui->timing_box->isChecked())
        {
            for (int i=1;i<49;i++)
            {
                fprintf (fileSpectra[i], "Kerberos ch %d\n\n",i);
                fprintf (fileSpectra[i], "Measurement started at: ");
                fprintf (fileSpectra[i], "%s\n",start_time.c_str());
                fprintf (fileSpectra[i], "(Milliseconds from epoch: ");
                fprintf (fileSpectra[i], "%s)\n\n",std::to_string(start_time_ms.count()).c_str());
                fprintf (fileSpectra[i], "Measurement finished at: ");
                fprintf (fileSpectra[i], "%s\n",finish_time.c_str());
                fprintf (fileSpectra[i], "(Milliseconds from epoch: ");
                fprintf (fileSpectra[i], "%s)\n\n",std::to_string(finish_time_ms.count()).c_str());
                fprintf (fileSpectra[i], "Measurement duration : ");
                fprintf (fileSpectra[i], "%s ms.\n\n",std::to_string(time_duration_ms.count()).c_str());
                fprintf (fileSpectra[i], "SFERA Settings: \n");
                fprintf (fileSpectra[i], "ADJ: %s\n",setting2.value("1").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "GAIN: %s\n",setting2.value("4").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "PEAKING TIME: %s\n",setting2.value("7").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "PKS MIRROR: %s\n",setting2.value("8").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "SCARICA PKS: %s\n",setting2.value("5").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "REF PKS: %s\n",setting2.value("9").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "DAC OFFSET: %s\n",setting2.value("2").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "DAC OFFSET FAST: %s\n",setting2.value("14").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "REFERENCE: %s\n",setting2.value("3").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "TH REAL: %s\n",setting2.value("10").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "POL SH: %s\n",setting2.value("11").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "BLH POLO 1U: %s\n",setting2.value("12").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "BLH SLEW RATE 1U: %s\n",setting2.value("13").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "THR CUBE: %s\n",setting2.value("15").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "INHIBIT DURATION: %s\n\n",setting2.value("16").toString().toStdString().c_str());
                fprintf (fileSpectra[i], "Comment: ");
                fprintf (fileSpectra[i], "%s\n\n",comment_box.c_str());
                fprintf (fileSpectra[i], "Spectrum: \n");
            }
        }

        int y=0;
        for (int i=1;i<17;i++)
        {
            for(y=0;y<16383;y++)
            {
                fprintf (fileSpectra[i], "%li, ",long(spectra1_rt_temp[i][y]));
            }
            if (y==16383)
            {
                qDebug()<<"ciao";
                fprintf (fileSpectra[i], "%li.",long(spectra1_rt_temp[i][y]));
            }
        }
        for (int i=17;i<33;i++)
        {
            for(y=0;y<16383;y++)
            {
                fprintf (fileSpectra[i], "%li, ",long(spectra2_rt_temp[i-16][y]));
            }
            if (y==16383)
            {
                qDebug()<<"ciao2";
                fprintf (fileSpectra[i], "%li.",long(spectra2_rt_temp[i-16][y]));
            }
        }
        for (int i=33;i<49;i++)
        {
            for(y=0;y<16383;y++)
            {
                fprintf (fileSpectra[i], "%li, ",long(spectra3_rt_temp[i-32][y]));
            }
            if (y==16383)
            {
                qDebug()<<"ciao3";
                fprintf (fileSpectra[i], "%li.",long(spectra3_rt_temp[i-32][y]));
            }
        }


        for (int i=1;i<49;i++)
            fclose(fileSpectra[i]);

    }
}


void timed_spectra::rt_spectra_creation(unsigned char *RxBuffer_char, int numbytes)
{

//    unsigned int temp_rt;
//    unsigned int sfera_address_rt;
//    unsigned int canale_rt;
//    unsigned int valore_rt;
//    //qDebug()<<"thread:"+QString::number(numbytes);
//    for(int i=0;i<numbytes;i+=4)
//    {

//        temp_rt = ((int(RxBuffer_char[i])<<24) | (int(RxBuffer_char[i+1]) <<16) |  (int(RxBuffer_char[i+2])<<8) |  (int(RxBuffer_char[i+3])));


//        sfera_address_rt=temp_rt>>24;
//        canale_rt=temp_rt<<8;
//        canale_rt=canale_rt>>24;
//        valore_rt=temp_rt<<16;
//        valore_rt=valore_rt>>18;  //rebinning da 16 a 14bit

//        //qDebug()<<"thread:"+QString::number(sfera_address_rt);



//        switch (sfera_address_rt) {
//        case 1:
//            spectra1_rt[canale_rt][valore_rt]++;
//            break;
//        case 2:
//            spectra2_rt[canale_rt][valore_rt]++;
//            break;
//        case 3:
//            spectra3_rt[canale_rt][valore_rt]++;
//            break;
//        default:
//            break;
//        }
//    }


}


void timed_spectra::on_set_time_clicked()
{
    ui->lcd_display->timeValue->setHMS(ui->spin_h->value(),ui->spin_m->value(),ui->spin_s->value());
    ui->lcd_display->display(ui->lcd_display->timeValue->toString("HH:mm:ss"));
    repet_h=ui->spin_h->value();
    repet_m=ui->spin_m->value();
    repet_s=ui->spin_s->value();
}

void timed_spectra::on_set_repetitions_clicked()
{
    num_of_repetitions=ui->spin_repetitions->value();

}


void timed_spectra::on_pushButton_2_clicked()
{
    delay_rep=ui->spin_delay_rep->value();
}

void timed_spectra::on_pushButton_3_clicked()
{
    stop();
    timer_start->stop();
    ui->lcd_display->timer->stop();
    repetion_counter=1;
    rt_write=0;
    tristate_button=0;
    ui->logger->append("Measurement Abruptly Stopped");
    for (int x=0;x<17;x++)
        for(int y=0;y<16384;y++)
        {
            spectra1_rt[x][y]=0;
            spectra2_rt[x][y]=0;
            spectra3_rt[x][y]=0;
        }
}
