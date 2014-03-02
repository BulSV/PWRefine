#include "tishastone.h"
#include "matematika.h"

float TishaStone::addChance(const Armor *armor) const
{
    switch(armor->refineLevel())
    {
    case 0: return 3.5;
    case 1: return -16.5;
    case 2: return -16.5;
    case 3: return -16.5;
    case 4: return -16.5;
    case 5: return -16.5;;
    case 6: return -16.5;
    case 7: return -16.5;
    case 8: return -21.5;
    case 9: return -26.5;
    case 10: return -34.5;
    case 11: return -41.5;
    default: std::cout << "ERROR! Refine level not in [0..12]";
        exit(-4);
    }
}

TishaStone::TishaStone()    
{
}

TishaStone::~TishaStone() /*virtual*/
{
}

REFINE TishaStone::refineRequest(float obtainedChance) const
{
    if(MLib::roundFloat(obtainedChance, 0.001) > 50.0)
    {
        return SUCCESS;
    }
    else
    {
        return FAIL;
    }
}
