/*
 * Keys.h
 *
 *  Created on: 21 ���. 2014 �.
 *      Author: sergey
 */

#ifndef KEYS_H_
#define KEYS_H_

#include "Key.h"

template<class T, class H>
class Keys
{
public:
	virtual ~Keys(){}
	virtual int size() const = 0;
	virtual Key<T, H> getKey(int index) const = 0;
};

#endif /* KEYS_H_ */
