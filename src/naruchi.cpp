#include "../include/naruchi.h"

Naruchi::Naruchi(std::string pro)
{
    itsCategory = NARUCHI;
    itsProperty = pro;
    itsTochka = 0;
}

Naruchi::~Naruchi() /*virtual*/
{
    //dtor
}
