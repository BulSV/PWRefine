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
    int stoi(const char* str);
/*
    //////////////////////////////////////////////////////////////////////////
    // DECLARE_ENUM_OPERATIONS is used to declare enum bitwise operations
    // to use enum type as a type safe flags
    //////////////////////////////////////////////////////////////////////////

#define DECLARE_ENUM_OPERATIONS(ENUM_NAME)                              \\
    inline ENUM_NAME                                                        \\
    operator|(ENUM_NAME left, ENUM_NAME right)                              \\
    { return ENUM_NAME(static_cast<int>(left) | static_cast<int>(right)); } \\
    \\
    inline ENUM_NAME                                                        \\
    operator&(ENUM_NAME left, ENUM_NAME right)                              \\
    { return ENUM_NAME(static_cast<int>(left) & static_cast<int>(right)); } \\
    \\
    inline ENUM_NAME                                                        \\
    operator^(ENUM_NAME left, ENUM_NAME right)                              \\
    { return ENUM_NAME(static_cast<int>(left) ^ static_cast<int>(right)); } \\
    \\
    inline ENUM_NAME                                                        \\
    operator~(ENUM_NAME left)                                               \\
    { return ENUM_NAME(~static_cast<int>(left)); }                          \\
    \\
    inline const ENUM_NAME&                                                 \\
    operator|=(ENUM_NAME& left, ENUM_NAME right)                            \\
    { return left = left | right; }                                         \\
    \\
    inline const ENUM_NAME&                                                 \\
    operator&=(ENUM_NAME& left, ENUM_NAME right)                            \\
    { return left = left & right; }                                         \\
    \\
    inline const ENUM_NAME&                                                 \\
    operator^=(ENUM_NAME& left, ENUM_NAME right)                            \\
    { return left = left ^ right; }                                         \\*/
}

namespace MLib = Math_Lib;

#endif // MATEMATIKA_H
