#ifndef IOCHECKER_H
#define IOCHECKER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

class iochecker
{
    unsigned int m_lim;
    std::vector<unsigned char> *m_buf;
    std::vector<unsigned char> *m_bufOrigin;
    const char *m_mas;
    void fillUnMaskSmbs();
    bool emergUnMaskSym(unsigned char ch);
    void unEmergUnMaskSym(unsigned char ch);
    void checker(unsigned int ch);
    void fillBufOrigin();
    void leadingZeros();
    void trailingZeros();
    struct UnMaksSymStruct
    {
        bool symWas;
        char name;
    };
    const char* m_inputSymLim;
    const char* m_inputCheckMass;
    const char* m_inputSym;
    const char* m_outputSymLim;
    const char* m_outputCheckMass;
    const char* m_outputSym;
    std::vector<UnMaksSymStruct> m_vUnMaskSmbs;
public:
    iochecker(unsigned int lim,
              std::vector<unsigned char> *buf,
              const char *mas);
    iochecker(unsigned int lim,
              std::vector<unsigned char> *buf,
              const char *mas,
              const char* inputSymLim,
              const char* inputCheckMass,
              const char* inputSym,
              const char* outputSymLim,
              const char* outputCheckMass,
              const char* outputSym);
    ~iochecker();
    enum ZEROFLAGS
    {
        LEADING = 0x01,
        TRAILING = 0x02,
        ALLZEROS = LEADING | TRAILING,
        NOCHANGED = -1
    };
    void check(unsigned int ch);
    friend std::ostream &operator <<(std::ostream &output, const iochecker &o);
    friend std::istream &operator >>(std::istream &input, iochecker &o);
    void setInputMessages(const char* inputSymLim,
                          const char* inputCheckMass,
                          const char* inputSym);
    void setOutputMessages(const char* outputSymLim,
                          const char* outputCheckMass,
                          const char* outputSym);
    void setBuffer(std::vector<unsigned char> v);
    void setStringBuffer(std::string s);
    void setCharBuffer(const char* c);
    std::vector<unsigned char> buffer(ZEROFLAGS zeros = NOCHANGED);
    std::string stringBuffer(ZEROFLAGS zeros = NOCHANGED);
    const char *charBuffer(ZEROFLAGS zeros = NOCHANGED);
    static bool eqSym(const char *mas, const unsigned char &ch);
    static int eqSymIndex(const char* mas,
               const unsigned char &ch,
               unsigned int beginIndex = 0);
    static const char* repeatedChars(const char* in, bool mask = true);
    static bool isDigit(const char* c);
    static int stoi(const char* str);
};

#endif // IOCHECKER_H
