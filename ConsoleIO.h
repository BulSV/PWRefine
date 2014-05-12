/*
 * ConsoleIO.h
 *
 *  Created on: 16 апр. 2014
 *      Author: sergey
 */

#ifndef CONSOLEIO_H_
#define CONSOLEIO_H_

#include <iostream>
#include "AbstractIO.h"

class ConsoleIO: public AbstractIO {
	std::string itsString;
public:
	ConsoleIO();
	virtual ~ConsoleIO();
	virtual std::string output();
	virtual std::string input(std::string s);

};

#endif /* CONSOLEIO_H_ */
