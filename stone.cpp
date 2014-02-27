#include "stone.h"

Stone::Stone()
{
}


Stone::~Stone() /*virtual*/
{
}

float Stone::addChance(const Armor *armor) const
{
    return addChance(armor->refine());
}
