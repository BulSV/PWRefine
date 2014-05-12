/**
 * @file StoneCategory.cpp
 *
 *  @date 4 мая 2014
 *  @author sergey
 */

#include "StoneCategory.h"

StoneCategory::StoneCategory(std::string category)
: itsCategory(category)
{
}

StoneCategory::~StoneCategory()
{
}

std::string StoneCategory::getCategory() const
{
	return itsCategory;
}
