#ifndef TIENKANGSTONE_H
#define TIENKANGSTONE_H

#include <iostream>
#include "catalyzerstone.h"
#include "Exceptions/refinelevelexception.h"

class TienkangStone : public CatalyzerStone
{
public:
    TienkangStone();
    virtual ~TienkangStone();
    virtual float addChance(const Armor *armor) const;
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // TIENKANGSTONE_H
