/*
 * Keys1251to866.h
 *
 *  Created on: 22 апр. 2014 г.
 *      Author: sergey
 */

#ifndef KEYS1251TO866_H_
#define KEYS1251TO866_H_

#include "Keys.h"

class Keys1251to866: public Keys<char, char>
{
	Key<char, char>* key;
	int sizeKey;
public:
	Keys1251to866(Key<char, char>* key, int size);
	virtual ~Keys1251to866();
	virtual int size() const;
	virtual Key<char, char> getKey(int index) const;
};

#endif /* KEYS1251TO866_H_ */
