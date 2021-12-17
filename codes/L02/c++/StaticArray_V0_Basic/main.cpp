/************************************************************************\


Copyright (c) 2021 HE, Xingxin


Module Name:

	A file demonstrating static array.


Notes:
	[Optional]


History:
	Created on 12/17/2021 xingxin.he@mail.polimi.it


\************************************************************************/

#include <cstdio>
#include <cstdlib>

int g_iNum;
double* g_pArray;


void CreateArray(int n);
void SetValue(int i, double value);
void FreeArray();
void PrintArray();

int main()
{
	//  create an array
	CreateArray(3);

	//  set the value of array
	SetValue(0, 1.3);
	SetValue(1, 12.5);
	SetValue(2, 28.0);

	//  print out the array
	PrintArray();

	//  free the memory
	FreeArray();

	return 0;
}

void CreateArray(int size)
{
	g_iNum = size;
	g_pArray = (double*)malloc(sizeof(double) * size);
	if (g_pArray == NULL)
	{
		printf("Memory is not enough.");
	}
}

void SetValue(int i, double value)
{
	if (g_pArray != NULL && i >= 0 && i < g_iNum)
	{
		g_pArray[i] = value;
	}
	else
	{
		printf("The index or array is not OK.");
	}
}

void FreeArray()
{
	if (g_pArray!=NULL)
	{
		free(g_pArray);
		g_pArray = NULL;
		g_iNum = 0;
	}
}

void PrintArray()
{
	if (g_pArray!=NULL && g_iNum!=0)
	{
		for (int i = 0; i < g_iNum; i++)
		{
			printf("%lf \n", g_pArray[i]);
		}
	}
	else
	{
		printf("The array is NULL.");
	}
}

