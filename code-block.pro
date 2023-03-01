QT += core gui widgets

CONFIG += release console 

include($$PWD/blocks/blocks.pri)
include($$PWD/windows/windows.pri)
include($$PWD/targets/targets.pri)

TARGET = code-blocks-app

# install

target.path = $$PWD/build/code-blocks 

target_depends.path = $$PWD/build/code-blocks 
target_depends.commands = windeployqt $$PWD/build/code-blocks/$${TARGET}.exe
target_depends.depends = $$PWD/build/code-blocks/$${TARGET}.exe

INSTALLS += target target_depends
