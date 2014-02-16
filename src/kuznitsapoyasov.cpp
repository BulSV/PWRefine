#include "../include/kuznitsapoyasov.h"
#include "../include/poyas.h"

KuznitsaPoyasov *KuznitsaPoyasov::itsKuznitsaPoyasov = NULL;

KuznitsaPoyasov::KuznitsaPoyasov()
{

}

Dospeh *KuznitsaPoyasov::createDospeh(std::string pro) const /*virtual*/
{
    return new Poyas(pro);
}

Kuznitsa *KuznitsaPoyasov::getInstance() /*static*/
{
    if(!itsKuznitsaPoyasov)
    {
        itsKuznitsaPoyasov = new KuznitsaPoyasov();
    }
    return itsKuznitsaPoyasov;
}

void KuznitsaPoyasov::delInstance() /*static*/
{
    if(itsKuznitsaPoyasov)
    {
        delete itsKuznitsaPoyasov;
        itsKuznitsaPoyasov = NULL;
    }
}

KuznitsaPoyasov::~KuznitsaPoyasov() /*virtual*/
{

}
