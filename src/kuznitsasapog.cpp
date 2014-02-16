#include "../include/kuznitsasapog.h"
#include "../include/sapogi.h"

KuznitsaSapog *KuznitsaSapog::itsKuznitsaSapog = NULL;

KuznitsaSapog::KuznitsaSapog()
{

}

Dospeh *KuznitsaSapog::createDospeh(std::string pro) const /*virtual*/
{
    return new Sapogi(pro);
}

Kuznitsa *KuznitsaSapog::getInstance() /*static*/
{
    if(!itsKuznitsaSapog)
    {
        itsKuznitsaSapog = new KuznitsaSapog();
    }
    return itsKuznitsaSapog;
}

void KuznitsaSapog::delInstance() /*static*/
{
    if(itsKuznitsaSapog)
    {
        delete itsKuznitsaSapog;
        itsKuznitsaSapog = NULL;
    }
}

KuznitsaSapog::~KuznitsaSapog() /*virtual*/
{

}
