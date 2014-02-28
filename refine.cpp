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

void Refine::goRefining(Armor *armor, Stone *stone)
{
    itsArmor = armor;

    stone->addChance(itsArmor) + chance();
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

float Refine::chance()
{
    switch(itsArmor->refineLevel())
    {
    case 0: return baseChance(); // +1
    case 1: return (baseChance() - 20.0); // +2
    case 2: return (baseChance() - 20.0); // +3
    case 3: return (baseChance() - 20.0); // +4
    case 4: return (baseChance() - 20.0); // +5
    case 5: return (baseChance() - 20.0); // +6
    case 6: return (baseChance() - 20.0); // +7
    case 7: return (baseChance() - 20.0); // +8
    case 8: return (baseChance() - 25.0); // +9
    case 9: return (baseChance() - 30.0); // +10
    case 10: return (baseChance() - 38.0); // +11
    case 11: return (baseChance() - 45.0); // +12
    default: std::cout << "ERROR! Refine level not in [0..12]";
        exit(-2);
    }
}
