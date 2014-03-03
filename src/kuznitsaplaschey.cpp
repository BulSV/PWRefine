#include "../include/kuznitsaplaschey.h"
#include "../include/plasch.h"

KuznitsaPlaschey *KuznitsaPlaschey::itsKuznitsaPlaschey = NULL;

KuznitsaPlaschey::KuznitsaPlaschey()
{

}

Dospeh *KuznitsaPlaschey::createDospeh(std::string pro) const /*virtual*/
{
    return new Plasch(pro);
}

Kuznitsa *KuznitsaPlaschey::getInstance() /*static*/
{
    if(!itsKuznitsaPlaschey)
    {
        itsKuznitsaPlaschey = new KuznitsaPlaschey();
    }
    return itsKuznitsaPlaschey;
}

void KuznitsaPlaschey::delInstance() /*static*/
{
    if(itsKuznitsaPlaschey)
    {
        delete itsKuznitsaPlaschey;
        itsKuznitsaPlaschey = NULL;
    }
}

KuznitsaPlaschey::~KuznitsaPlaschey() /*virtual*/
{

}
