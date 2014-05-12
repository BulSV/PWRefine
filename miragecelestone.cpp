#include "miragecelestone.h"
#include "matematika.h"

float MirageCelestone::addChance(const Armor *armor) const
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
		std::string message =  "\nERROR!\nFailed to refine armor: \"" +
				armor->category() + ": " + armor->property() +
				"\",\nbecause the maximum or minimum level of refinement has\n";
		throw RefineLevelException(message);
	}
	}
}

MirageCelestone::MirageCelestone()
{
}

MirageCelestone::~MirageCelestone()
{
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
