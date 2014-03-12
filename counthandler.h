#ifndef COUNTHANDLER_H
#define COUNTHANDLER_H

#include "armor.h"

class CountHandler
{
    Armor *itsArmor;
    int itsMirageCelestone;
    int itsTienkangStone;
    int itsTishaStone;
    int itsChienkunStone;
public:
    CountHandler(Armor *armor);
    ~CountHandler();
    Armor *armor() const;
    void incMirageCelestone();
    void incTienkangStone();
    void incTishaStone();
    void incChienkunStone();
    int mirageCelestone() const;
    int tienkangStone() const;
    int tishaStone() const;
    int chienkunStone() const;
};

#endif // COUNTHANDLER_H
