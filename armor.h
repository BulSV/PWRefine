#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include "globalenums.h"

class Armor
{
    static const int MAX_REFINE_LEVEL = 12;
    static const int MIN_REFINE_LEVEL = 0;
public:
    Armor(int requiredMiragecelestone = 1,
          std::string category = "NO CATEGORY",
          std::string property = "NO PROPERTY");
    virtual ~Armor();
    std::string category() const;
    std::string property() const;
    void setRefine(REFINE resRefine);
    int refine() const;
    int requiredMirageCelestone() const;
    virtual void drawDospeh() = 0;
private:
    std::string itsCategory;
    std::string itsProperty;
    int itsRefine;
    int itsRequiredMirazh;

    void setRefine(int refine);
};

#endif // ARMOR_H
