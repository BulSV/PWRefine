/*
 * Utf8ToWinDecoderIO.h
 *
 *  Created on: 21 ���. 2014 �.
 *      Author: sergey
 */

#ifndef UTF8TOWINDECODERIO_H_
#define UTF8TOWINDECODERIO_H_

#include "DecoderIO.h"
#include "KeysUtf8to1251.h"
#include "Exceptions/DecodingException.h"

class Utf8ToWinDecoderIO: public DecoderIO
{
	AbstractIO* itsAbstractIO;
	KeysUtf8to1251* itsKeys;

	char* cpUtf8to1251(int* c, int size);
	int* reverse(int* c, int size);
	int tableCheck(int c) throw (DecodingException);
public:
	Utf8ToWinDecoderIO(AbstractIO* abstractIO);
	virtual ~Utf8ToWinDecoderIO();
	virtual std::string output();
	virtual std::string input(std::string s);
};

#endif /* UTF8TOWINDECODERIO_H_ */
