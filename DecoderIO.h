/*
 * DecoderIO.h
 *
 *  Created on: 21 ���. 2014 �.
 *      Author: sergey
 */

#ifndef DECODERIO_H_
#define DECODERIO_H_

#include "AbstractIO.h"

class DecoderIO: public  AbstractIO
{
public:
	virtual ~DecoderIO();
	virtual std::string output() = 0;
	virtual std::string input(std::string s) = 0;
};

#endif /* DECODERIO_H_ */
