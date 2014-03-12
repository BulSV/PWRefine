#include "counthandler.h"

CountHandler::CountHandler(Armor *armor)
    : itsArmor(armor)
    , itsMirageCelestone(0)
    , itsTienkangStone(0)
    , itsTishaStone(0)
    , itsChienkunStone(0)
{
}

CountHandler::~CountHandler()
{
	delete itsArmor;
	itsArmor = 0;
}

Armor *CountHandler::armor() const
{
    return itsArmor;
}

void CountHandler::incMirageCelestone()
{
    ++itsMirageCelestone;
}

void CountHandler::incTienkangStone()
{
    ++itsTienkangStone;
}

void CountHandler::incTishaStone()
{
    ++itsTishaStone;
}

void CountHandler::incChienkunStone()
{
    ++itsChienkunStone;
}

int CountHandler::mirageCelestone() const
{
    return itsMirageCelestone;
}

int CountHandler::tienkangStone() const
{
    return itsTienkangStone;
}

int CountHandler::tishaStone() const
{
    return itsTishaStone;
}

int CountHandler::chienkunStone() const
{
    return itsChienkunStone;
}
