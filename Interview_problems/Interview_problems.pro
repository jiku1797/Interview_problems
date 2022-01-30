TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    ../arrays/ \
    ../strings

SOURCES += \
        main.cpp

HEADERS += \
  ../arrays/Arrays.h
