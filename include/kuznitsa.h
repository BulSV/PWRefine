#ifndef KUZNITSA_H
#define KUZNITSA_H

#include "object.h"

class Kuznitsa
{
public:
    Kuznitsa(CATEGORY cat, std::string pro);
    Object *object() const;
    ~Kuznitsa();
private:
    Object *itsObject;
};

#endif // KUZNITSA_H
