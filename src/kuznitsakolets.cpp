#include "../include/kuznitsakolets.h"
#include "../include/koltso.h"

KuznitsaKolets::KuznitsaKolets()
{
}

Dospeh *KuznitsaKolets::createDospeh(std::string pro) const
{
    return new Koltso(pro);
}

KuznitsaKolets::~KuznitsaKolets() /*virtual*/
{
}
