#include <QCoreApplication>
#include <QApplication>
#include <window.h>
#include <QStyleFactory>
#include <QHBoxLayout>
#include <windows.h>
#include "ftd2xx.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
    a.setPalette(darkPalette);
    Window *mainWindow = new Window; //was Qwidget
    //QVBoxLayout *layout = new QVBoxLayout();
    mainWindow->show();
    FreeConsole();
    return a.exec();
}
