QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ConsultScore.cpp \
    MyClient.cpp \
    StuLoad.cpp \
    StuMenu.cpp \
    TeaLoad.cpp \
    TeaMenu.cpp \
    main.cpp \
    personcenter.cpp \
    recordifm.cpp \
    stuifm.cpp \
    widget.cpp

HEADERS += \
    ConsultScore.h \
    MyClient.h \
    StuLoad.h \
    StuMenu.h \
    TeaLoad.h \
    TeaMenu.h \
    personcenter.h \
    recordifm.h \
    stuifm.h \
    widget.h

FORMS += \
    ConsultScore.ui \
    StuLoad.ui \
    StuMenu.ui \
    TeaLoad.ui \
    TeaMenu.ui \
    personcenter.ui \
    recordifm.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
