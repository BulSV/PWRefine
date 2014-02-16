#ifndef KUZNITSA_POYASOV_H
#define KUZNITSA_POYASOV_H

#include <string>
#include "kuznitsa.h"

class KuznitsaPoyasov: public Kuznitsa
{
    static KuznitsaPoyasov *itsKuznitsaPoyasov;
protected:
    KuznitsaPoyasov();
public:
    virtual Dospeh *createDospeh(std::string pro) const;
    static Kuznitsa *getInstance();
    static void delInstance();
    virtual ~KuznitsaPoyasov();
};

#endif // KUZNITSA_POYASOV_H
