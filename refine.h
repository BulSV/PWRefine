#ifndef REFINE_H
#define REFINE_H

#include "armor.h"
#include "stone.h"
#include "globalenums.h"

class Refine
{
public:
    Refine();
    ~Refine();
    void goRefining(Armor *armor, Stone *stone);
    REFINE refineResult() const;
private:
    Armor *itsArmor;
    REFINE itsCurRefRes;

    float baseChance();
    float chance();
};

#endif // REFINE_H
