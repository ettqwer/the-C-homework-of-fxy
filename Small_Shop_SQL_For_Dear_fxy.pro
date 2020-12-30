#PROJECT BY 冯馨仪
#Begin Data 2020/12/28
#Now Verson:1.0
#End Data:
#GitHub Link:Do Not Open Source
#CopyRight © 2020 By 冯馨仪 Team
#--------------Useful File Begin---------------#
QT       += core gui
QT       += sql
QT       += axcontainer
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_user.cpp \
    addgoods.cpp \
    allinformation.cpp \
    changegoods.cpp \
    changeuser.cpp \
    chineseletterhelper.cpp \
    deletegoods.cpp \
    deleteuser.cpp \
    finduser.cpp \
    ingoods.cpp \
    main.cpp \
    model.cpp \
    outgoods.cpp \
    pooruserview.cpp \
    rootview.cpp \
    searchgoods.cpp \
    setting.cpp \
    small_shop_sql.cpp \
    sudonumberchange.cpp \
    thenumbeeofgoodscharts.cpp \
    usersudo.cpp \
    viewallofearn.cpp \
    viewallofsold.cpp \
    viewearnofgoods.cpp \
    viewnumberofgoods.cpp

HEADERS += \
    ALLIN.h \
    add_user.h \
    addgoods.h \
    allinformation.h \
    changegoods.h \
    changeuser.h \
    chineseletterhelper.h \
    deletegoods.h \
    deleteuser.h \
    finduser.h \
    ingoods.h \
    model.h \
    outgoods.h \
    pooruserview.h \
    rootview.h \
    searchgoods.h \
    setting.h \
    small_shop_sql.h \
    sudonumberchange.h \
    thenumbeeofgoodscharts.h \
    usersudo.h \
    viewallofearn.h \
    viewallofsold.h \
    viewearnofgoods.h \
    viewnumberofgoods.h

FORMS += \
    add_user.ui \
    addgoods.ui \
    allinformation.ui \
    changegoods.ui \
    changeuser.ui \
    deletegoods.ui \
    deleteuser.ui \
    finduser.ui \
    ingoods.ui \
    outgoods.ui \
    pooruserview.ui \
    rootview.ui \
    searchgoods.ui \
    setting.ui \
    small_shop_sql.ui \
    sudonumberchange.ui \
    thenumbeeofgoodscharts.ui \
    usersudo.ui \
    viewallofearn.ui \
    viewallofsold.ui \
    viewearnofgoods.ui \
    viewnumberofgoods.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
