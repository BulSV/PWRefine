#ifndef KUZNITSA_SAPOG_H
#define KUZNITSA_SAPOG_H

#include <string>
#include "kuznitsa.h"

class KuznitsaSapog: public Kuznitsa
{
public:
    KuznitsaSapog();
    virtual Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaSapog();
};

#endif // KUZNITSA_SAPOG_H
