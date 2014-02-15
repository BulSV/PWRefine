#include "../include/kuznitsapoyasov.h"
#include "../include/poyas.h"

KuznitsaPoyasov::KuznitsaPoyasov()
{

}

Dospeh *KuznitsaPoyasov::createDospeh(std::string pro) const /*virtual*/
{
    return new Poyas(pro);
}

KuznitsaPoyasov::~KuznitsaPoyasov() /*virtual*/
{

}
