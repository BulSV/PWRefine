/**
 * @file StoneCategory.h
 *
 *  @date 4 мая 2014
 *  @author sergey
 */

#ifndef STONECATEGORY_H_
#define STONECATEGORY_H_

#include <string>

class StoneCategory
{
	std::string itsCategory;
public:
	StoneCategory(std::string category);
	~StoneCategory();
	std::string getCategory() const;
};

#endif /* STONECATEGORY_H_ */
