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
    /*case NOCATEGORY: itsObject = new Object;
                     break;*/
    case WEAPON: itsObject = new Weapon(pro);
                 break;
    case SHLEM: itsObject = new Shlem(pro);
                break;
    case NAKIDKA: itsObject = new Nakidka(pro);
                  break;
    case BRIDGY: itsObject = new Bridgy(pro);
                 break;
    case SAPOGI: itsObject = new Sapogi(pro);
                 break;
    case NARUCHI: itsObject = new Naruchi(pro);
                  break;
    case PLASCH: itsObject = new Plasch(pro);
                 break;
    case OZHERELYE: itsObject = new Ozherelye(pro);
                    break;
    case POYAS: itsObject = new Poyas(pro);
                break;
    case RING: itsObject = new Ring(pro);
               break;
    default: exit(-5);
    }
}

Kuznitsa::~Kuznitsa()
{
    //delete itsObject;
}

Object* Kuznitsa::object() const
{
    return itsObject;
}
