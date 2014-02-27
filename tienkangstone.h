#ifndef TIENKANGSTONE_H
#define TIENKANGSTONE_H

class TienkangStone : public Stone
{
    static const float ADD_CHANCE = 15.0;
    float additionalChance;
protected:
    virtual float addChance(int armorLevel);
public:
    TienkangStone();
    virtual ~TienkangStone();
};

#endif // TIENKANGSTONE_H
