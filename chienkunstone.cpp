#include "chienkunstone.h"
#include <iostream>
#include <cstdlib>
#include "matematika.h"

std::string ChienkunStone::CATEGORY = "CHIENKUNSTONE";

float ChienkunStone::addChance(const Armor *armor) const
{
	switch(armor->refineLevel())
	{
	case T0: return 50.0;
	case T1: return (100.0/4.0 - 50.0);
	case T2: return (100.0/10.0 - 50.0);
	case T3: return (100.0/25.0 - 50.0);
	case T4: return (100.0/60.0 - 50.0);
	case T5: return (100.0/130.0 - 50.0);
	case T6: return (100.0/215.0 - 50.0);
	case T7: return (100.0/405.0 - 50.0);
	case T8: return (100.0/750.0 - 50.0);
	case T9: return (100.0/1370.0 - 50.0);
	case T10: return (100.0/2525.0 - 50.0);
	case T11: return (100.0/4645.0 - 50.0);
	default:
	{
		std::cout << "\nERROR! Failed to refine armor, because the maximum or minimum level of refinement has\n";
		exit(-1); // TODO exit(-1)
	}
	}
}

ChienkunStone::ChienkunStone()
: itsCategory(CATEGORY)
{
}

ChienkunStone::~ChienkunStone()
{
}

std::string ChienkunStone::category() const
{
	return itsCategory;
}

REFINE ChienkunStone::refineRequest(float obtainedChance) const
{
	if(MLib::roundFloat(obtainedChance, 0.001) > 50.0)
	{
		return SUCCESS;
	}
	else
	{
		return NOCHANGE;
	}
}
