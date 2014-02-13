#ifndef WEAPON_H
#define WEAPON_H

#include "dospeh.h"


class Oruzhie: public Dospeh
{
public:
    Oruzhie(std::string pro);
    virtual ~Oruzhie();
private:
    virtual void incMirazh();
};

#endif // WEAPON_H
