#include "miragecelestone.h"
#include "matematika.h"

float MirageCelestone::addChance(const Armor *armor) const
{
    switch(armor)
    {
    case 0: return 0.0;
    case 1: return -20.0;
    case 2: return -20.0;
    case 3: return -20.0;
    case 4: return -20.0;
    case 5: return -20.0;
    case 6: return -20.0;
    case 7: return -20.0;
    case 8: return -25.0;
    case 9: return -30.0;
    case 10: return -38.0;
    case 11: return -45.0;
    default: std::cout << "ERROR! Refine level not in [0..12]";
        exit(-2);
    }
}

MirageCelestone::MirageCelestone()
{
}

MirageCelestone::~MirageCelestone()
{
}

REFINE MirageCelestone::refineRequest(float obtainedChance) const
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
