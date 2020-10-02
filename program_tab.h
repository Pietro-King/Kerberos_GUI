#ifndef PROGRAM_TAB_H
#define PROGRAM_TAB_H

#include <QWidget>
#include "sfera_spi_bits.h"
#include <QSettings>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include "QDebug"
#include <Windows.h>
#include <ftd2xx.h>
#include <chrono>
#include <thread>


namespace Ui {
class Program_tab;
}

class Program_tab : public QWidget
{
    Q_OBJECT

public:
    explicit Program_tab(QWidget *parent = 0);
    ~Program_tab();

private slots:
    void saveSettings();
    void loadSettings();


    void on_default_prog_clicked();

    void on_program_button_clicked();

private:
    Ui::Program_tab *ui;
};

#endif // PROGRAM_TAB_H
