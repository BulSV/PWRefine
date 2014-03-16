#ifndef IOCHECKER_H
#define IOCHECKER_H

#include <string>
#include "inputexception.h"
#include "inputlimitexception.h"

class InputChecker
{
public:
    static bool isContaineErrorString(std::string str, std::string mask, unsigned int limit)
    throw (InputException, InputLimitException);
};

#endif // IOCHECKER_H
