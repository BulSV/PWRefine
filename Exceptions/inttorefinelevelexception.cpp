/*
 * inttorefinelevelexception.cpp
 *
 *  Created on: 04 ���. 2014 �.
 *      Author: Sergey
 */

#include "inttorefinelevelexception.h"

IntToRefineLevelException::IntToRefineLevelException(std::string message, REFINE_LEVEL refineLevel)
: itsMessage(message)
, itsRefineLevel(refineLevel)
{
}

IntToRefineLevelException::~IntToRefineLevelException()
{
}

std::string IntToRefineLevelException::message() const
{
	return itsMessage;
}

REFINE_LEVEL IntToRefineLevelException::refineLevel() const
{
	return itsRefineLevel;
}
