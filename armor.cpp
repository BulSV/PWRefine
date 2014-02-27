#include "armor.h"
#include <stdlib.h>

Armor::Armor(int requiredMirazh,
             std::string category,
             std::string property)
    : itsCategory(category)
    , itsProperty(property)
    , itsRefine(0)
    , itsRequiredMirazh(requiredMirazh)
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

void Armor::setRefine(REFINE resRefine)
{
    switch (resRefine) {
    case RESET:
        setRefine(0);
        break;
    case SUCCESS:
        setRefine(refine() + 1);
        break;
    case FAIL:
        setRefine(refine() - 1);
        break;
    default:
        break;
    }
}

int Armor::refine() const
{
    return itsRefine;
}

int Armor::requiredMirageCelestone() const
{
    return itsRequiredMirazh;
}

void Armor::setRefine(int refine)
{
    if(refine <= MAX_REFINE_LEVEL && refine >= MIN_REFINE_LEVEL)
    {
        itsRefine = refine;
    }
}
