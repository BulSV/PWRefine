TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    src/refine.cpp \
    src/matematika.cpp \
    src/armorfactory.cpp \
    src/iochecker.cpp \
    src/armor.cpp \
    src/consolearmor.cpp   \
    src/consolearmorfactory.cpp

HEADERS += \
    include/refine.h \
    include/matematika.h \
    include/armorfactory.h \
    include/iochecker.h \
    include/armor.h \
    include/consolearmor.h \
    include/consolearmorfactory.h \
    include/globalenums.h

OTHER_FILES += \
    TODO.txt    \
    refactor.cpp

