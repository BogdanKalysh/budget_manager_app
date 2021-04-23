QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    $$PWD/sources \
    $$PWD/headers \
    $$PWD/forms \

DEPENDPATH += \
    $$PWD/mainWindow \


HEADERS += \
        headers/IJsonBuilder.h \
        headers/category.h \
        headers/categoryJsonBuilder.h \
        headers/constants.h \
        headers/loginJsonBuilder.h \
        headers/loginWindow.h \
        headers/mainWindow.h \
        headers/registrationJsonBuilder.h \
        headers/signUpWindow.h \
        headers/transaction.h \
        headers/transactionJsonBuilder.h \
        headers/user.h \
        headers/transaction.h


SOURCES += \
    sources/categoryJsonBuilder.cpp \
    sources/loginJsonBuilder.cpp \
    sources/loginWindow.cpp \
    sources/mainWindow.cpp \
    sources/models/category.cpp \
    sources/models/transaction.cpp \
    sources/models/user.cpp \
    sources/registrationJsonBuilder.cpp \
    main.cpp \
    sources/signUpWindow.cpp \
    sources/transactionJsonBuilder.cpp

#>>>>>>> a3561b0bdf48440138fe15bef5f842f134fc6482

FORMS += \
    forms/mainwindow.ui \
    forms/loginwindow.ui \
    forms/signupwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

