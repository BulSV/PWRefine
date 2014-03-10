#include "iochecker.h"
#include <stdlib.h>

#define BACKSPACE 8
#define ENTER 13

void iochecker::fillUnMaskSmbs()
{
    UnMaksSymStruct smb;
    m_vUnMaskSmbs.clear();
    std::string s = repeatedChars(m_mas, false);

    for(unsigned int i = 0; i < s.size(); ++i)
    {
        smb.name = s.at(i);
        smb.symWas = false;
        m_vUnMaskSmbs.push_back(smb);
    }
}

bool iochecker::emergUnMaskSym(char ch)
{
    for(unsigned int i = 0; i < m_vUnMaskSmbs.size(); ++i)
    {
        if(m_vUnMaskSmbs.at(i).name == ch)
        {
            if(m_vUnMaskSmbs.at(i).symWas)
            {
                return true;
            }
            else
            {
                if(m_buf->size() < m_lim)
                {
                    m_vUnMaskSmbs.at(i).symWas = true;
                }
            }
        }
    }

    return false;
}

void iochecker::unEmergUnMaskSym(char ch)
{
    for(unsigned int i = 0; i < m_vUnMaskSmbs.size(); ++i)
    {
        if(m_vUnMaskSmbs.at(i).name == ch)
        {
            m_vUnMaskSmbs.at(i).symWas = false;
        }
    }
}

void iochecker::fillBufOrigin()
{
    m_bufOrigin->clear();
    for(unsigned int i = 0; i < m_buf->size(); ++i)
    {
        m_bufOrigin->push_back(m_buf->at(i));
    }
}

void iochecker::checker(int ch)
{
    if(eqSym(repeatedChars(m_mas), ch) &&
            (!eqSym(repeatedChars(m_mas, false), ch) || !emergUnMaskSym(ch)) &&
            m_buf->size() < m_lim)
    {
        std::cout << (char)ch;
        m_buf->push_back(ch);
        checker(_getch());
    }
    else
    {
        switch(ch)
        {
        case BACKSPACE:
        {
            std::cout << (char)BACKSPACE << ' ' << (char)BACKSPACE;
            if(m_buf->size())
            {
                if(emergUnMaskSym(m_buf->at(m_buf->size() - 1)))
                {
                    unEmergUnMaskSym(m_buf->at(m_buf->size() - 1));
                }
                if(m_buf->size() > 0)
                {
                    m_buf->pop_back();
                }
            }
            checker(_getch());
            break;
        }
        case ENTER:
        {
            std::cin.putback(ch);
            break;
        }
        default:
        {
            checker(_getch());
        }
        }
    }
    fillBufOrigin();
}

std::ostream &operator <<(std::ostream &output, const iochecker &o)
{
    output << o.m_outputSymLim << o.m_lim;
    output << o.m_outputCheckMass << o.m_mas;
    output << o.m_outputSym;
    for(unsigned int index = 0; index < o.m_buf->size(); ++index)
    {
        output << "|" << o.m_buf->at(index);
    }
    output << "|" << std::endl;

    return output;
}

bool iochecker::eqSym(const char *mas, const char &ch)
{
    while(*mas)
    {
        if(*mas == ch)
        {
            return true;
        }
        ++mas;
    }
    return false;
}

int iochecker::eqSymIndex(const char* mas,
                          const char &ch,
                          int beginIndex)
{
    int symIndex = beginIndex;
    if(beginIndex < 0) return -1; /// protect from dummy input
    while(beginIndex-- && mas++)
    {}
    while(*mas)
    {
        if(*mas == ch)
        {
            return symIndex;
        }
        ++mas;
        ++symIndex;
    }
    return -1;
}

const char* iochecker::repeatedChars(const char* in, bool mask)
{
    std::string unRptMask;
    std::string symMask = in;

    for(unsigned int i = 0; i < symMask.size(); ++i)
    {
        for(unsigned int j = i + 1; j < symMask.size(); ++j)
        {
            if(symMask.at(i) == symMask.at(j))
            {
                unRptMask.push_back(symMask.at(j));
                symMask.erase(j, 1);
                --j;
            }
        }
    }

    if(!mask)
    {
        return repeatedChars(unRptMask.c_str());
    }

    return symMask.c_str();
}

bool iochecker::isDigit(const char *c)
{
    while(*c)
    {
        if(*c < 48 || *c > 57)
        {
            return false;
        }
        ++c;
    }

    return true;
}

int iochecker::stoi(const char *str)
{
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
        exit(1);
    }

    return number*sign;
}

iochecker::iochecker(int lim,
                     std::vector<char> *buf,
                     const char *mas)
    : m_lim(lim)
    , m_buf(buf)
    , m_bufOrigin(new std::vector<char>)
    , m_mas(mas)
    , m_inputSymLim("Input symbols limit: ")
    , m_inputCheckMass("Input check massive: ")
    , m_inputSym("Input symbols for checking: ")
    , m_outputSymLim("\nsymbols limit: ")
    , m_outputCheckMass("\ncheck massive: ")
    , m_outputSym("\ninput symbols: ")
{
    fillUnMaskSmbs();
}

iochecker::iochecker(int lim,
                     std::vector<char> *buf,
                     const char *mas,
                     const char *inputSymLim,
                     const char *inputCheckMass,
                     const char *inputSym,
                     const char *outputSymLim,
                     const char *outputCheckMass,
                     const char *outputSym)
    : m_lim(lim)
    , m_buf(buf)
    , m_bufOrigin(new std::vector<char>)
    , m_mas(mas)
    , m_inputSymLim(inputSymLim)
    , m_inputCheckMass(inputCheckMass)
    , m_inputSym(inputSym)
    , m_outputSymLim(outputSymLim)
    , m_outputCheckMass(outputCheckMass)
    , m_outputSym(outputSym)
{
    fillUnMaskSmbs();
}

iochecker::~iochecker()
{
    delete m_bufOrigin;
}

void iochecker::check(int ch)
{
    if(eqSym(m_mas, ch))
    {
        checker(ch);

    }
    else
    {
        check(_getch());
    }
}

std::istream &operator >>(std::istream &input, iochecker &o)
{
    std::cout << o.m_inputSymLim;
    input >> o.m_lim;
    std::cout << o.m_inputCheckMass;
    std::cin.ignore();
    std::string s;
    getline(input, s);
    o.m_mas = const_cast<char*>(s.c_str());
    o.fillUnMaskSmbs();
    std::cout << o.m_inputSym;
    o.check(_getch());

    return input;
}

void iochecker::leadingZeros()
{
    while(m_buf->at(0) == '0' && m_buf->size() > 1 && m_buf->at(1) != '.')
    {
        m_buf->erase(m_buf->begin());
    }
}

void iochecker::trailingZeros()
{
    bool dot = false;
    unsigned int i = 0;
    while(i < m_buf->size() && !dot)
    {
        if(m_buf->at(i++) == '.')
        {
            dot = true;
        }
    }
    while(m_buf->at(m_buf->size() - 1) == '0' && dot && m_buf->size() > 1)
    {
        m_buf->erase(m_buf->end() - 1);
    }
}

std::vector<char> iochecker::buffer(ZEROFLAGS zeros)
{
    if((zeros == LEADING) && m_buf->size() > 1)
    {
        leadingZeros();

        return *m_buf;
    }

    if((zeros == TRAILING) && m_buf->size() > 1)
    {
        trailingZeros();

        return *m_buf;
    }

    if((zeros == ALLZEROS) && m_buf->size() > 1)
    {
        leadingZeros();
        trailingZeros();

        return *m_buf;
    }

    return *m_bufOrigin;
}

std::string iochecker::stringBuffer(ZEROFLAGS zeros)
{
    std::string s;

    buffer(zeros);


    if(zeros == NOCHANGED)
    {
        for(unsigned int index = 0; index < m_bufOrigin->size(); ++index)
        {
            s.push_back(m_bufOrigin->at(index));
        }
    }
    else
    {
        for(unsigned int index = 0; index < m_buf->size(); ++index)
        {
            s.push_back(m_buf->at(index));
        }
    }

    return s;
}

const char *iochecker::charBuffer(ZEROFLAGS zeros)
{
    return stringBuffer(zeros).c_str();
}

void iochecker::setInputMessages(const char *inputSymLim,
                                 const char *inputCheckMass,
                                 const char *inputSym)
{
    m_inputSymLim = inputSymLim;
    m_inputCheckMass = inputCheckMass;
    m_inputSym = inputSym;
}

void iochecker::setOutputMessages(const char *outputSymLim,
                                  const char *outputCheckMass,
                                  const char *outputSym)
{
    m_outputSymLim = outputSymLim;
    m_outputCheckMass = outputCheckMass;
    m_outputSym = outputSym;
}

void iochecker::setBuffer(std::vector<char> v)
{
    if(v.empty())
    {
        return;
    }
    m_buf->clear();
    for(unsigned i = 0; i < v.size(); ++i)
    {
        m_buf->push_back(v.at(i));
    }
}

void iochecker::setStringBuffer(std::string s)
{
    if(s.empty())
    {
        return;
    }
    m_buf->clear();
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        m_buf->push_back(s.at(i));
    }
}

void iochecker::setCharBuffer(const char *c)
{
    if(!*c)
    {
        return;
    }
    m_buf->clear();
    unsigned i = 0;
    while(c[i])
    {
        m_buf->push_back(c[i++]);
    }
}
