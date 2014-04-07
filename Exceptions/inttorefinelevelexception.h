/*
 * inttorefinelevelexception.h
 *
 *  Created on: 04 апр. 2014 г.
 *      Author: Sergey
 */

#ifndef INTTOREFINELEVELEXCEPTION_H_
#define INTTOREFINELEVELEXCEPTION_H_

#include <string>
#include "../globalenums.h"

class IntToRefineLevelException
{
	std::string itsMessage;
	REFINE_LEVEL itsRefineLevel;
public:
	IntToRefineLevelException(std::string message, REFINE_LEVEL refineLevel);
	~IntToRefineLevelException();
	std::string message() const;
	REFINE_LEVEL refineLevel() const;
};

#endif /* INTTOREFINELEVELEXCEPTION_H_ */
