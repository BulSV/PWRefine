/*
 * AbstractIO.cpp
 *
 *  Created on: 16 апр. 2014
 *      Author: sergey
 */

#include "AbstractIO.h"

AbstractIO::~AbstractIO()
{
}

std::istream& operator >> (std::istream& is, AbstractIO* aio)
{
	std::string in;
	std::getline(is, in);
	aio->input(in);

	return is;
}

std::ostream& operator << (std::ostream& os, AbstractIO* aio)
{
	os << aio->output();

	return os;
}
