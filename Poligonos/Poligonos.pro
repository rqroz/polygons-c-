TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    point.cpp \
    polygon.cpp \
    rectangle.cpp

HEADERS += \
    point.h \
    polygon.h \
    rectangle.h
