#include "../include/shlem.h"

Shlem::Shlem(std::string pro)
{
    itsCategory = SHLEM;
    itsProperty = pro;
    itsTochka = 0;
}

Shlem::~Shlem() /*virtual*/
{
    //dtor
}
