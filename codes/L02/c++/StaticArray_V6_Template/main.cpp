/************************************************************************\


Copyright (c) 2021 HE, Xingxin


Module Name:

	A file demonstrating generic static array with class separated with header file and cpp file.


Notes:
	[Optional]


History:
	Created on 12/18/2021 xingxin.he@mail.polimi.it


\************************************************************************/


#include "StaticArray.h"
#include <cstdio>

int main()
{
	StaticArray<int> cIntArray;
	StaticArray<double> cDoubleArray;

	
	cIntArray.CreateArray(3);
	cIntArray.SetValue(0, 65);
	cIntArray.SetValue(1, 16);
	cIntArray.SetValue(2, 42);
	cIntArray.PrintArray();

	cDoubleArray.CreateArray(3);
	cDoubleArray.SetValue(0, 311.2);
	cDoubleArray.SetValue(1, 45.1);
	cDoubleArray.SetValue(2, 78.2);
	cDoubleArray.PrintArray();

	return 0;
}
