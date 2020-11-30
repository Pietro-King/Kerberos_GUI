#ifndef FRAME_CHECKER_H
#define FRAME_CHECKER_H

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

namespace Ui {
class frame_checker;
}

class frame_checker : public QWidget
{
    Q_OBJECT

public:
    explicit frame_checker(QWidget *parent = 0);
    ~frame_checker();

private slots:
    void on_pushButton_clicked();

private:
    Ui::frame_checker *ui;
};

#endif // FRAME_CHECKER_H
