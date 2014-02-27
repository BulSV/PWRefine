#ifndef REFINE_H
#define REFINE_H

#include "armor.h"
#include "stone.h"

class Refine
{
public:
    Refine();
    ~Refine();
    void goRefining(Armor *armor, Stone stone);
    REFINE refineResult() const;
private:
    Armor *itsArmor;
    REFINE itsCurRefRes;

    float baseChance();
    float chance(int armorLevel);
};

#endif // REFINE_H
