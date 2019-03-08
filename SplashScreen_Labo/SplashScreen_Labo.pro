QT += widgets
QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_splash_test.cpp \
    main.cpp \
    r_manag.cpp \
    r_display.cpp \
    spl.cpp

HEADERS += \
    spl.h \
    r_display.h \
    r_manag.h \
    observer.h \
    subject.h

RESOURCES += \
    resources.qrc
