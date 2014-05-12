#ifndef TISHASTONE_H
#define TISHASTONE_H

#include <iostream>
#include "catalyzerstone.h"
#include "Exceptions/refinelevelexception.h"

class TishaStone : public CatalyzerStone
{
public:
    TishaStone();
    virtual ~TishaStone();
    virtual float addChance(const Armor *armor) const throw(RefineLevelException);
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // TISHASTONE_H
