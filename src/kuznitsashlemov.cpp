#include "../include/kuznitsashlemov.h"
#include "../include/shlem.h"
KuznitsaShlemov *KuznitsaShlemov::itsKuznitsaShlemov = NULL;

KuznitsaShlemov::KuznitsaShlemov()
{

}

Dospeh *KuznitsaShlemov::createDospeh(std::string pro) const /*virtual*/
{
    return new Shlem(pro);
}

Kuznitsa *KuznitsaShlemov::getInstance() /*static*/
{
    if(!itsKuznitsaShlemov)
    {
        itsKuznitsaShlemov = new KuznitsaShlemov();
    }
    return itsKuznitsaShlemov;
}

void KuznitsaShlemov::delInstance() /*static*/
{
    if(itsKuznitsaShlemov)
    {
        delete itsKuznitsaShlemov;
        itsKuznitsaShlemov = NULL;
    }
}

KuznitsaShlemov::~KuznitsaShlemov() /*virtual*/
{

}
