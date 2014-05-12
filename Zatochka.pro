TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    refine.cpp \
    matematika.cpp \
    armor.cpp \
    stone.cpp \
    tienkangstone.cpp \
    tishastone.cpp \
    chienkunstone.cpp \
    miragecelestone.cpp \
    catalyzerstone.cpp \
    counthandler.cpp \
    countmanager.cpp	\
    refinedriver.cpp    \
    consolerefinedriver.cpp \
    inputchecker.cpp \
    Exceptions/emptyexception.cpp \
    Exceptions/inputexception.cpp \
    Exceptions/inputlimitexception.cpp \
    Exceptions/refinelevelexception.cpp \
    Exceptions/stoiexception.cpp

HEADERS += \
    refine.h \
    matematika.h \
    armor.h \
    globalenums.h \
    stone.h \
    tienkangstone.h \
    tishastone.h \
    chienkunstone.h \
    miragecelestone.h \
    catalyzerstone.h \
    counthandler.h \
    countmanager.h	\
    refinedriver.h  \
    consolerefinedriver.h \
    inputchecker.h \
    Exceptions/emptyexception.h \
    Exceptions/inputexception.h \
    Exceptions/inputlimitexception.h \
    Exceptions/refinelevelexception.h \
    Exceptions/stoiexception.h

OTHER_FILES += \
    TODO.txt
