#ifndef MATEMATIKA_H
#define MATEMATIKA_H


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
}

namespace MLib = Math_Lib;

#endif // MATEMATIKA_H
