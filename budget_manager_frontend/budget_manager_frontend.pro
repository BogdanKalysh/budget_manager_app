QT += core
QT += gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    $$PWD/sources \
    $$PWD/sources/models \
    $$PWD/headers/builders \
    $$PWD/headers/parsers \
    $$PWD/headers \
    $$PWD/headers/models \
    $$PWD/headers/builders \
    $$PWD/headers/parsers \
    $$PWD/forms \
    $$PWD/resources \


DEPENDPATH += \
    $$PWD/mainWindow \


HEADERS += \
    headers/TransactionsListItem.h \
    headers/builders/IJsonBuilder.h \
    headers/builders/userJsonBuilder.h \
    headers/models/category.h \
    headers/builders/categoryJsonBuilder.h \
    headers/constants.h \
    headers/loginWindow.h \
    headers/mainWindow.h \
    headers/signUpWindow.h \
    headers/models/transaction.h \
    headers/builders/transactionJsonBuilder.h \
    headers/models/user.h \
    headers/models/transaction.h \
    headers/parsers/ijsonparser.h \
    headers/parsers/userparser.h \
    headers/parsers/categoryparser.h \
    headers/parsers/transactionparser.h


SOURCES += \
    sources/TransactionsListItem.cpp \
    sources/builders/userJsonBuilder.cpp \
    sources/parsers/categoryparser.cpp \
    sources/builders/categoryJsonBuilder.cpp \
    sources/loginWindow.cpp \
    sources/mainWindow.cpp \
    sources/models/category.cpp \
    sources/models/transaction.cpp \
    sources/models/user.cpp \
    main.cpp \
    sources/parsers/transactionparser.cpp \
    sources/parsers/userparser.cpp \
    sources/signUpWindow.cpp \
    sources/builders/transactionJsonBuilder.cpp


FORMS += \
    forms/mainwindow.ui \
    forms/loginwindow.ui \
    forms/signupwindow.ui

RESOURCES += \
    resources/src.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
