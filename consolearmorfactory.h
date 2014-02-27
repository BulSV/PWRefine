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
    virtual Armor *createArmor(std::string property) const;
    static ArmorFactory *getInstance();
    static void delInstance();
    virtual ~ConsoleArmorFactory();
};

#endif // CONSOLE_ARMOR_FACTORY
