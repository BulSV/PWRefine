#include <cstdlib>
#include <time.h>
#include <iostream>
#include "refine.h"

REFINE Refine::goRefining(Armor *armor,
        MirageCelestone *mirageCelestone)
{
	float armorChance;
    try {
    	armorChance = mirageCelestone->addChance(armor);
	} catch (RefineLevelException &e) {
		std::cout << e.message() << std::endl;
		delete mirageCelestone;
		mirageCelestone = 0;
		throw(RefineLevelException(e));
	}
	REFINE refine = mirageCelestone->refineRequest(armorChance + baseChance());

    delete mirageCelestone;
    mirageCelestone = 0;
    armor->setRefineLevel(refine);

    return refine;
}

REFINE Refine::goRefining(Armor *armor,
        MirageCelestone *mirageCelestone,
        CatalyzerStone *catalyzerStone)
{
	float armorChance;
	try {
		armorChance = catalyzerStone->addChance(armor);
	} catch (RefineLevelException &e) {
		std::cout << e.message() << std::endl;
		delete mirageCelestone;
		mirageCelestone = 0;
		delete catalyzerStone;
		catalyzerStone = 0;
		throw(RefineLevelException(e));
	}
    REFINE refine = catalyzerStone->refineRequest(armorChance + baseChance());

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

