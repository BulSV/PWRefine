#include "armor.h"
#include <stdlib.h>

Armor::Armor(int refineLevel,
             int requiredMiragecelestone,
             std::string category,
             std::string property)
    : itsCategory(category)
    , itsProperty(property)
    , itsRefineLevel(refineLevel)
    , itsRequiredMiragecelestone(requiredMiragecelestone)
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
        setRefineLevel(0);
        break;
    case SUCCESS:
        setRefineLevel(refineLevel() + 1);
        break;
    case FAIL:
        setRefineLevel(refineLevel() - 1);
        break;
    default:
        break;
    }
}

int Armor::refineLevel() const
{
    return itsRefineLevel;
}

int Armor::requiredMirageCelestone() const
{
    return itsRequiredMiragecelestone;
}

void Armor::setRefineLevel(int refineLevel)
{
    if(refineLevel <= MAX_REFINE_LEVEL && refineLevel >= MIN_REFINE_LEVEL)
    {
        itsRefineLevel = refineLevel;
    }
}
