#include "../include/plasch.h"

Plasch::Plasch(std::string pro)
{
    itsCategory = PLASCH;
    itsProperty = pro;
    itsTochka = 0;
}

Plasch::~Plasch() /*virtual*/
{
    //dtor
}
