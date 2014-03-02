#ifndef CATALYZER_STONE_H
#define CATALYZER_STONE_H

#include "globalenums.h"
#include "stone.h"

class CatalyzerStone : public Stone
{
public:
    CatalyzerStone();
    virtual ~CatalyzerStone();
    virtual float addChance(const Armor *armor) const = 0;
    virtual REFINE refineRequest(float obtainedChance) const = 0;
};

#endif // CATALYZER_STONE_H
