#ifndef KUZNITSA_KOLETS_H
#define KUZNITSA_KOLETS_H

#include <string>
#include "kuznitsa.h"

class KuznitsaKolets: public Kuznitsa
{
    static KuznitsaKolets *itsKuznitsaKolets;
protected:
    KuznitsaKolets();
public:    
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaKolets();
};

#endif // KUZNITSA_KOLETS_H
