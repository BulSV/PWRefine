#include <stdlib.h>
#include "armor.h"

Armor::Armor(REFINE_LEVEL refineLevel,
		int requiredMiragecelestone,
		std::string category,
		std::string property)
: itsCategory(category)
, itsProperty(property)
, itsRefineLevel(refineLevel)
, itsRequiredMiragecelestone(requiredMiragecelestone)
, itsWasRefineLevel(itsRefineLevel)
{
}

Armor::~Armor() /*virtual*/
{
}

std::string Armor::category() const
{
	return itsCategory;
}

std::string Armor::property() const
{
	return itsProperty;
}

void Armor::setRefineLevel(REFINE resRefine)
{
	switch (resRefine) {
	case RESET:
		setRefineLevel(T0);
		break;
	case SUCCESS:
		setRefineLevel((REFINE_LEVEL)((int)(refineLevel()) + 1));
		break;
	case FAIL:
		setRefineLevel((REFINE_LEVEL)((int)(refineLevel()) - 1));
		break;
	default:
		break;
	}
}

REFINE_LEVEL Armor::refineLevel() const
{
	return itsRefineLevel;
}

int Armor::requiredMirageCelestone() const
{
	return itsRequiredMiragecelestone;
}

void Armor::setRefineLevel(REFINE_LEVEL refineLevel)
{
	itsWasRefineLevel = itsRefineLevel;
	if(refineLevel >= T0 && refineLevel <= T12)
	{
		itsRefineLevel = refineLevel;
	}
}

REFINE_LEVEL Armor::wasRefineLevel() const
{
	return itsWasRefineLevel;
}
