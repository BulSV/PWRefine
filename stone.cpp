#include "stone.h"

std::string Stone::CATEGORY = "NO CATEGORY";

Stone::Stone()
    : itsCategory(CATEGORY)
{
}


Stone::~Stone() /*virtual*/
{
}

std::string Stone::category() const
{
    return itsCategory;
}
