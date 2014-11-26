TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    XML/pugixml.cpp \
    mainapplication.cpp \

SOURCES += main.cpp

LIBS += -L/usr/local/lib -lSDL2 -ldl -lpthread
LIBS += -L/usr/lib/x86_64-linux-gnu -lGL

INCLUDES += /usr/local/include
INCLUDES += /usr/include

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    XML/pugiconfig.hpp \
    XML/pugixml.hpp \
    StdAfx.h \
    mainapplication.h \
    DesignPatterns/Multiton.h

