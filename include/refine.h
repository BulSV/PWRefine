#ifndef REFINE_H
#define REFINE_H

#include "dospeh.h"

class Refine
{
public:
    Refine();
    ~Refine();
    void goRefining(Dospeh *o, STONES s);
    TOCHKA refineResult() const;
private:
    Dospeh *itsdospeh;
    TOCHKA itsCurRefRes;

    int tochka();
    int verMirazh(int t);
    void tochkaMirazh();
    int verNebeska(int t);
    void tochkaNebeska();
    float verPodzemka(int t);
    void tochkaPodzemka();
    float verMirozdanka(int t);
    void tochkaMirozdanka();
};

#endif // REFINE_H
