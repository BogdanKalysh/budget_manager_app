QT += gui core sql

TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEPENDPATH += \
    $$PWD/sources \
    $$PWD/headers \
    $$PWD/sources/models \
    $$PWD/headers/models \
    $$PWD/sources/repositories \
    $$PWD/headers/repositories \
    $$PWD/headers/querybuilder \
    $$PWD/sources/querybuilder \


INCLUDEPATH += \
    $$PWD/sources \
    $$PWD/headers \
    $$PWD/sources/models \
    $$PWD/headers/models \
    $$PWD/sources/repositories \
    $$PWD/headers/repositories \
    $$PWD/headers/querybuilder \
    $$PWD/sources/querybuilder \


SOURCES += \
    sources/models/category.cpp \
    sources/models/transaction.cpp \
    sources/models/user.cpp \
    sources/repositories/categoryrepository.cpp \
    sources/repositories/setupdatabase.cpp \
    sources/repositories/transactionrepository.cpp \
    sources/repositories/userrepository.cpp \
    sources/querybuilder/querybuilder.cpp \


HEADERS += \
    headers/constants.h \
    headers/models/category.h \
    headers/models/transaction.h \
    headers/models/user.h \
    headers/repositories/categoryrepository.h \
    headers/repositories/setupdatabase.h \
    headers/repositories/transactionrepository.h \
    headers/repositories/userrepository.h \
    headers/repositories/irepository.h \
    headers/querybuilder/querybuilder.h \

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target



LIBS += -LC:/msys64/mingw64/bin/ \
    -llibPocoCrypto.dll


INCLUDEPATH += C:/msys64/mingw64/include
DEPENDPATH += C:/msys64/mingw64/include
