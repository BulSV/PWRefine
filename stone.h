#ifndef STONE_H
#define STONE_H

#include "armor.h"

class Stone
{
protected:
    virtual float addChance(int armorLevel) = 0;
public:
    Stone();
    virtual ~Stone();
    float addChance(const Armor *armor) const;
};

#endif // STONE_H
