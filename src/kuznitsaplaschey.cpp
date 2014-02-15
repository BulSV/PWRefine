#include "../include/kuznitsaplaschey.h"
#include "../include/plasch.h"

KuznitsaPlaschey::KuznitsaPlaschey()
{

}

Dospeh *KuznitsaPlaschey::createDospeh(std::string pro) const /*virtual*/
{
    return new Plasch(pro);
}

KuznitsaPlaschey::~KuznitsaPlaschey() /*virtual*/
{

}
