/*
 * AbstractIO.h
 *
 *  Created on: 16 апр. 2014
 *      Author: sergey
 */

#ifndef ABSTRACTIO_H_
#define ABSTRACTIO_H_

#include <istream>
#include <ostream>
#include <string>
#include <iostream>

class AbstractIO {
	friend std::istream& operator >> (std::istream& is, AbstractIO* aio);
	friend std::ostream& operator << (std::ostream& os, AbstractIO* aio);
public:
	virtual ~AbstractIO();
	virtual std::string output() = 0;
	virtual std::string input(std::string s) = 0;
};

#endif /* ABSTRACTIO_H_ */
