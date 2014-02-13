#include "../include/kuznitsanaruchey.h"
#include "../include/naruchi.h"

KuznitsaNaruchey::KuznitsaNaruchey()
{
}

Dospeh *KuznitsaNaruchey::createDospeh(std::string pro) const /*virtual*/
{
    return new Naruchi(pro);
}

KuznitsaNaruchey::~KuznitsaNaruchey() /*virtual*/
{
}
