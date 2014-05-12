/*
 * Keys1251to866.cpp
 *
 *  Created on: 22 ���. 2014 �.
 *      Author: sergey
 */

#include "Keys1251to866.h"

Keys1251to866::Keys1251to866(Key<char, char>* key, int size)
{
	sizeKey = size;
	this->key = key;
}

Keys1251to866::~Keys1251to866()
{
	delete key;
	key = 0;
}

int Keys1251to866::size() const
{
	return sizeKey;
}

Key<char, char> Keys1251to866::getKey(int index) const
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
