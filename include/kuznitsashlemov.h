#ifndef KUZNITSA_SHLEMOV_H
#define KUZNITSA_SHLEMOV_H

#include <string>
#include "kuznitsa.h"

class KuznitsaShlemov: public Kuznitsa
{
    static KuznitsaShlemov *itsKuznitsaShlemov;
//protected:
    KuznitsaShlemov();
public:
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaShlemov();
};

#endif // KUZNITSA_SHLEMOV_H
