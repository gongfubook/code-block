QT += widgets

CONFIG += debug console 

QMAKE_CFLAGS += -static
QMAKE_LFLAGS += -static 

include($$PWD/blocks.pri)
include($$PWD/windows.pri)
include($$PWD/targets.pri)

# install
target.path = ./
INSTALLS += target
