#ifndef KUZNITSA_NAKIDOK_H
#define KUZNITSA_NAKIDOK_H

#include <string>
#include "kuznitsa.h"

class KuznitsaNakidok: public Kuznitsa
{
    static KuznitsaNakidok *itsKuznitsaNakidok;
//protected:
    KuznitsaNakidok();
public:
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaNakidok();
};

#endif // KUZNITSA_NAKIDOK_H
