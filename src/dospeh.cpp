#include "../include/dospeh.h"
#include <stdlib.h>

Dospeh::Dospeh()
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

Dospeh::~Dospeh() /*virtual*/
{
    //dtor
}

void Dospeh::refine(TOCHKA toch, STONES st)
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

CATEGORY Dospeh::cat() const
{
    return itsCategory;
}

std::string Dospeh::pro() const
{
    return itsProperty;
}

void Dospeh::setToch(int tochka)
{
    //itsTochka = (tochka >=0 && tochka <= 12) ? tochka : 0;
    if(tochka >=0 && tochka <= 12)
    {
        itsTochka = tochka;
    }
    if(tochka < 0)
    {
        itsTochka = 0;
    }
    if(tochka > 12)
    {
        itsTochka = 12;
    }
}

int Dospeh::toch() const
{
    return itsTochka;
}

int Dospeh::mirazh() const
{
    return itsMirazhey;
}

int Dospeh::nebeska() const
{
    return itsNebesok;
}

int Dospeh::podzemka() const
{
    return itsPodzemok;
}

int Dospeh::mirozdanka() const
{
    return itsMirozdanok;
}

void Dospeh::incMirazh() /*virtual*/
{
    itsMirazhey++;
}

void Dospeh::incNebeska() /*virtual*/
{
    itsNebesok++;
}

void Dospeh::incPodzemka() /*virtual*/
{
    itsPodzemok++;
}

void Dospeh::incMirozdanka() /*virtual*/
{
    itsMirozdanok++;
}
