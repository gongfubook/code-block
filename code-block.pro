QT += widgets

CONFIG += debug console 

HEADERS     = block-base.h \
              code-list.h \
              block-list.h 

SOURCES     = block-base.cpp \
              code-list.cpp \
              block-list.cpp \
              main.cpp

# install
target.path = ./
INSTALLS += target
