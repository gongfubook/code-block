QT += widgets

RESOURCES   = draggableicons.qrc

HEADERS     = dragwidget.h \
              block-base.h 

SOURCES     = dragwidget.cpp \
              block-base.cpp \
              main.cpp

# install
target.path = ./
INSTALLS += target
