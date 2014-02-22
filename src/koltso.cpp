#include "../include/koltso.h"

Koltso::Koltso(std::string pro)
{
    itsCategory = RING;
    itsProperty = pro;
    itsTochka = 0;
}

Koltso::~Koltso() /*virtual*/
{
    //dtor
}
