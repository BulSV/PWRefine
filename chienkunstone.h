#ifndef CHIENKUNSTONE_H
#define CHIENKUNSTONE_H

#include "catalyzerstone.h"
#include "Exceptions/refinelevelexception.h"

class ChienkunStone : public CatalyzerStone
{
public:
    ChienkunStone();
    virtual ~ChienkunStone();
    virtual float addChance(const Armor* armor) const throw(RefineLevelException);
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // CHIENKUNSTONE_H
