TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    ../arrays/ \
    ../strings \
    ../linked_lists

SOURCES += \
        main.cpp

HEADERS += \
  ../arrays/Arrays.h \
  ../arrays/QuickSort.h \
  ../linked_lists/LinkedList.h \
  ../linked_lists/LinkedList.inl \
  ../linked_lists/LinkedListSpecial.inl \
  Util.h

DISTFILES +=
