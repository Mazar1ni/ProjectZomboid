#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T18:07:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectZomboid
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(debug, debug|release) {
    DESTDIR = $$OUT_PWD/../../ProjectZomboid/Debug
} else {
    DESTDIR = $$OUT_PWD/../../ProjectZomboid/Release
}
# разделяем по директориям все выходные файлы проекта
MOC_DIR = ../common/build/moc
RCC_DIR = ../common/build/rcc
UI_DIR = ../common/build/ui
unix:OBJECTS_DIR = ../common/build/o/unix
win32:OBJECTS_DIR = ../common/build/o/win32
macx:OBJECTS_DIR = ../common/build/o/mac

# в зависимости от режима сборки проекта
# запускаем win deploy приложения в целевой директории, то есть собираем все dll
CONFIG(debug, debug|release) {
    QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$OUT_PWD/../../ProjectZomboid/Debug
} else {
    QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$OUT_PWD/../../ProjectZomboid/Release
}


SOURCES += \
        main.cpp \
    Code/UI/game.cpp \
    Code/Character/main_character.cpp \
    Code/Character/player.cpp \
    Code/UI/scene.cpp \
    Code/UI/background.cpp \
    Code/Storage/storageitem.cpp \
    Code/Character/Components/storagecomponent.cpp \
    Code/UI/inventory.cpp \
    Code/UI/advancedtablewidget.cpp \
    Code/Storage/Items/item_water.cpp \
    Code/Character/Components/statscomponent.cpp \
    Code/UI/hud.cpp \
    Code/Storage/Equipables/equipableitem.cpp \
    Code/Character/Components/equipcomponents.cpp \
    Code/UI/equiptablewidget.cpp \
    Code/Storage/Equipables/Hats/hat.cpp \
    Code/Storage/Equipables/Hats/cylinderhat.cpp \
    Code/Storage/Equipables/Weapons/weapon.cpp \
    Code/Storage/Equipables/Weapons/rangeweapon.cpp \
    Code/Storage/Items/Horn/horn.cpp \
    Code/object.cpp

HEADERS += \
    Code/UI/game.h \
    Code/Character/main_character.h \
    Code/Character/player.h \
    Code/UI/scene.h \
    Code/UI/background.h \
    Code/Storage/storageitem.h \
    Code/Character/Components/storagecomponent.h \
    Code/UI/inventory.h \
    Code/UI/advancedtablewidget.h \
    Code/Storage/Items/item_water.h \
    Code/Character/Components/statscomponent.h \
    Code/UI/hud.h \
    Code/Storage/Equipables/equipableitem.h \
    Code/Character/Components/equipcomponents.h \
    Code/UI/equiptablewidget.h \
    Code/Storage/Equipables/Hats/hat.h \
    Code/Storage/Equipables/Hats/cylinderhat.h \
    Code/Storage/Equipables/Weapons/weapon.h \
    Code/Storage/Equipables/Weapons/rangeweapon.h \
    Code/Storage/Items/Horn/horn.h \
    Code/object.h

RESOURCES += \
    Resources/cursor.qrc \
    Resources/player.qrc \
    Resources/background.qrc \
    Resources/items.qrc
