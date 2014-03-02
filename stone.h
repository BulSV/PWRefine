#ifndef STONE_H
#define STONE_H

#include "armor.h"
#include "globalenums.h"

class Stone
{
public:
    Stone();
    virtual ~Stone();
    virtual float addChance(const Armor *armor) const = 0;
    virtual REFINE refineRequest(float obtainedChance) const = 0;
};

#endif // STONE_H
