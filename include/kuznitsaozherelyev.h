#ifndef KUZNITSA_OZHERELYEV_H
#define KUZNITSA_OZHERELYEV_H

#include <string>
#include "kuznitsa.h"

class KuznitsaOzherelyev: public Kuznitsa
{
    static KuznitsaOzherelyev *itsKuznitsaOzherelyev;
//protected:
    KuznitsaOzherelyev();
public:
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaOzherelyev();
};

#endif // KUZNITSA_OZHERELYEV_H
