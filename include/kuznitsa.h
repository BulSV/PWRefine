#ifndef KUZNITSA_H
#define KUZNITSA_H

#include "dospeh.h"

class Kuznitsa
{
public:
    Kuznitsa(CATEGORY cat, std::string pro);
    Dospeh *dospeh() const;
    ~Kuznitsa();
private:
    Dospeh *itsdospeh;
};

#endif // KUZNITSA_H
