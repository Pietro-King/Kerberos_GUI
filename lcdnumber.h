//LCDNumber.h File

#ifndef LCDNUMBER_H
#define LCDNUMBER_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QDateTime>
class LCDNumber: public QLCDNumber
{
  Q_OBJECT

  public:
  QTimer* timer;
  QTime*  timeValue;
  int flag=0;
  int forward_reverse=0;
  int stopping_flag=0;

  public:
    LCDNumber(QWidget * parentWidget)
    {
        int hours=0; int minutes=0;int seconds=0;

        timer = new QTimer();
        timeValue = new QTime(hours,minutes,seconds);
        this->setParent(parentWidget);
        this->display(timeValue->toString("HH:mm:ss"));
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setDisplay()));
    }

    ~LCDNumber(){}

   public slots:
    void setDisplay()
    {
        if (forward_reverse==0)
        {
        this->timeValue->setHMS(this->timeValue->addSecs(1).hour(),this->timeValue->addSecs(1).minute(),this->timeValue->addSecs(1).second());
        this->display(this->timeValue->toString("HH:mm:ss"));
        }
        if (forward_reverse==1)
        {
        this->timeValue->setHMS(this->timeValue->addSecs(-1).hour(),this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
        this->display(this->timeValue->toString("HH:mm:ss"));
            if (this->timeValue->second()==0 && this->timeValue->minute()==0 && this->timeValue->hour()==0 )
            {
                this->timer->stop();
                stopping_flag=1;
            }

        }
    }
    void go()
    {
      this->timer->start(1000);
    }

    void start_stop_reverse_lcdnumber()
    {
      this->timer->start(1000);
    }

    void start_stop_lcdnumber()
    {
        if(this->flag==0){
            this->timer->start(1000);
            this->flag=1;
        }
        else if(this->flag==1)
        {
            this->timer->stop();
            this->flag=2;
        }
        else if(this->flag==2)
        {
            //this->timer->stop();
            this->timeValue->setHMS(0,0,0);
            this->display(this->timeValue->toString("HH:mm:ss"));
            this->flag=0;
        }
    }
};
#endif
