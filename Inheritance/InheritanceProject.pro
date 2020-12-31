TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += catch.hpp \
    Armor.cpp \
    Weapon.cpp \
    RangedWeapon.cpp \
    Character.cpp \
    Item.cpp \
    projectTester.cpp
SOURCES += mainTester.cpp
SOURCES +=

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

HEADERS += \
    Armor.h \
    Weapon.h \
    RangedWeapon.h \
    Character.h \
    Item.h

