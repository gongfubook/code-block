QT += widgets

CONFIG += debug console 

QMAKE_LFLAGS += -static
QMAKE_LFLAGS += -static 

HEADERS     = block-base.h \
              code-list.h \
              block-list.h \
              block-color.h \
              block-io.h


SOURCES     = block-base.cpp \
              code-list.cpp \
              block-list.cpp \
              block-color.cpp \
              block-io.cpp \
              main.cpp

# install
target.path = ./
INSTALLS += target
