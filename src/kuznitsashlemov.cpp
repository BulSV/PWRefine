#include "../include/kuznitsashlemov.h"
#include "../include/shlem.h"

KuznitsaShlemov::KuznitsaShlemov()
{

}

Dospeh *KuznitsaShlemov::createDospeh(std::string pro) const /*virtual*/
{
    return new Shlem(pro);
}

KuznitsaShlemov::~KuznitsaShlemov() /*virtual*/
{

}
