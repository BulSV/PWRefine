#include "../include/kuznitsa.h"
#include "../include/weapon.h"
#include "../include/shlem.h"
#include "../include/nakidka.h"
#include "../include/bridgy.h"
#include "../include/sapogi.h"
#include "../include/naruchi.h"
#include "../include/plasch.h"
#include "../include/ozherelye.h"
#include "../include/poyas.h"
#include "../include/ring.h"
#include <stdlib.h>

Kuznitsa::Kuznitsa(CATEGORY cat, std::string pro)
{
    switch(cat)
    {
    /*case NOCATEGORY: itsdospeh = new dospeh;
                     break;*/
    case WEAPON: itsdospeh = new Weapon(pro);
                 break;
    case SHLEM: itsdospeh = new Shlem(pro);
                break;
    case NAKIDKA: itsdospeh = new Nakidka(pro);
                  break;
    case BRIDGY: itsdospeh = new Bridgy(pro);
                 break;
    case SAPOGI: itsdospeh = new Sapogi(pro);
                 break;
    case NARUCHI: itsdospeh = new Naruchi(pro);
                  break;
    case PLASCH: itsdospeh = new Plasch(pro);
                 break;
    case OZHERELYE: itsdospeh = new Ozherelye(pro);
                    break;
    case POYAS: itsdospeh = new Poyas(pro);
                break;
    case RING: itsdospeh = new Ring(pro);
               break;
    default: exit(-5);
    }
}

Kuznitsa::~Kuznitsa()
{
    //delete itsdospeh;
}

Dospeh* Kuznitsa::dospeh() const
{
    return itsdospeh;
}
