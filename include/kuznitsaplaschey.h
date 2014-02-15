#ifndef KUZNITSA_PLASCHEY_H
#define KUZNITSA_PLASCHEY_H

#include <string>
#include "kuznitsa.h"

class KuznitsaPlaschey: public Kuznitsa
{
public:
    KuznitsaPlaschey();
    virtual Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaPlaschey();
};

#endif // KUZNITSA_PLASCHEY_H
