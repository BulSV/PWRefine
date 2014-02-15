#ifndef KUZNITSA_SHLEMOV_H
#define KUZNITSA_SHLEMOV_H

#include <string>
#include "kuznitsa.h"

class KuznitsaShlemov: public Kuznitsa
{
public:
    KuznitsaShlemov();
    virtual Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaShlemov();
};

#endif // KUZNITSA_SHLEMOV_H
