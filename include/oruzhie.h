#ifndef WEAPON_H
#define WEAPON_H

#include "dospeh.h"


class Weapon: public Dospeh
{
public:
    Weapon(std::string pro);
    virtual ~Weapon();
private:
    virtual void incMirazh();
};

#endif // WEAPON_H
