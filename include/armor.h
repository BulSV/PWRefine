#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include "globalenums.h"

class Armor
{
public:
    Armor(int requiredMiragecelestone = 1,
           std::string category = "NO CATEGORY",
           std::string property = "NO PROPERTY");
    virtual ~Armor();
    std::string category() const;
    std::string property() const;
    void setToch(REFINE resTochka);
    int tochka() const;
    int requiredMiragecelestone() const;
    virtual void drawDospeh() = 0;
private:
    std::string itsCategory;
    std::string itsProperty;
    int itsTochka;
    int itsRequiredMirazh;

    void setTochka(int tochka);
};

#endif // ARMOR_H
