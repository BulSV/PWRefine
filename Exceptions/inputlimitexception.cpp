/*
 * inputlimitexception.cpp
 *
 *  Created on: 16 марта 2014 г.
 *      Author: Сергей
 */

#include "inputlimitexception.h"

InputLimitException::InputLimitException(unsigned int limit, std::string message)
: itsLimit(limit)
, itsMessage(message)
{
}

unsigned int InputLimitException::limit() const
{
	return itsLimit;
}

InputLimitException::~InputLimitException()
{
}

std::string InputLimitException::message() const
{
	return itsMessage;
}
