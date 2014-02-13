#include "../include/kuznitsabridgey.h"
#include "../include/bridgy.h"

KuznitsaBridgey::KuznitsaBridgey()
{
}

Dospeh *KuznitsaBridgey::createDospeh(std::string pro) const
{
    return new Bridgy(pro);
}

KuznitsaBridgey::~KuznitsaBridgey()
{
}
