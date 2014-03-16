#include "inputchecker.h"

bool InputChecker::isContaineErrorString(std::string str, std::string mask, unsigned int limit)
throw (InputException, InputLimitException)
{
	if(str.size() > limit)
	{
		throw InputLimitException(limit);
	}
	unsigned int currentCount = 0;
	unsigned int count = 0;
	std::string errorString;
	for(unsigned int i = 0; i < str.size(); ++i)
	{
		for(unsigned int j = 0; j < mask.size(); ++j)
		{
			if(str[i] == mask[j])
			{
				++currentCount;
			}
		}
		if(currentCount != count)
		{
			++count;
		}
		else if(limit > 1)
		{
			errorString.push_back(str[i]);
		}
		else
		{
			throw InputException(str, mask);
		}
	}

	if(currentCount != str.size())
	{
		throw InputException(errorString, mask);
	}

	return true;
}
