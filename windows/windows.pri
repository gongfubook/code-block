include($$PWD/window-events/window-events.pri)

HEADERS    += $$PWD/code-list-window.h \
              $$PWD/block-list-window.h \
              $$PWD/code-display-window.h \
              $$PWD/output-display-window.h \
              $$PWD/block-menu-window.h \
              $$PWD/main-window.h 

SOURCES    += $$PWD/code-list-window.cpp \
              $$PWD/block-list-window.cpp \
              $$PWD/code-display-window.cpp \
              $$PWD/output-display-window.cpp \ 
              $$PWD/block-menu-window.cpp \
              $$PWD/main-window.cpp 


INCLUDEPATH += $$PWD