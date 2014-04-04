#include "tishastone.h"
#include "matematika.h"

std::string TishaStone::CATEGORY = "TISHA STONE";

float TishaStone::addChance(const Armor *armor) const throw(RefineLevelException)
{
	switch(armor->refineLevel())
	{
	case T0: return 3.5;
	case T1: return -16.5;
	case T2: return -16.5;
	case T3: return -16.5;
	case T4: return -16.5;
	case T5: return -16.5;
	case T6: return -16.5;
	case T7: return -16.5;
	case T8: return -21.5;
	case T9: return -26.5;
	case T10: return -34.5;
	case T11: return -41.5;
	default:
	{
		std::string message =  "\nERROR!\nFailed to refine armor: \"" +
				armor->category() + ": " + armor->property() +
				"\",\nbecause the maximum or minimum level of refinement has\n";
		throw RefineLevelException(message);
	}
	}
}

TishaStone::TishaStone()
: itsCategory(CATEGORY)
{
}

TishaStone::~TishaStone() /*virtual*/
{
}

std::string TishaStone::category() const
{
	return itsCategory;
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
