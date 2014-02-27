#include "tienkangstone.h"

float TienkangStone::addChance(int armorLevel) /*virtual*/
{
    return additionalChance;
}

TienkangStone::TienkangStone()
    : additionalChance(ADD_CHANCE)
{
}

TienkangStone::~TienkangStone() /*virtual*/
{
}
