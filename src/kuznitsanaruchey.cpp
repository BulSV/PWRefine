#include "../include/kuznitsanaruchey.h"
#include "../include/naruchi.h"

KuznitsaNaruchey *KuznitsaNaruchey::itsKuznitsaNaruchey = NULL;

KuznitsaNaruchey::KuznitsaNaruchey()
{
}

Dospeh *KuznitsaNaruchey::createDospeh(std::string pro) const /*virtual*/
{
    return new Naruchi(pro);
}

Kuznitsa *KuznitsaNaruchey::getInstance() /*static*/
{
    if(!itsKuznitsaNaruchey)
    {
        itsKuznitsaNaruchey = new KuznitsaNaruchey();
    }
    return itsKuznitsaNaruchey;
}

void KuznitsaNaruchey::delInstance() /*static*/
{
    if(itsKuznitsaNaruchey)
    {
        delete itsKuznitsaNaruchey;
        itsKuznitsaNaruchey = NULL;
    }
}

KuznitsaNaruchey::~KuznitsaNaruchey() /*virtual*/
{
}
