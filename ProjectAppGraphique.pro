QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../ChiffrementCpp/CruptoCiel/CryptoCiel1/x64/release/ -lcryptoCielTest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../ChiffrementCpp/CruptoCiel/CryptoCiel1/x64/debug/ -lcryptoCielTest

INCLUDEPATH += $$PWD/../../../ChiffrementCpp/CruptoCiel/CryptoCiel1
DEPENDPATH += $$PWD/../../../ChiffrementCpp/CruptoCiel/CryptoCiel1

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../ChiffrementCpp/CruptoCiel/CryptoCiel1/x64/release/libcryptoCielTest.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../ChiffrementCpp/CruptoCiel/CryptoCiel1/x64/debug/libcryptoCielTest.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../ChiffrementCpp/CruptoCiel/CryptoCiel1/x64/release/cryptoCielTest.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../ChiffrementCpp/CruptoCiel/CryptoCiel1/x64/debug/cryptoCielTest.lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../ChiffrementCpp/cryptopp/x64/Output/release/ -lcryptlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../ChiffrementCpp/cryptopp/x64/Output/debug/ -lcryptlib

INCLUDEPATH += $$PWD/../../../ChiffrementCpp/cryptopp
DEPENDPATH += $$PWD/../../../ChiffrementCpp/cryptopp

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../ChiffrementCpp/cryptopp/x64/Output/release/libcryptlib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../ChiffrementCpp/cryptopp/x64/Output/debug/libcryptlib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../ChiffrementCpp/cryptopp/x64/Output/release/cryptlib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../ChiffrementCpp/cryptopp/x64/Output/debug/cryptlib.lib
