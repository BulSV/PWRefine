#include "chienkunstone.h"
#include <iostream>
#include <cstdlib>

float ChienkunStone::addChance(int armorLevel)
{
    switch(armorLevel)
    {
    case 0: return 50.0;
    case 1: return (100.0/4.0 - 50.0);
    case 2: return (100.0/10.0 - 50.0);
    case 3: return (100.0/25.0 - 50.0);
    case 4: return (100.0/60.0 - 50.0);
    case 5: return (100.0/130.0 - 50.0);
    case 6: return (100.0/215.0 - 50.0);
    case 7: return (100.0/405.0 - 50.0);
    case 8: return (100.0/750.0 - 50.0);
    case 9: return (100.0/1370.0 - 50.0);
    case 10: return (100.0/2525.0 - 50.0);
    case 11: return (100.0/4645.0 - 50.0);
    default: std::cout << "ERROR! Refine level not in [0..12]";
        exit(-1);
    }
}

ChienkunStone::ChienkunStone()
{
}

ChienkunStone::~ChienkunStone()
{
}
