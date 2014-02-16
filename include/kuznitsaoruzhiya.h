#ifndef KUZNITSA_ORUZHIYA_H
#define KUZNITSA_ORUZHIYA_H

#include <string>
#include "kuznitsa.h"

class KuznitsaOruzhiya: public Kuznitsa
{
    static KuznitsaOruzhiya *itsKuznitsaOruzhiya;
protected:
    KuznitsaOruzhiya();
public:
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaOruzhiya();
};

#endif // KUZNITSA_ORUZHIYA_H
