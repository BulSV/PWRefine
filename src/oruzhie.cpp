#include "../include/weapon.h"

Weapon::Weapon(std::string pro)
{
    itsCategory = WEAPON;
    itsProperty = pro;
    itsTochka = 0;
}

Weapon::~Weapon()
{
    //dtor
}

void Weapon::incMirazh() /*virtual*/
{
    itsMirazhey += 2;
}
