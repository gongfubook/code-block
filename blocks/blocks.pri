include($$PWD/common/blocks-common.pri)

HEADERS +=  $$PWD/block-function.h \
            $$PWD/block-main-function.h \
            $$PWD/block-number.h \ 
            $$PWD/block-string.h \ 
            $$PWD/block-logic.h \
            $$PWD/block-loop.h \
            $$PWD/block-variable.h \
            $$PWD/block-list.h \
            $$PWD/block-dict.h \
            $$PWD/block-io.h 

SOURCES +=  $$PWD/block-function.cpp \
            $$PWD/block-main-function.cpp \
            $$PWD/block-number.cpp \ 
            $$PWD/block-string.cpp \ 
            $$PWD/block-logic.cpp \ 
            $$PWD/block-loop.cpp \
            $$PWD/block-variable.cpp \ 
            $$PWD/block-list.cpp \
            $$PWD/block-dict.cpp \
            $$PWD/block-io.cpp 