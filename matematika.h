#ifndef MATEMATIKA_H
#define MATEMATIKA_H

#include "Exceptions/stoiexception.h"

namespace Math_Lib
{
    float power(float num, int deg);
    float roundFloat(float f, float e);
    int bin_dexTodex(int bin_dex);
    int round(double d);
    float round(float f, int prec);
    int power(int num, int deg);
    float decaToSexta(float time);
    float sextaToDeca(float time);
    int stoi(const char* str) throw(StoiException);
}

namespace MLib = Math_Lib;

#endif // MATEMATIKA_H
