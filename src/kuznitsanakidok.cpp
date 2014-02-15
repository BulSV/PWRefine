#include "../include/kuznitsanakidok.h"
#include "../include/nakidka.h"

KuznitsaNakidok::KuznitsaNakidok()
{
}

Dospeh *KuznitsaNakidok::createDospeh(std::string pro) const /*virtual*/
{
    return new Nakidka(pro);
}

KuznitsaNakidok::~KuznitsaNakidok() /*virtual*/
{
}
