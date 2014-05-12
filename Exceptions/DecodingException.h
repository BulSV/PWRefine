/*
 * DecodingException.h
 *
 *  Created on: 28 апр. 2014
 *      Author: sergey
 */

#ifndef DECODINGEXCEPTION_H_
#define DECODINGEXCEPTION_H_

#include <string>

class DecodingException {
	int itsErrorLetter;
	std::string itsMessage;
public:
	DecodingException(int errorLetter, std::string message = "");
	~DecodingException();
	std::string getMessage() const;
	int getErrorLetter() const;
};

#endif /* DECODINGEXCEPTION_H_ */
