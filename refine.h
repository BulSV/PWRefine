#ifndef REFINE_H
#define REFINE_H

#include "armor.h"
#include "miragecelestone.h"
#include "catalyzerstone.h"
#include "globalenums.h"

class Refine
{
public:
    static REFINE goRefining(Armor *armor,
                           MirageCelestone *mirageCelestone);
    static REFINE goRefining(Armor *armor,
                           MirageCelestone *mirageCelestone,
                           CatalyzerStone *catalyzerStone);
private:
    static float baseChance();
};

#endif // REFINE_H
