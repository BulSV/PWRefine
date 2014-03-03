#include "refine.h"
#include <time.h>
#include <cstdlib>
#include "matematika.h"
#include <iostream>

void Refine::goRefining(Armor *armor,
                        const MirageCelestone *mirageCelestone)
{
    armor->setRefineLevel(mirageCelestone->refineRequest(mirageCelestone->addChance(armor) + baseChance()));
}

void Refine::goRefining(Armor *armor,
                        const MirageCelestone *mirageCelestone,
                        const CatalyzerStone *catalyzerStone)
{
    armor->setRefineLevel(catalyzerStone->refineRequest(catalyzerStone->addChance(armor) + baseChance()));
}

float Refine::baseChance()
{
    srand(time(0));

    return reinterpret_cast<float>(rand()%100 + 1);
}
