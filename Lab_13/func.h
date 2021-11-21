#pragma once

#include <iostream>
#include <cmath>
#include "windows.h"

#define RU 1251
using namespace std;

template <class T>
bool MemoryCheck(T** arr)
{
	if (arr == nullptr)
	{
		return false;
	}

	return true;
}

bool sizeCheck(int&, int&);