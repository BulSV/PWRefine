#ifndef KUZNITSA_BRIDGEY_H
#define KUZNITSA_BRIDGEY_H

#include <string>
#include "kuznitsa.h"

class KuznitsaBridgey: public Kuznitsa
{
    static KuznitsaBridgey *itsKuznitsaBridgey;
protected:
    KuznitsaBridgey();
public:    
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaBridgey();
};

#endif // KUZNITSA_BRIDGEY_H
