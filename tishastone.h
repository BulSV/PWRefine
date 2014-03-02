#ifndef TISHASTONE_H
#define TISHASTONE_H

#include "catalyzerstone.h"

class TishaStone : public CatalyzerStone
{        
public:
    TishaStone();
    virtual ~TishaStone();
    virtual float addChance(const Armor *armor) const;
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // TISHASTONE_H
