#ifndef KUZNITSA_SAPOG_H
#define KUZNITSA_SAPOG_H

#include <string>
#include "kuznitsa.h"

class KuznitsaSapog: public Kuznitsa
{
    static KuznitsaSapog *itsKuznitsaSapog;
//protected:
    KuznitsaSapog();
public:
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaSapog();
};

#endif // KUZNITSA_SAPOG_H
