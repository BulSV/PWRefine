/*
 * stoiexception.h
 *
 *  Created on: 04 апр. 2014 г.
 *      Author: Sergey
 */

#ifndef STOIEXCEPTION_H_
#define STOIEXCEPTION_H_

#include <string>

class StoiException
{
	std::string itsMessage;
	int itsNumber;
public:
	StoiException(std::string message, int number);
	~StoiException();
	const std::string message() const;
	int number() const;
};

#endif /* STOIEXCEPTION_H_ */
