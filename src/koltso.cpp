#include "../include/ring.h"

Ring::Ring(std::string pro)
{
    itsCategory = RING;
    itsProperty = pro;
    itsTochka = 0;
}

Ring::~Ring()
{
    //dtor
}
