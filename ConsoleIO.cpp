/*
 * ConsoleIO.cpp
 *
 *  Created on: 16 апр. 2014
 *      Author: sergey
 */

#include "ConsoleIO.h"

ConsoleIO::ConsoleIO()
: itsString("")
{
}

ConsoleIO::~ConsoleIO()
{
}

std::string ConsoleIO::output()
{
	return itsString;
}

std::string ConsoleIO::input(std::string s)
{
	itsString = s;

	return output();
}
