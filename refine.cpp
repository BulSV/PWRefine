#include "refine.h"
#include <time.h>
#include <cstdlib>
#include "matematika.h"
#include <iostream>

void Refine::goRefining(Armor *armor, const Stone *stone)
{    
    armor->setRefineLevel(stone->refineRequest(stone->addChance(itsArmor) + chance()));
}

float Refine::baseChance()
{
    srand(time(0));

    return reinterpret_cast<float>(rand()%100 + 1);
}
