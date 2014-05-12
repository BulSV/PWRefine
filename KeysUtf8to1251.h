/*
 * KeysUtf8to1251.h
 *
 *  Created on: 23 апр. 2014 г.
 *      Author: sergey
 */

#ifndef KEYSUTF8TO1251_H_
#define KEYSUTF8TO1251_H_

#include "Keys.h"

class KeysUtf8to1251: public Keys<int, char>
{
	Key<int, char>* key;
	int sizeKey;
public:
	KeysUtf8to1251(Key<int, char>* key, int size);
	virtual ~KeysUtf8to1251();
	virtual int size() const;
	virtual Key<int, char> getKey(int index) const;
};

#endif /* KEYSUTF8TO1251_H_ */
