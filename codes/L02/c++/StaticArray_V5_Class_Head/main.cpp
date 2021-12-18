/************************************************************************\


Copyright (c) 2021 HE, Xingxin


Module Name:

	A file demonstrating static array with class.


Notes:
	[Optional]


History:
	Created on 12/18/2021 xingxin.he@mail.polimi.it


\************************************************************************/

#include "StaticArray.h"

int main()
{
	StaticArray cArray;

	cArray.CreateArray(3);
	cArray.SetValue(0, 311.2);
	cArray.SetValue(1, 45.1);
	cArray.SetValue(2, 78.2);
	cArray.PrintArray();

	return 0;
}

