#include <cstdlib>
#include <time.h>
#include <iostream>
#include "refine.h"

REFINE Refine::goRefining(Armor *armor,
        MirageCelestone *mirageCelestone)
{
	REFINE refine = mirageCelestone->refineRequest(mirageCelestone->addChance(armor) + baseChance());

    delete mirageCelestone;
    mirageCelestone = 0;
    armor->setRefineLevel(refine);

    return refine;
}

REFINE Refine::goRefining(Armor *armor,
        MirageCelestone *mirageCelestone,
        CatalyzerStone *catalyzerStone)
{
    REFINE refine = catalyzerStone->refineRequest(catalyzerStone->addChance(armor) + baseChance());

    delete mirageCelestone;
    mirageCelestone = 0;
    delete catalyzerStone;
    catalyzerStone = 0;
    armor->setRefineLevel(refine);

    return refine;
}

float Refine::baseChance()
{
    srand(time(0));

    return (float)(rand()%100 + 1);
}

