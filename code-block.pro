QT += widgets

CONFIG += debug console 

QMAKE_CFLAGS += -static
QMAKE_LFLAGS += -static 

include($$PWD/blocks/blocks.pri)
include($$PWD/windows/windows.pri)
include($$PWD/targets/targets.pri)

# install
target.path = ./
INSTALLS += target
