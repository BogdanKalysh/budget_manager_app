QT += gui sql

CONFIG += c++11
TEMPLATE = app
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += \
    $$PWD/sources \
    $$PWD/headers \
    $$PWD/sources/parsers \
    $$PWD/headers/parsers \

HEADERS += \
    headers/parsers/categoryparser.h \
    headers/parsers/ijsonparser.h \
    headers/parsers/transactionparser.h \
    headers/parsers/userparser.h \

SOURCES += \
    main.cpp \
    sources/parsers/userparser.cpp \
    sources/parsers/categoryparser.cpp \
    sources/parsers/transactionparser.cpp \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += \
    -L../build-DAL-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/debug -lDAL \

INCLUDEPATH += \
    ../DAL/headers \
    ../DAL/headers/models \
    ../DAL/headers/repositories
DEPENDPATH += \
    ../DAL/headers \
    ../DAL/headers/models \
    ../DAL/headers/repositories


