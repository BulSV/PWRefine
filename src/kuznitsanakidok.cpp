#include "../include/kuznitsanakidok.h"
#include "../include/nakidka.h"

KuznitsaNakidok *KuznitsaNakidok::itsKuznitsaNakidok = NULL;

KuznitsaNakidok::KuznitsaNakidok()
{
}

Dospeh *KuznitsaNakidok::createDospeh(std::string pro) const /*virtual*/
{
    return new Nakidka(pro);
}

Kuznitsa *KuznitsaNakidok::getInstance() /*static*/
{
    if(!itsKuznitsaNakidok)
    {
        itsKuznitsaNakidok = new KuznitsaNakidok();
    }
    return itsKuznitsaNakidok;
}

void KuznitsaNakidok::delInstance() /*static*/
{
    if(itsKuznitsaNakidok)
    {
        delete itsKuznitsaNakidok;
        itsKuznitsaNakidok = NULL;
    }
}

KuznitsaNakidok::~KuznitsaNakidok() /*virtual*/
{
}
