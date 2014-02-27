#include "consolearmorfactory.h"
#include "consolearmor.h"

ConsoleArmorFactory *ConsoleArmorFactory::itsConsoleArmorFactory = NULL;

ConsoleArmorFactory::ConsoleArmorFactory()
{
}

Armor *ConsoleArmorFactory::createArmor(std::string property) const /*virtual*/
{
    return new ConsoleArmor(property);
}

ArmorFactory *ConsoleArmorFactory::getInstance() /*static*/
{
    if(!itsConsoleArmorFactory)
    {
        itsConsoleArmorFactory = new ConsoleArmorFactory();
    }
    return itsConsoleArmorFactory;
}

void ConsoleArmorFactory::delInstance() /*static*/
{
    if(itsConsoleArmorFactory)
    {
        delete itsConsoleArmorFactory;
        itsConsoleArmorFactory = NULL;
    }
}

ConsoleArmorFactory::~ConsoleArmorFactory() /*virtual*/
{
}
