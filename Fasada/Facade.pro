TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        aircondition.cpp \
        alarm.cpp \
        homedoors.cpp \
        homefacade.cpp \
        homewindows.cpp \
        lights.cpp \
        main.cpp

HEADERS += \
    aircondition.h \
    alarm.h \
    homedoors.h \
    homefacade.h \
    homewindows.h \
    lights.h
