/*
 * ArmorCategory.cpp
 *
 *  Created on: 4 мая 2014
 *      Author: sergey
 */

#include "ArmorCategory.h"

ArmorCategory::ArmorCategory(std::string category)
: itsCategory(category)
{
}

ArmorCategory::~ArmorCategory()
{
}

std::string ArmorCategory::getCategory() const
{
	return itsCategory;
}
