#include "miragecelestone.h"
#include "matematika.h"

std::string MirageCelestone::CATEGORY = "MIRAGE CELESTONE";

float MirageCelestone::addChance(const Armor *armor) const throw(RefineLevelException)
{
	switch(armor->refineLevel())
	{
	case T0: return 0.0;
	case T1: return -20.0;
	case T2: return -20.0;
	case T3: return -20.0;
	case T4: return -20.0;
	case T5: return -20.0;
	case T6: return -20.0;
	case T7: return -20.0;
	case T8: return -25.0;
	case T9: return -30.0;
	case T10: return -38.0;
	case T11: return -45.0;
	default:
	{
		std::string message =  "\nERROR! Failed to refine armor, because the maximum or minimum level of refinement has\n";
		throw RefineLevelException(message);
	}
	}
}

MirageCelestone::MirageCelestone()
: itsCategory(CATEGORY)
{
}

MirageCelestone::~MirageCelestone()
{
}

std::string MirageCelestone::category() const
{
	return itsCategory;
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
