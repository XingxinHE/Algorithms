/************************************************************************\


Copyright (c) 2021 HE, Xingxin


Module Name:

	A file demonstrating static array with struct and reference type.


Notes:
	[Optional]


History:
	Created on 12/17/2021 xingxin.he@mail.polimi.it


\************************************************************************/


#include <cstdlib>
#include <cstdio>

typedef struct
{
	int iLength;
	double* pArray;
}StaticArray;

void InitArray(StaticArray& s);
void CreateArray(StaticArray& s, int size);
void FreeArray(StaticArray& s);
void SetValue(StaticArray& s, int i, double value);
void PrintArray(StaticArray& s);

int main()
{
	StaticArray stArray;
	InitArray(stArray);
	CreateArray(stArray, 3);
	SetValue(stArray, 0, 2.8);
	SetValue(stArray, 1, 13.1);
	SetValue(stArray, 2, 0.1);
	PrintArray(stArray);
	FreeArray(stArray);
}

void InitArray(StaticArray& s)
{
	s.iLength = 0;
	s.pArray = NULL;
}

void CreateArray(StaticArray& s, int size)
{
	s.iLength = size;
	s.pArray = (double*)malloc(sizeof(double) * size);
	if (s.pArray == NULL)
	{
		printf("No sufficient memory!");
	}
}

void FreeArray(StaticArray& s)
{
	if (s.pArray != NULL)
	{
		free(s.pArray);
		s.pArray = NULL;
	}
}

void SetValue(StaticArray& s, int i, double value)
{
	if (s.pArray != NULL && i >= 0 && i < s.iLength)
	{
		s.pArray[i] = value;
	}
	else
	{
		printf("The index or array is not OK.");
	}
}

void PrintArray(StaticArray& s)
{
	if (s.pArray!=NULL && s.iLength!=0)
	{
		for (int i = 0; i < s.iLength; i++)
		{
			printf("%lf\n", s.pArray[i]);
		}
	}
	else
	{
		printf("The array is NULL.");
	}
}
