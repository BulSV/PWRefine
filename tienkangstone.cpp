#include "tienkangstone.h"
#include "matematika.h"

std::string TienkangStone::CATEGORY = "TIENKANG STONE";

float TienkangStone::addChance(const Armor *armor) const throw(RefineLevelException)/*virtual*/
{
	switch(armor->refineLevel())
	{
	case T0: return 15.0;
	case T1: return -5.0;
	case T2: return -5.0;
	case T3: return -5.0;
	case T4: return -5.0;
	case T5: return -5.0;
	case T6: return -5.0;
	case T7: return -5.0;
	case T8: return -10.0;
	case T9: return -15.0;
	case T10: return -23.0;
	case T11: return -30.0;
	default:
	{
		std::string message = "\nERROR! Failed to refine armor, because the maximum or minimum level of refinement has\n";
		throw RefineLevelException(message);
	}
	}
}

TienkangStone::TienkangStone()
: itsCategory(CATEGORY)
{
}

TienkangStone::~TienkangStone() /*virtual*/
{
}

std::string TienkangStone::category() const
{
	return itsCategory;
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
