#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout();

    this->setWindowTitle("Kerberos GUI V2.4.1");
    this->resize(1350,800);

    QTabWidget *tab=new QTabWidget;
    Program_tab* program_tab = new Program_tab;
    Spectra* spectra = new Spectra;
    timed_spectra* timed_spectr = new timed_spectra;





    tab->addTab(spectra, "Spectra");
    tab->addTab(program_tab, "Program SFERA");
    tab->addTab(timed_spectr, "Timed Spectra");

    layout->addWidget(tab);
    this->setLayout(layout);

}

Window::~Window()
{
    delete ui;
}
