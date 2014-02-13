#ifndef KUZNITSA_OZHERELYEV_H
#define KUZNITSA_OZHERELYEV_H

#include <string>
#include "kuznitsa.h"

class KuznitsaOzherelyev: public Kuznitsa
{
public:
    KuznitsaOzherelyev();
    virtual Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaOzherelyev();
};

#endif // KUZNITSA_OZHERELYEV_H
