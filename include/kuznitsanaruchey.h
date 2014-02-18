#ifndef KUZNITSA_NARUCHEY_H
#define KUZNITSA_NARUCHEY_H

#include <string>
#include "kuznitsa.h"

class KuznitsaNaruchey: public Kuznitsa
{
    static KuznitsaNaruchey *itsKuznitsaNaruchey;
//protected:
    KuznitsaNaruchey();
public:
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaNaruchey();
};

#endif // KUZNITSA_NARUCHEY_H
