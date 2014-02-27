#ifndef TISHASTONE_H
#define TISHASTONE_H

class TishaStone : public Stone
{
    static const float ADD_CHANCE = 3.5;
    float additionalChance;
protected:
    virtual float addChance(int armorLevel);
public:
    TishaStone();
    virtual ~TishaStone();
};

#endif // TISHASTONE_H
