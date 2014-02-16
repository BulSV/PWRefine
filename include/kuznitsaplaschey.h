#ifndef KUZNITSA_PLASCHEY_H
#define KUZNITSA_PLASCHEY_H

#include <string>
#include "kuznitsa.h"

class KuznitsaPlaschey: public Kuznitsa
{
    static KuznitsaPlaschey *itsKuznitsaPlaschey;
protected:
    KuznitsaPlaschey();
public:
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaPlaschey();
};

#endif // KUZNITSA_PLASCHEY_H
