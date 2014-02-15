#ifndef KUZNITSA_BRIDGEY_H
#define KUZNITSA_BRIDGEY_H

#include <string>
#include "kuznitsa.h"

class KuznitsaBridgey: public Kuznitsa
{
public:
    KuznitsaBridgey();
    Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaBridgey();
};

#endif // KUZNITSA_BRIDGEY_H
