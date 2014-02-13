#ifndef KUZNITSA_POYASOV_H
#define KUZNITSA_POYASOV_H

#include <string>
#include "kuznitsa.h"

class KuznitsaPoyasov: public Kuznitsa
{
public:
    KuznitsaPoyasov();
    virtual Dospeh *createDospeh(std::string pro) const;
    virtual ~KuznitsaPoyasov();
};

#endif // KUZNITSA_POYASOV_H
