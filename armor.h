#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include "globalenums.h"
#include "ArmorCategory.h"

class Armor
{
public:
    Armor(REFINE_LEVEL refineLevel = T0,
          int requiredMiragecelestone = 1,
          ArmorCategory category = ArmorCategory("NO CATEGORY"),
          std::string property = "NO PROPERTY");
    virtual ~Armor();
    std::string category() const;
    std::string property() const;
    void setRefineLevel(REFINE resRefine);
    REFINE_LEVEL refineLevel() const;
    int requiredMirageCelestone() const;

	REFINE_LEVEL wasRefineLevel() const;

private:
    ArmorCategory itsCategory;
    std::string itsProperty;
    REFINE_LEVEL itsRefineLevel;
    int itsRequiredMiragecelestone;
    REFINE_LEVEL itsWasRefineLevel;

    void setRefineLevel(REFINE_LEVEL refineLevel);

};

#endif // ARMOR_H
