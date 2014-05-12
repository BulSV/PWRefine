/*
 * ArmorCategory.h
 *
 *  Created on: 4 мая 2014
 *      Author: sergey
 */

#ifndef ARMORCATEGORY_H_
#define ARMORCATEGORY_H_

#include <string>

class ArmorCategory
{
	std::string itsCategory;
public:
	ArmorCategory(std::string category);
	~ArmorCategory();
	std::string getCategory() const;
};

#endif /* ARMORCATEGORY_H_ */
