/*
 * countmanager.h
 *
 *  Created on: 11 марта 2014 г.
 *      Author: Sergey
 */

#ifndef COUNTMANAGER_H_
#define COUNTMANAGER_H_

#include <vector>
#include "counthandler.h"

class CountManager
{
	std::vector<CountHandler*> itsVectorCountHandler;
public:
	CountManager();
	~CountManager();
	void addArmorToCount(Armor *armor);
	CountHandler *at(int index) const;
	void deleteArmorFromCount(int index);
	int size() const;
	int totalMirageCelestone() const;
	int totalTienkangStone() const;
	int totalTishaStone() const;
	int totalChienkunStone() const;
};

#endif /* COUNTMANAGER_H_ */
