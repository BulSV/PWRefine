/*
 * inputexception.h
 *
 *  Created on: 16 марта 2014 г.
 *      Author: Сергей
 */

#ifndef INPUTEXCEPTION_H_
#define INPUTEXCEPTION_H_

#include <string>

class InputException
{
	std::string itsErrorString;
	std::string itsMask;
	std::string itsMessage;
public:
	InputException(std::string errorString,
			std::string mask,
			std::string message = "");
	~InputException();
	std::string message() const;
	std::string errorString() const;
	std::string mask() const;
};

#endif /* INPUTEXCEPTION_H_ */
