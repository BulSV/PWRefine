#include "tienkangstone.h"
#include "matematika.h"

float TienkangStone::addChance(const Armor *armor) const /*virtual*/
{
    switch(armor->refineLevel())
    {
    case 0: return 15.0;
    case 1: return -5.0;
    case 2: return -5.0;
    case 3: return -5.0;
    case 4: return -5.0;
    case 5: return -5.0;
    case 6: return -5.0;
    case 7: return -5.0;
    case 8: return -10.0;
    case 9: return -15.0;
    case 10: return -23.0;
    case 11: return -30.0;
    default: std::cout << "ERROR! Refine level not in [0..12]";
        exit(-3);
    }
}

TienkangStone::TienkangStone()    
{
}

TienkangStone::~TienkangStone() /*virtual*/
{
}

REFINE TienkangStone::refineRequest(float obtainedChance) const
{
    if(MLib::roundFloat(obtainedChance, 0.001) > 50.0)
    {
        return SUCCESS;
    }
    else
    {
        return RESET;
    }
}
