#include "func.h"

bool sizeCheck(int& iRows, int& iCols)
{
	if (iRows <= 0 || iCols <= 0)
	{
		return false;
	}

	return true;
}
