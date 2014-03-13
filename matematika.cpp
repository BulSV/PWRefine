#include "matematika.h"
#include <stdlib.h>
#include <iostream>

float Math_Lib::power(float num, int deg)
{
    if(!deg) return 1.0;
    if(deg > 0)
    {
        for(int i = 1; i < deg; ++i)
        {
            num *= num;
        }
        return num;
    }
    else
    {
        for(int i = 0; i > deg; --i)
        {
            if(i)
            {
                num /= num;
            }
            else
            {
                num = 1/num;
            }
        }
        return num;
    }
}

float Math_Lib::roundFloat(float f, float e)
{
    if(f >= 0)
        return (float)((int)(f/e + 0.5)*e);
    else
        return (float)((int)(f/e - 0.5)*e);
}

int Math_Lib::bin_dexTodex(int bin_dex)
{
    return (((bin_dex & 0xF0)>>4)*10 + (bin_dex & 0x0F));
}

int Math_Lib::round(double d)
{
    if(d > 0)
        return ((int)(d + 0.5));
    else
        return ((int)(d - 0.5));
}

float Math_Lib::round(float f, int prec)
{
    prec = power(10, prec);
    f *= prec;
    f = (float)round(f);

    return f /= prec;
}

int Math_Lib::power(int num, int deg)
{
    int tempNum = 1;

    for(int i = 0; i < deg; ++i)
        tempNum *= num;
    return tempNum;
}

float Math_Lib::decaToSexta(float time)
{
    float hours = (int)time;
    float minuts = (time - (int)time)*0.6;
    time = hours + minuts;
    return time;
}

float Math_Lib::sextaToDeca(float time)
{
    float hours = (int)time;
    float minuts = (time - (int)time)/0.6;
    time = hours + minuts;
    return time;
}

int Math_Lib::stoi(const char* str){
    int number=0;
    int temp;
    int sign=1;
//Проверка на отрицательность
    if(*str=='-'){
        str++;
        sign=-1;
    }
//Преобразование символов строки в разряды числа
    while(*str){
        temp=(int)*str++-48;
        number+=temp;
        number*=10;
    }
    number/=10;
//Проверка на вхождения числа в допустимый диапазон значений
    if((number<-32768)||(number>32767)){
        std::cout<<"Error 1. ";
        std::cout<<"Number overload long int"<<std::endl;
        exit(1); // TODO exit(1)
    }
    return number*sign;
}
