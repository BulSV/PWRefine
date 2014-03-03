#ifndef REFINE_H
#define REFINE_H

#include "armor.h"
#include "miragecelestone.h"
#include "catalyzerstone.h"
#include "globalenums.h"

class Refine
{
public:
    static void goRefining(Armor *armor,
                           const MirageCelestone *mirageCelestone);
    static void goRefining(Armor *armor,
                           const MirageCelestone *mirageCelestone,
                           const CatalyzerStone *catalyzerStone);
private:
    static float baseChance();
};

#endif // REFINE_H
