#ifndef DOSPEH_H
#define DOSPEH_H

#include <string>

enum CATEGORY
{
    NOCATEGORY,
    WEAPON,
    SHLEM,
    NAKIDKA,
    BRIDGY,
    SAPOGI,
    NARUCHI,
    PLASCH,
    OZHERELYE,
    POYAS,
    RING
};

enum TOCHKA
{
    RESET,
    NEUDACH,
    NEIZMEN,
    UDACH
};

enum STONES
{
    NOSTONE,
    NEBESKA,
    PODZEMKA,
    MIROZDANKA
};

class Dospeh
{
public:
    Dospeh();
    virtual ~Dospeh();
    void refine(TOCHKA toch, STONES st);
    CATEGORY cat() const;
    std::string pro() const;
    void setToch(int tochka);
    int toch() const;
    int mirazh() const;
    int nebeska() const;
    int podzemka() const;
    int mirozdanka() const;
protected:
    int itsMirazhey;
    int itsNebesok;
    int itsPodzemok;
    int itsMirozdanok;
    CATEGORY itsCategory;
    std::string itsProperty;
    int itsTochka;

    virtual void incMirazh();
    virtual void incNebeska();
    virtual void incPodzemka();
    virtual void incMirozdanka();
};

#endif // DOSPEH_H
