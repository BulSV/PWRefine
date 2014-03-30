#ifndef STONE_H
#define STONE_H

#include <iostream>
#include <stdlib.h>
#include "armor.h"
#include "globalenums.h"

class Stone
{
    static std::string CATEGORY;
    std::string itsCategory;
public:
    Stone();
    virtual ~Stone();
    virtual std::string category() const;
    virtual float addChance(const Armor *armor) const = 0;
    virtual REFINE refineRequest(float obtainedChance) const = 0;
};

#endif // STONE_H
