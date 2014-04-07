#ifndef IOCHECKER_H
#define IOCHECKER_H

#include <string>
#include "Exceptions/inputexception.h"
#include "Exceptions/inputlimitexception.h"

class InputChecker
{
	std::string itsString;
	std::string itsMask;
	unsigned int itsLimit;

	bool isContaineErrorString()
	throw (InputException, InputLimitException);
public:
	bool check(std::string str, std::string mask, unsigned int limit);
	std::string str() const;
};

#endif // IOCHECKER_H
