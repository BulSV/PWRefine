#ifndef REFINE_H
#define REFINE_H

#include "armor.h"
#include "stone.h"
#include "globalenums.h"

class Refine
{
public:      
    static void goRefining(Armor *armor, const Stone *stone);
private:
    static float baseChance();
};

#endif // REFINE_H
