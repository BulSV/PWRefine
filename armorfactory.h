#ifndef ARMOR_FACTORY
#define ARMOR_FACTORY

#include <string>
#include "armor.h"

class ArmorFactory
{
public:
    virtual Armor *createArmor(REFINE_LEVEL refineLevel = 0,
                               int requiredMiragecelestone = 1,
                               std::string category = "NO CATEGORY",
                               std::string property = "NO PROPERTY") const = 0;

    virtual ~ArmorFactory();
};

#endif // ARMOR_FACTORY
