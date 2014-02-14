#ifndef KUZNITSA_KOLETS_H
#define KUZNITSA_KOLETS_H

#include <string>
#include "kuznitsa.h"

class KuznitsaKolets: public Kuznitsa
{
public:
    KuznitsaKolets();

    virtual Dospeh *createDospeh(std::string pro) const;

    virtual ~KuznitsaKolets();
};

#endif // KUZNITSA_KOLETS_H
