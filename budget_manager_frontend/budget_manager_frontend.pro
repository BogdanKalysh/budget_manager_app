QT += core
QT += gui
QT += network
QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    $$PWD/sources \
    $$PWD/sources/models \
    $$PWD/sources/builders \
    $$PWD/sources/parsers \
    $$PWD/sources/listItems \
    $$PWD/sources/windows \
    $$PWD/sources/tests\
    $$PWD/headers \
    $$PWD/headers/models \
    $$PWD/headers/builders \
    $$PWD/headers/parsers \
    $$PWD/headers/listItems \
    $$PWD/headers/windows \
    $$PWD/forms \
    $$PWD/resources\
    $$PWD/headers/tests\

DEPENDPATH += \
    $$PWD/mainWindow \


HEADERS += \
    headers/windows/addcategorydialog.h \
    headers/listItems/TransactionsListItem.h \
    headers/builders/IJsonBuilder.h \
    headers/builders/userJsonBuilder.h \
    headers/models/category.h \
    headers/builders/categoryJsonBuilder.h \
    headers/constants.h \
    headers/windows/loginWindow.h \
    headers/windows/mainWindow.h \
    headers/windows/signUpWindow.h \
    headers/models/transaction.h \
    headers/builders/transactionJsonBuilder.h \
    headers/models/user.h \
    headers/models/transaction.h \
    headers/parsers/ijsonparser.h \
    headers/parsers/userparser.h \
    headers/parsers/categoryparser.h \
    headers/parsers/transactionparser.h\
    headers/listItems/legendlistitem.h \
    headers/windows/usersettingsdialog.h\
    headers/tests/testMainWindow.h \


SOURCES += \
    sources/listItems/legendlistitem.cpp \
    sources/windows/addcategorydialog.cpp \
    sources/listItems/TransactionsListItem.cpp \
    sources/builders/userJsonBuilder.cpp \
    sources/parsers/categoryparser.cpp \
    sources/builders/categoryJsonBuilder.cpp \
    sources/windows/loginWindow.cpp \
    sources/windows/mainWindow.cpp \
    sources/models/category.cpp \
    sources/models/transaction.cpp \
    sources/models/user.cpp \
    main.cpp \
    sources/parsers/transactionparser.cpp \
    sources/parsers/userparser.cpp \
    sources/windows/signUpWindow.cpp \
    sources/builders/transactionJsonBuilder.cpp \
    sources/windows/usersettingsdialog.cpp\
    sources/tests/testMainWindow.cpp \

FORMS += \
    forms/addcategorydialog.ui \
    forms/mainwindow.ui \
    forms/loginwindow.ui \
    forms/signupwindow.ui \
    forms/usersettingsdialog.ui

RESOURCES += \
    resources/src.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
