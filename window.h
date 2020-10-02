#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include <program_tab.h>
#include <spectra.h>

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    QTabWidget *tab;
    QVBoxLayout *layout;
    ~Window();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
