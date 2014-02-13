#ifndef KUZNITSA_NAKIDOK_H
#define KUZNITSA_NAKIDOK_H

#include <string>
#include "kuznitsa.h"

class KuznitsaNakidok: public Kuznitsa
{
public:
    KuznitsaNakidok();
    virtual Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaNakidok();
};

#endif // KUZNITSA_NAKIDOK_H
