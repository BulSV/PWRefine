/*
 * refinelevelexception.h
 *
 *  Created on: 01 апр. 2014 г.
 *      Author: Sergey
 */

#ifndef REFINELEVELEXCEPTION_H_
#define REFINELEVELEXCEPTION_H_

#include <string>

class RefineLevelException
{
	std::string itsMessage;
public:
	RefineLevelException(std::string message);
	~RefineLevelException();
	std::string message() const;
};

#endif /* REFINELEVELEXCEPTION_H_ */
