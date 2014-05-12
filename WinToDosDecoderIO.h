/*
 * WinToDosConvertor.h
 *
 *  Created on: 21 апр. 2014
 *      Author: sergey
 */

#ifndef WINTODOSDECODERIO_H_
#define WINTODOSDECODERIO_H_

#include "DecoderIO.h"
#include "Keys1251to866.h"
#include "Exceptions/DecodingException.h"

class WinToDosDecoderIO: public DecoderIO {
	AbstractIO* itsAbstractIO;
	Keys1251to866* itsKeys;

	char* cp1251to866(char* c) throw(DecodingException);
public:
	WinToDosDecoderIO(AbstractIO* abstractIO);
	virtual ~WinToDosDecoderIO();
	virtual std::string output();
	virtual std::string input(std::string s);
};

#endif /* WINTODOSDECODERIO_H_ */
