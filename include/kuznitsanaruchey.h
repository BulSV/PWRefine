#ifndef KUZNITSA_NARUCHEY_H
#define KUZNITSA_NARUCHEY_H

#include <string>
#include "kuznitsa.h"

class KuznitsaNaruchey: public Kuznitsa
{
public:
    KuznitsaNaruchey();
    virtual Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaNaruchey();
};

#endif // KUZNITSA_NARUCHEY_H
