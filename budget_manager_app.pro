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
    main.cpp \
    mainWindow/mainwindow.cpp \
    models/category.cpp \
    models/categoryparser.cpp \
    models/transaction.cpp \
    models/transactionparser.cpp \
    models/user.cpp \
    models/userparser.cpp


HEADERS += \
    mainWindow/mainwindow.h \
    models/category.h \
    models/categoryparser.h \
    models/constants.h \
    models/ijsonparser.h \
    models/transaction.h \
    models/transactionparser.h \
    models/user.h \
    models/userparser.h

FORMS += \
    mainWindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
