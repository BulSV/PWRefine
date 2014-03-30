/*
 * inputexception.cpp
 *
 *  Created on: 16 ����� 2014 �.
 *      Author: ������
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
