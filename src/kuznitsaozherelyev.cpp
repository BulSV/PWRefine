#include "../include/kuznitsaozherelyev.h"
#include "../include/ozherelye.h"

KuznitsaOzherelyev *KuznitsaOzherelyev::itsKuznitsaOzherelyev = NULL;

KuznitsaOzherelyev::KuznitsaOzherelyev()
{

}

Dospeh *KuznitsaOzherelyev::createDospeh(std::string pro) const /*virtual*/
{
    return new Ozherelye(pro);
}

Kuznitsa *KuznitsaOzherelyev::getInstance() /*static*/
{
    if(!itsKuznitsaOzherelyev)
    {
        itsKuznitsaOzherelyev = new KuznitsaOzherelyev();
    }
    return itsKuznitsaOzherelyev;
}

void KuznitsaOzherelyev::delInstance() /*static*/
{
    if(itsKuznitsaOzherelyev)
    {
        delete itsKuznitsaOzherelyev;
        itsKuznitsaOzherelyev = NULL;
    }
}

KuznitsaOzherelyev::~KuznitsaOzherelyev() /*virtual*/
{

}
