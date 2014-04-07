/*
 * stoiexception.cpp
 *
 *  Created on: 04 апр. 2014 г.
 *      Author: Sergey
 */

#include "stoiexception.h"

StoiException::StoiException(std::string message, int number)
: itsMessage(message)
, itsNumber(number)
{
}

StoiException::~StoiException()
{
}

const std::string StoiException::message() const
{
	return itsMessage;
}

int StoiException::number() const
{
	return itsNumber;
}
