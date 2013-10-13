#ifndef WEAPON_H
#define WEAPON_H

#include "object.h"


class Weapon: public Object
{
public:
    Weapon(std::string pro);
    virtual ~Weapon();
private:
    virtual void incMirazh();
};

#endif // WEAPON_H
