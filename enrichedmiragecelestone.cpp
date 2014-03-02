#include "enrichedmiragecelestone.h"

EnrichedMirageCelestone::EnrichedMirageCelestone(const CatalyzerStone *catalyzer)
    : itsCatalyzerStone(catalyzer)
{
}

EnrichedMirageCelestone::~EnrichedMirageCelestone()
{
}

float EnrichedMirageCelestone::addChance(const Armor *armor) const
{
    return itsCatalyzerStone->addChance(armor);
}

REFINE EnrichedMirageCelestone::refineRequest(float obtainedChance) const
{
    return itsCatalyzerStone->refineRequest(obtainedChance);
}
