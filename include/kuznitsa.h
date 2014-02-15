#ifndef KUZNITSA_H
#define KUZNITSA_H

#include <string>
#include "dospeh.h"

class Kuznitsa
{
public:
    Kuznitsa();
    Dospeh *createDospeh(std::string pro) const = 0;
    virtual ~Kuznitsa();
};

#endif // KUZNITSA_H
