QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += \
    $$PWD/frontend \
    $$PWD/backend \
    $$PWD/frontend/mainWindow \
    $$PWD/backend/models \
    $$PWD/backend/DAL \

DEPENDPATH += \
    $$PWD/mainWindow \



SOURCES += \
    frontend/main.cpp \
    frontend/mainWindow/mainwindow.cpp \
    backend/models/category.cpp \
    backend/models/categoryparser.cpp \
    backend/models/transaction.cpp \
    backend/models/transactionparser.cpp \
    backend/models/user.cpp \
    backend/models/userparser.cpp \
    backend/DAL/categoryrepository.cpp \
    backend/DAL/transactionrepository.cpp \
    backend/DAL/userrepository.cpp \
    backend/DAL/irepository.cpp \


HEADERS += \
    frontend/mainWindow/mainwindow.h \
    backend/models/category.h \
    backend/models/categoryparser.h \
    backend/models/constants.h \
    backend/models/ijsonparser.h \
    backend/models/transaction.h \
    backend/models/transactionparser.h \
    backend/models/user.h \
    backend/models/userparser.h \
    backend/DAL/categoryrepository.h \
    backend/DAL/transactionrepository.h \
    backend/DAL/userrepository.h \
    backend/DAL/irepository.h \


FORMS += \
    frontend/mainWindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
