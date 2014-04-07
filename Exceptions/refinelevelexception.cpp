/*
 * commonexception.cpp
 *
 *  Created on: 01 ���. 2014 �.
 *      Author: Sergey
 */

#include "refinelevelexception.h"

RefineLevelException::RefineLevelException(std::string message)
: itsMessage(message)
{
}

RefineLevelException::~RefineLevelException()
{
}

std::string RefineLevelException::message() const
{
	return itsMessage;
}
