QT += gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += \
    $$PWD/sources \
    $$PWD/headers \


SOURCES += \
    main.cpp \
    sources/models/category.cpp \
    sources/models/transaction.cpp \
    sources/models/user.cpp \
    sources/parsers/userparser.cpp \
    sources/parsers/categoryparser.cpp \
    sources/parsers/transactionparser.cpp \
    sources/DAL/categoryrepository.cpp \
    sources/DAL/transactionrepository.cpp \
    sources/DAL/userrepository.cpp \
    sources/DAL/irepository.cpp \


HEADERS += \
    headers/category.h \
    headers/categoryparser.h \
    headers/constants.h \
    headers/ijsonparser.h \
    headers/transaction.h \
    headers/transactionparser.h \
    headers/user.h \
    headers/userparser.h \
    headers/categoryrepository.h \
    headers/transactionrepository.h \
    headers/userrepository.h \
    headers/irepository.h \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
