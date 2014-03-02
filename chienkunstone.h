#ifndef CHIENKUNSTONE_H
#define CHIENKUNSTONE_H

#include "catalyzerstone.h"

class ChienkunStone : public CatalyzerStone
{

public:
    ChienkunStone();
    virtual ~ChienkunStone();
    virtual float addChance(const Armor* armor) const;
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // CHIENKUNSTONE_H
