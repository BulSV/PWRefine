#ifndef CHIENKUNSTONE_H
#define CHIENKUNSTONE_H

#include "catalyzerstone.h"

class ChienkunStone : public CatalyzerStone
{
    static std::string CATEGORY;
    std::string itsCategory;
public:
    ChienkunStone();
    virtual ~ChienkunStone();
    virtual std::string category() const;
    virtual float addChance(const Armor* armor) const;
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // CHIENKUNSTONE_H
