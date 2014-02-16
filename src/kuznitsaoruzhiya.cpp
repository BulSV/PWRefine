#include "../include/kuznitsaoruzhiya.h"
#include "../include/oruzhie.h"

KuznitsaOruzhiya *KuznitsaOruzhiya::itsKuznitsaOruzhiya = NULL;

KuznitsaOruzhiya::KuznitsaOruzhiya()
{
}

Dospeh *KuznitsaOruzhiya::createDospeh(std::string pro) const /*virtual*/
{
    return new Oruzhie(pro);
}

Kuznitsa *KuznitsaOruzhiya::getInstance() /*static*/
{
    if(!itsKuznitsaOruzhiya)
    {
        itsKuznitsaOruzhiya = new KuznitsaOruzhiya();
    }
    return itsKuznitsaOruzhiya;
}

void KuznitsaOruzhiya::delInstance() /*static*/
{
    if(itsKuznitsaOruzhiya)
    {
        delete itsKuznitsaOruzhiya;
        itsKuznitsaOruzhiya = NULL;
    }
}

KuznitsaOruzhiya::~KuznitsaOruzhiya() /*virtual*/
{
}
