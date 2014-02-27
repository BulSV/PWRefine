#ifndef ARMOR_FACTORY
#define ARMOR_FACTORY

#include <string>
#include "armor.h"

class ArmorFactory
{
public:
    virtual Armor *createArmor(std::string property) const = 0;

    virtual ~ArmorFactory();
};

#endif // ARMOR_FACTORY
