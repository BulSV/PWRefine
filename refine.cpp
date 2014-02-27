#include "refine.h"
#include <time.h>
#include <cstdlib>
#include "matematika.h"
#include <iostream>

Refine::Refine()
: itsArmor(0)
, itsCurRefRes(NOCHANGE)
{}

Refine::~Refine()
{}

void Refine::goRefining(Armor *armor, Stone stone)
{
    itsArmor = armor;

    stone.addChance(armor) + chance(armor->refine());
}

REFINE Refine::refineResult() const
{
    return itsCurRefRes;
}

float Refine::baseChance()
{
    srand(time(0));    

    return reinterpret_cast<float>(rand()%100 + 1);
}

float Refine::chance(int armorLevel)
{
    switch(armorLevel)
    {
    case 0: return baseChance();
    case 1: return (baseChance() - 20.0);
    case 2: return (baseChance() - 20.0);
    case 3: return (baseChance() - 20.0);
    case 4: return (baseChance() - 20.0);
    case 5: return (baseChance() - 20.0);
    case 6: return (baseChance() - 20.0);
    case 7: return (baseChance() - 20.0);
    case 8: return (baseChance() - 25.0);
    case 9: return (baseChance() - 30.0);
    case 10: return (baseChance() - 38.0);
    case 11: return (baseChance() - 31.0);
    default: std::cout << "ERROR! Refine level no in [0..12]";
        exit(-2);
    }
}
