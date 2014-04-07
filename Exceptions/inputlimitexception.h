/*
 * inputlimitexception.h
 *
 *  Created on: 16 ����� 2014 �.
 *      Author: ������
 */

#ifndef INPUTLIMITEXCEPTION_H_
#define INPUTLIMITEXCEPTION_H_

#include <string>

class InputLimitException
{
	unsigned int itsLimit;
	std::string itsMessage;
public:
	InputLimitException(unsigned int limit, std::string message = "");
	~InputLimitException();
	unsigned int limit() const;
	std::string message() const;
};

#endif /* INPUTLIMITEXCEPTION_H_ */
