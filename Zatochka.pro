TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    refine.cpp \
    matematika.cpp \
    armorfactory.cpp \
    iochecker.cpp \
    armor.cpp \
    consolearmor.cpp   \
    consolearmorfactory.cpp \
    stone.cpp \
    tienkangstone.cpp \
    tishastone.cpp \
    chienkunstone.cpp \
    miragecelestone.cpp \
    catalyzerstone.cpp

HEADERS += \
    refine.h \
    matematika.h \
    armorfactory.h \
    iochecker.h \
    armor.h \
    consolearmor.h \
    consolearmorfactory.h \
    globalenums.h \
    stone.h \
    tienkangstone.h \
    tishastone.h \
    chienkunstone.h \
    miragecelestone.h \
    catalyzerstone.h

OTHER_FILES += \
    TODO.txt    \
    refactor.cpp

