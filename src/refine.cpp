#include "../include/refine.h"
#include <time.h>
#include <cstdlib>
#include "../include/matematika.h"
#include <iostream>

Refine::Refine()
: itsdospeh(0)
, itsCurRefRes(NEIZMEN)
{}

Refine::~Refine()
{}

void Refine::goRefining(Dospeh *dospeh, STONES s)
{
    itsdospeh = dospeh;

    switch(s)
    {
    case NOSTONE: tochkaMirazh();
                  break;
    case NEBESKA: tochkaNebeska();
                  break;
    case PODZEMKA: tochkaPodzemka();
                  break;
    case MIROZDANKA: tochkaMirozdanka();
                  break;
    default: exit(-6);
    }
}

TOCHKA Refine::refineResult() const
{
    return itsCurRefRes;
}

int Refine::tochka()
{
    srand(time(0));
    int x = rand()%100 + 1;
    //std::cout << "\nx=" << x << "\n";
    return x;
}

int Refine::verMirazh(int t)
{
    switch(t)
    {
    case 0: return tochka();
    case 1: return (tochka() - 20);
    case 2: return (tochka() - 20);
    case 3: return (tochka() - 20);
    case 4: return (tochka() - 20);
    case 5: return (tochka() - 20);
    case 6: return (tochka() - 20);
    case 7: return (tochka() - 20);
    case 8: return (tochka() - 25);
    case 9: return (tochka() - 20);
    case 10: return (tochka() - 20);
    case 11: return (tochka() - 20);
    default: exit(-3);
    }
}

void Refine::tochkaMirazh()
{
    if(verMirazh(itsdospeh->toch()) > 50)
    {
        itsCurRefRes = UDACH;
    }
    else
    {
        if(itsdospeh->toch())
        {
            itsCurRefRes = RESET;
        }
        else
        {
            itsCurRefRes = NEIZMEN;
        }
    }

    itsdospeh->refine(itsCurRefRes, NOSTONE);
}

int Refine::verNebeska(int t)
{
    return (verMirazh(t) + 15);
}

void Refine::tochkaNebeska()
{
    if(verNebeska(itsdospeh->toch()) > 50)
    {
        itsCurRefRes = UDACH;
    }
    else
    {
        if(itsdospeh->toch())
        {
            itsCurRefRes = RESET;
        }
        else
        {
            itsCurRefRes = NEIZMEN;
        }
    }

    itsdospeh->refine(itsCurRefRes, NEBESKA);
}

float Refine::verPodzemka(int t)
{
    return ((float)verMirazh(t) + 3.5);
}

void Refine::tochkaPodzemka()
{
    if(MLib::round(verPodzemka(itsdospeh->toch()), 0.5) > 50)
    {
        itsCurRefRes = UDACH;
    }
    else
    {
        if(itsdospeh->toch())
        {
            itsCurRefRes = NEUDACH;
        }
        else
        {
            itsCurRefRes = NEIZMEN;
        }
    }

    itsdospeh->refine(itsCurRefRes, PODZEMKA);
}

float Refine::verMirozdanka(int t)
{
    switch(t)
    {
    case 0: return 100.0;
    case 1: return (tochka() - (50 - 100.0/4.0));
    case 2: return (tochka() - (50 - 100.0/10.0));
    case 3: return (tochka() - (50 - 100.0/25.0));
    case 4: return (tochka() - (50 - 100.0/60.0));
    case 5: return (tochka() - (50 - 100.0/130.0));
    case 6: return (tochka() - (50 - 100.0/215.0));
    case 7: return (tochka() - (50 - 100.0/405.0));
    case 8: return (tochka() - (50 - 100.0/750.0));
    case 9: return (tochka() - (50 - 100.0/1370.0));
    case 10: return (tochka() - (50 - 100.0/2525.0));
    case 11: return (tochka() - (50 - 100.0/4645.0));
    default: exit(-3);
    }
}

void Refine::tochkaMirozdanka()
{
    if( MLib::round( verMirozdanka( itsdospeh->toch() ), 0.01 ) > 50 )
    {
        itsCurRefRes = UDACH;
    }
    else
    {
        itsCurRefRes = NEIZMEN;
    }

    itsdospeh->refine(itsCurRefRes, MIROZDANKA);
}
