QT += core gui sql testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoShop
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp \
           test_mainwindow.cpp

HEADERS += mainwindow.h
