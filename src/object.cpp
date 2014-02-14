#include "../include/object.h"
#include <stdlib.h>

Object::Object()
: itsMirazhey(0)
, itsNebesok(0)
, itsPodzemok(0)
, itsMirozdanok(0)
, itsCategory(NOCATEGORY)
, itsProperty("NOPROPERTY")
, itsTochka(0)
{
    //ctor
}

Object::~Object() /*virtual*/
{
    //dtor
}

void Object::refine(TOCHKA toch, STONES st)
{
    switch(toch)
    {
        case RESET: itsTochka = 0;
                    break;
        case NEUDACH: if(itsTochka) itsTochka--;
                      break;
        case NEIZMEN: break;
        case UDACH: if(itsTochka < 12) itsTochka++;
                    break;
        default: exit(-1);
    }
    switch(st)
    {
        case NOSTONE: incMirazh();
                      break;
        case NEBESKA: incMirazh();
                      incNebeska();
                      break;
        case PODZEMKA: incMirazh();
                       incPodzemka();
                       break;
        case MIROZDANKA: incMirazh();
                         incMirozdanka();
                         break;
        default: exit(-2);
    }
}

CATEGORY Object::cat() const
{
    return itsCategory;
}

std::string Object::pro() const
{
    return itsProperty;
}

void Object::setToch(int tochka)
{
    itsTochka = (tochka <=12 && tochka >=0) ? tochka : 0;
}

int Object::toch() const
{
    return itsTochka;
}

int Object::mirazh() const
{
    return itsMirazhey;
}

int Object::nebeska() const
{
    return itsNebesok;
}

int Object::podzemka() const
{
    return itsPodzemok;
}

int Object::mirozdanka() const
{
    return itsMirozdanok;
}

void Object::incMirazh() /*virtual*/
{
    itsMirazhey++;
}

void Object::incNebeska() /*virtual*/
{
    itsNebesok++;
}

void Object::incPodzemka() /*virtual*/
{
    itsPodzemok++;
}

void Object::incMirozdanka() /*virtual*/
{
    itsMirozdanok++;
}
