QT += widgets

CONFIG += debug console 

QMAKE_CFLAGS += -static
QMAKE_LFLAGS += -static 

HEADERS     = block-base.h \
              code-list.h \
              block-list.h \
              block-color.h \
              block-io.h \
              block-function.h \
              block-size.h \
              block-main-function.h \
              code-display.h \
              output-display.h \
              block-menu.h \
              block-number.h \ 
              block-string.h \ 
              block-logic.h \
              block-loop.h \
              block-variable.h \
              main-window.h 


SOURCES     = block-base.cpp \
              code-list.cpp \
              block-list.cpp \
              block-color.cpp \
              block-io.cpp \
              block-function.cpp \
              block-size.cpp \
              block-main-function.cpp \
              main-window.cpp \
              code-display.cpp \
              output-display.cpp \ 
              block-menu.cpp \
              block-number.cpp \ 
              block-string.cpp \ 
              block-logic.cpp \ 
              block-loop.cpp \
              block-variable.cpp \ 
              main.cpp

# install
target.path = ./
INSTALLS += target
