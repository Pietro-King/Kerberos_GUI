QT       += core gui
CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += c++11
CONFIG += windows

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += printsupport
QMAKE_LFLAGS += -static

TARGET = Kerberos GUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    window.cpp \
    sfera_spi_bits.cpp \
    program_tab.cpp \
    spectra.cpp \
    qcustomplot.cpp
win32:CONFIG(release, debug|release):LIBS += -L$$PWD/ -lftd2xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ -lftd2xx
else:unix: LIBS += -L$$PWD/ -lftd2xx

DISTFILES += \
    ftd2xx.lib \
    ftd2xx.dll \

FORMS += \
    window.ui \
    program_tab.ui \
    spectra.ui \
    acquire.ui

HEADERS += \
    window.h \
    sfera_spi_bits.h \
    ftd2xx.h \
    program_tab.h \
    spectra.h \
    lcdnumber.h \
    qcustomplot.h
