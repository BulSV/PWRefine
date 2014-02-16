#include "../include/kuznitsabridgey.h"
#include "../include/bridgy.h"

KuznitsaBridgey *KuznitsaBridgey::itsKuznitsaBridgey = NULL;

KuznitsaBridgey::KuznitsaBridgey()
{
}

Dospeh *KuznitsaBridgey::createDospeh(std::string pro) const /*virtual*/
{
    return new Bridgy(pro);
}

Kuznitsa *KuznitsaBridgey::getInstance() /*static*/
{
    if(!itsKuznitsaBridgey)
    {
        itsKuznitsaBridgey = new KuznitsaBridgey();
    }
    return itsKuznitsaBridgey;
}

void KuznitsaBridgey::delInstance() /*static*/
{
    if(itsKuznitsaBridgey)
    {
        delete itsKuznitsaBridgey;
        itsKuznitsaBridgey = NULL;
    }
}

KuznitsaBridgey::~KuznitsaBridgey() /*virtual*/
{   
}
