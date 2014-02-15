#include "../include/kuznitsasapog.h"
#include "../include/sapogi.h"

KuznitsaSapog::KuznitsaSapog()
{

}

Dospeh *KuznitsaSapog::createDospeh(std::string pro) const /*virtual*/
{
    return new Sapogi(pro);
}

KuznitsaSapog::~KuznitsaSapog() /*virtual*/
{

}
