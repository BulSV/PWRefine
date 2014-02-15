#include "../include/kuznitsaozherelyev.h"
#include "../include/ozherelye.h"

KuznitsaOzherelyev::KuznitsaOzherelyev()
{

}

Dospeh *KuznitsaOzherelyev::createDospeh(std::string pro) const /*virtual*/
{
    return new Ozherelye(pro);
}

KuznitsaOzherelyev::~KuznitsaOzherelyev() /*virtual*/
{

}
