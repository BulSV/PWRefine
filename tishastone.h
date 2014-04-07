#ifndef TISHASTONE_H
#define TISHASTONE_H

#include <iostream>
#include "catalyzerstone.h"
#include "Exceptions/refinelevelexception.h"

class TishaStone : public CatalyzerStone
{
    static std::string CATEGORY;
    std::string itsCategory;
public:
    TishaStone();
    virtual ~TishaStone();
    virtual std::string category() const;
    virtual float addChance(const Armor *armor) const throw(RefineLevelException);
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // TISHASTONE_H
