#include "armor.h"
#include <stdlib.h>

Armor::Armor(REFINE_LEVEL refineLevel,
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
        setRefineLevel(T0);
        break;
    case SUCCESS:
        setRefineLevel(reinterpret_cast<REFINE_LEVEL>(reinterpret_cast<int>(refineLevel()) + 1));
        break;
    case FAIL:
        setRefineLevel(reinterpret_cast<REFINE_LEVEL>(reinterpret_cast<int>(refineLevel()) - 1));
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
    itsRefineLevel = refineLevel;
}
