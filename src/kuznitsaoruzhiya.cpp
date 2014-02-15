#include "../include/kuznitsaoruzhiya.h"
#include "../include/oruzhie.h"

KuznitsaOruzhiya::KuznitsaNaruchey()
{
}

Dospeh *KuznitsaOruzhiya::createDospeh(std::string pro) const /*virtual*/
{
    return new Oruzhie(pro);
}

KuznitsaOruzhiya::~KuznitsaOruzhiya() /*virtual*/
{
}
