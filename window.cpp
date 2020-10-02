#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout();

    this->setWindowTitle("Kerberos GUI");
    this->resize(1280,720);

    QTabWidget *tab=new QTabWidget;
    Program_tab* program_tab = new Program_tab;
    Spectra* spectra = new Spectra;


    tab->addTab(spectra, "Spectra");
    tab->addTab(program_tab, "Program SFERA");
    layout->addWidget(tab);
    this->setLayout(layout);

}

Window::~Window()
{
    delete ui;
}
