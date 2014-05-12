/*
 * KeysUtf8to1251.cpp
 *
 *  Created on: 23 ���. 2014 �.
 *      Author: sergey
 */

#include "KeysUtf8to1251.h"

KeysUtf8to1251::KeysUtf8to1251(Key<int, char>* key, int size)
{
	sizeKey = size;
	this->key = key;
}

KeysUtf8to1251::~KeysUtf8to1251()
{
	delete key;
	key = 0;
}

int KeysUtf8to1251::size() const
{
	return sizeKey;
}

Key<int, char> KeysUtf8to1251::getKey(int index) const
{
	if(index >= 0 && index < sizeKey)
	{
		return key[index];
	}
	else if(index < 0)
	{
		return key[0];
	}
	else
	{
		return key[sizeKey - 1];
	}
}
