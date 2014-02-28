#include "consolearmor.h"

ConsoleArmor::ConsoleArmor(int refineLevel,
                           int requiredMirazh,
                           std::string category,
                           std::string property)
    :Armor(refineLevel,
           requiredMirazh,
           category,
           property)
{
}

ConsoleArmor::~ConsoleArmor() /*virtual*/
{
}

ConsoleArmor::drawArmor() /*virtual*/
{
    std::cout << "CATEGORY: [" << category()
              << "]\n NAME: {" << property()
              << "REFINE LEVEL: <" << refineLevel()
              << "REQURED MIRAGE CELESTONE: (" << requiredMiragecelestone()
              << ")\n";
}
