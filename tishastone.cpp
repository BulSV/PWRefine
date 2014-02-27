#include "tishastone.h"

float TishaStone::addChance(int armorLevel)
{
    return additionalChance;
}

TishaStone::TishaStone()
    : additionalChance(ADD_CHANCE)
{
}

TishaStone::~TishaStone() /*virtual*/
{
}
