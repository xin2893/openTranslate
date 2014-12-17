TEMPLATE = app

QT += core qml quick widgets network

SOURCES += main.cpp \
    translate.cpp \
    baiduapidictresult.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    translate.h \
    global.h \
    baiduapidictresult.h
