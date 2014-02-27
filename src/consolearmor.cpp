#include "../include/consolearmor.h"

ConsoleArmor::ConsoleArmor(int requiredMirazh,
                             std::string category,
                             std::string property)
    :Armor(requiredMirazh, category, property)
{
}

ConsoleArmor::~ConsoleArmor() /*virtual*/
{
    //dtor
}

ConsoleArmor::drawArmor() /*virtual*/
{
    std::cout << "CATEGORY: [" << category()
              << "]\n NAME: {" << property()
              << "REFINE LEVEL: <" << tochka()
              << "REQURED MIRAGE CELESTONE: (" << requiredMiragecelestone()
              << ")\n";
}
