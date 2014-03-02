#ifndef ENRICHEDMIRAGECELESTONE_H
#define ENRICHEDMIRAGECELESTONE_H

#include "miragecelestone.h"
#include "catalyzerstone.h"

class EnrichedMirageCelestone : public MirageCelestone
{
    CatalyzerStone *itsCatalyzerStone;
public:
    EnrichedMirageCelestone(const CatalyzerStone *catalyzer);
    virtual ~EnrichedMirageCelestone();
    virtual float addChance(const Armor *armor) const;
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // ENRICHEDMIRAGECELESTONE_H
