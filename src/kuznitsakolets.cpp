#include "../include/kuznitsakolets.h"
#include "../include/koltso.h"

KuznitsaKolets *KuznitsaKolets::itsKuznitsaKolets = NULL;

KuznitsaKolets::KuznitsaKolets()
{
}

Dospeh *KuznitsaKolets::createDospeh(std::string pro) const /*virtual*/
{
    return new Koltso(pro);
}

Kuznitsa *KuznitsaKolets::getInstance() /*static*/
{
    if(!itsKuznitsaKolets)
    {
        itsKuznitsaKolets = new KuznitsaKolets();
    }
    return itsKuznitsaKolets;
}

void KuznitsaKolets::delInstance() /*static*/
{
    if(itsKuznitsaKolets)
    {
        delete itsKuznitsaKolets;
        itsKuznitsaKolets = NULL;
    }
}

KuznitsaKolets::~KuznitsaKolets() /*virtual*/
{
}
