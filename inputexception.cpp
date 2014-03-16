/*
 * inputexception.cpp
 *
 *  Created on: 16 марта 2014 г.
 *      Author: Сергей
 */

#include "inputexception.h"

InputException::InputException(
		std::string errorString,
		std::string mask,
		std::string message)
: itsErrorString(errorString)
, itsMask(mask)
, itsMessage(message)
{
}

InputException::~InputException()
{
}

std::string InputException::message() const
{
	return itsMessage;
}

std::string InputException::errorString() const
{
	return itsErrorString;
}

std::string InputException::mask() const
{
	return itsMask;
}
