#ifndef CONSOLE_ARMOR
#define CONSOLE_ARMOR

#include "armor.h"


class ConsoleArmor: public Armor
{
public:
    ConsoleArmor(int refineLevel = 0,
                 int requiredMiragecelestone = 1,
                  std::string category = "NO CATEGORY",
                  std::string property = "NO PROPERTY");
    virtual ~ConsoleArmor();
    virtual drawArmor();
};

#endif // CONSOLE_ARMOR
