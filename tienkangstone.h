#ifndef TIENKANGSTONE_H
#define TIENKANGSTONE_H

#include "catalyzerstone.h"

class TienkangStone : public CatalyzerStone
{
    static std::string CATEGORY;
    std::string itsCategory;
public:
    TienkangStone();
    virtual ~TienkangStone();
    virtual std::string category() const;
    virtual float addChance(const Armor *armor) const;
    virtual REFINE refineRequest(float obtainedChance) const;
};

#endif // TIENKANGSTONE_H
