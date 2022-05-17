QT       += core gui sql
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    components/bottom/bottombuttons.cpp \
    components/header/formheadercenter.cpp \
    components/header/formheaderright.cpp \
    components/header/formheadleft.cpp \
    components/leftBottom/leftbottom.cpp \
    components/leftTop/lefttopbutton.cpp \
    components/others/rotationview.cpp \
    components/right/bloodpump.cpp \
    components/right/bloodspeedadjust.cpp \
    components/right/righttemperature.cpp \
    components/selfCheckItem/selfcheckitem.cpp \
    main.cpp \
    pages/index/indexpagetypetwo.cpp \
    pages/index/indexwindow.cpp \
    pages/selfCheck/selfcheck.cpp \
    pages/start/startwindow.cpp \
    threads/timethread.cpp \
    tools/SeriaPort/myseriaport.cpp \
    tools/statusvalue.cpp \
    tools/thresholdvalue.cpp \
    tools/utils/cgammaramp.cpp \
    tools/utils/stringutils.cpp \
    tools/utils/toast.cpp

HEADERS += \
    components/bottom/bottombuttons.h \
    components/header/formheadercenter.h \
    components/header/formheaderright.h \
    components/header/formheadleft.h \
    components/leftBottom/leftbottom.h \
    components/leftTop/lefttopbutton.h \
    components/others/rotationview.h \
    components/right/bloodpump.h \
    components/right/bloodspeedadjust.h \
    components/right/righttemperature.h \
    components/selfCheckItem/selfcheckitem.h \
    pages/index/indexpagetypetwo.h \
    pages/index/indexwindow.h \
    pages/selfCheck/selfcheck.h \
    pages/start/startwindow.h \
    threads/timethread.h \
    tools/GlobalHead.h \
    tools/MyTools.h \
    tools/SeriaPort/myseriaport.h \
    tools/statusvalue.h \
    tools/thresholdvalue.h \
    tools/utils/cgammaramp.h \
    tools/utils/stringutils.h \
    tools/utils/toast.h

FORMS += \
    components/bottom/bottombuttons.ui \
    components/header/formheadercenter.ui \
    components/header/formheaderright.ui \
    components/header/formheadleft.ui \
    components/leftBottom/leftbottom.ui \
    components/leftTop/lefttopbutton.ui \
    components/right/bloodpump.ui \
    components/right/bloodspeedadjust.ui \
    components/right/righttemperature.ui \
    components/selfCheckItem/selfcheckitem.ui \
    pages/index/indexpagetypetwo.ui \
    pages/index/indexwindow.ui \
    pages/selfCheck/selfcheck.ui \
    pages/start/startwindow.ui

TRANSLATIONS += \
    XueTouJi2022_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    public/public.qrc
