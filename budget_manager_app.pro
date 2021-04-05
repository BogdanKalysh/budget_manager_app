QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += \
    $$PWD/mainWindow \
    $$PWD/models

DEPENDPATH += \
    $$PWD/mainWindow \



SOURCES += \
    DAL/categoryrepository.cpp \
    DAL/irepository.cpp \
    DAL/transactionrepository.cpp \
    DAL/userrepository.cpp \
    main.cpp \
    mainWindow/mainwindow.cpp \
    models/category.cpp \
    models/categoryparcer.cpp \
    models/transaction.cpp \
    models/transactionparcer.cpp \
    models/user.cpp \
    models/userparcer.cpp


HEADERS += \
    DAL/categoryrepository.h \
    DAL/irepository.h \
    DAL/transactionrepository.h \
    DAL/userrepository.h \
    mainWindow/mainwindow.h \
    models/category.h \
    models/categoryparcer.h \
    models/ijsonparcer.h \
    models/transaction.h \
    models/transactionparcer.h \
    models/user.h \
    models/userparcer.h

FORMS += \
    mainWindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
