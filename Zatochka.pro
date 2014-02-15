TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    src/weapon.cpp \
    src/shlem.cpp \
    src/sapogi.cpp \
    src/ring.cpp \
    src/refine.cpp \
    src/poyas.cpp \
    src/plasch.cpp \
    src/ozherelye.cpp \
    src/naruchi.cpp \
    src/nakidka.cpp \
    src/matematika.cpp \
    src/kuznitsa.cpp \
    src/iochecker.cpp \
    src/bridgy.cpp \
    src/dospeh.cpp

HEADERS += \ 
    include/weapon.h \
    include/shlem.h \
    include/sapogi.h \
    include/ring.h \
    include/refine.h \
    include/poyas.h \
    include/plasch.h \
    include/ozherelye.h \
    include/naruchi.h \
    include/nakidka.h \
    include/matematika.h \
    include/kuznitsa.h \
    include/iochecker.h \
    include/bridgy.h \
    include/dospeh.h

OTHER_FILES += \
    TODO.txt \
    draftFile.cpp \
    newinputfunc.h \
    draftIochecker.h
