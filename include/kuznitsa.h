#ifndef KUZNITSA_H
#define KUZNITSA_H

#include <string>
#include "dospeh.h"

class Kuznitsa
{
protected:
//    Kuznitsa();
public:
    virtual Dospeh *createDospeh(std::string pro) const = 0;

    virtual ~Kuznitsa();
};

#endif // KUZNITSA_H
