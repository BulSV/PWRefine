#ifndef KUZNITSA_ORUZHIYA_H
#define KUZNITSA_ORUZHIYA_H

#include <string>
#include "kuznitsa.h"

class KuznitsaOruzhiya: public Kuznitsa
{
public:
    KuznitsaOruzhiya();
    virtual Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaOruzhiya();
};

#endif // KUZNITSA_ORUZHIYA_H
