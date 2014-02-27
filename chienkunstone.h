#ifndef CHIENKUNSTONE_H
#define CHIENKUNSTONE_H

class ChienkunStone : public Stone
{
protected:
    virtual float addChance(int armorLevel);
public:
    ChienkunStone();
    virtual ~ChienkunStone();
};

#endif // CHIENKUNSTONE_H
