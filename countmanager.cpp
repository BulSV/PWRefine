/*
 * countmanager.cpp
 *
 *  Created on: 11 марта 2014 г.
 *      Author: Sergey
 */

#include "countmanager.h"

CountManager::CountManager()
{
}

CountManager::~CountManager()
{
	for(int i = 0; i < size(); ++i)
	{
		deleteArmorFromCount(0);
	}
}

void CountManager::addArmorToCount(Armor* armor)
{
	itsVectorCountHandler.push_back(new CountHandler(armor));
}

CountHandler* CountManager::at(int index) const
{
	return itsVectorCountHandler.at(index);
}

void CountManager::deleteArmorFromCount(int index)
{
	CountHandler *countHandler = itsVectorCountHandler.at(index);
	itsVectorCountHandler.erase(itsVectorCountHandler.begin() + index);
	delete countHandler;
	countHandler = 0;
}

int CountManager::size() const
{
	return itsVectorCountHandler.size();
}

int CountManager::totalMirageCelestone() const
{
	int mirageCelestone = 0;
	for(int i = 0; i < size(); ++i)
	{
		mirageCelestone += at(i)->mirageCelestone();
	}

	return mirageCelestone;
}

int CountManager::totalTienkangStone() const
{
	int tienkangStone = 0;
	for(int i = 0; i < size(); ++i)
	{
		tienkangStone += at(i)->tienkangStone();
	}

	return tienkangStone;
}

int CountManager::totalTishaStone() const
{
	int tishaStone = 0;
	for(int i = 0; i < size(); ++i)
	{
		tishaStone += at(i)->tishaStone();
	}

	return tishaStone;
}

int CountManager::totalChienkunStone() const
{
	int chienkunStone = 0;
	for(int i = 0; i < size(); ++i)
	{
		chienkunStone += at(i)->chienkunStone();
	}

	return chienkunStone;
}
