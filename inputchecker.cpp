#include "inputchecker.h"

bool InputChecker::isContaineErrorString()
throw (InputException, InputLimitException)
{
	if(itsString.size() > itsLimit)
		{
			throw InputLimitException(itsLimit);
		}
		unsigned int currentCount = 0;
		unsigned int count = 0;
		std::string errorString;
		for(unsigned int i = 0; i < itsString.size(); ++i)
		{
			for(unsigned int j = 0; j < itsMask.size(); ++j)
			{
				if(itsString[i] == itsMask[j])
				{
					++currentCount;
				}
			}
			if(currentCount != count)
			{
				++count;
			}
			else if(itsLimit > 1)
			{
				errorString.push_back(itsString[i]);
			}
			else
			{
				throw InputException(itsString, itsMask);
			}
		}

		if(currentCount != itsString.size())
		{
			throw InputException(errorString, itsMask);
		}

		return true;
}

bool InputChecker::check(std::string str, std::string mask, unsigned int limit)
{
	itsString = str;
	itsMask = mask;
	itsLimit = limit;

	return isContaineErrorString();
}

std::string InputChecker::str() const
{
	return itsString;
}
