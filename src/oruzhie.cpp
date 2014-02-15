#include "../include/oruzhie.h"

Oruzhie::Oruzhie(std::string pro)
{
    itsCategory = WEAPON;
    itsProperty = pro;
    itsTochka = 0;
}

Oruzhie::~Oruzhie()
{
    //dtor
}

void Oruzhie::incMirazh() /*virtual*/
{
    itsMirazhey += 2;
}
