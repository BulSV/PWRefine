#include "../include/armor.h"
#include <stdlib.h>

Armor::Armor(int requiredMirazh,
               std::string category,
               std::string property)
    : itsCategory(category)
    , itsProperty(property)
    , itsTochka(0)
    , itsRequiredMirazh(requiredMirazh)
{
    //ctor
}

Armor::~Armor() /*virtual*/
{
    //dtor
}


std::string Armor::category() const
{
    return itsCategory;
}

std::string Armor::property() const
{
    return itsProperty;
}

void Armor::setTochka(REFINE resTochka)
{
    switch (resTochka) {
    case RESET:
        setToch(0);
        break;
    case SUCCESS:
        setToch(toch() + 1);
        break;
    case FAIL:
        setToch(toch() - 1);
        break;
    default:
        break;
    }
}

int Armor::tochka() const
{
    return itsTochka;
}

int Armor::requiredMiragecelestone() const
{
    return itsRequiredMirazh;
}

void Armor::setTochka(int tochka)
{
    if(tochka <= 12 && tochka >= 0)
    {
        itsTochka = tochka;
    }
}
