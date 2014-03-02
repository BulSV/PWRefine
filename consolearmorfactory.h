#ifndef CONSOLE_ARMOR_FACTORY
#define CONSOLE_ARMOR_FACTORY

#include <string>
#include "armorfactory.h"

class ConsoleArmorFactory: public ArmorFactory
{
    static ConsoleArmorFactory *itsConsoleArmorFactory;
protected:
    ConsoleArmorFactory();
public:
    virtual Armor *createArmor(int refineLevel = 0,
                               int requiredMiragecelestone = 1,
                                std::string category = "NO CATEGORY",
                                std::string property = "NO PROPERTY") const;
    static ArmorFactory *getInstance();
    static void delInstance();
    virtual ~ConsoleArmorFactory();
};

#endif // CONSOLE_ARMOR_FACTORY
