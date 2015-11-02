TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Fly2Elephant.cpp \
    Dictionary.cpp \
    WordsTree.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stdafx.h \
    Fly2Elephant.h \
    Dictionary.h \
    WordsTree.h

