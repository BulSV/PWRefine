/*
 * DecodingException.cpp
 *
 *  Created on: 28 апр. 2014
 *      Author: sergey
 */

#include "DecodingException.h"

DecodingException::DecodingException(int errorLetter, std::string message)
: itsErrorLetter(errorLetter)
, itsMessage(message)
{
}

DecodingException::~DecodingException()
{
}

std::string DecodingException::getMessage() const
{
	return itsMessage;
}

int DecodingException::getErrorLetter() const
{
	return itsErrorLetter;
}
