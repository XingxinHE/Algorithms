/************************************************************************\


Copyright (c) 2021 HE, Xingxin


Module Name:

	A file demonstrating static array with treating struct object.


Notes:
	[Optional]


History:
	Created on 12/18/2021 xingxin.he@mail.polimi.it


\************************************************************************/

#include<cstdio>
#include<cstdlib>

typedef struct
{

	int iLength;
	double* pArray;

	void InitArray();
	void CreateArray(int size);
	void FreeArray();
	void SetValue(int i, double value);
	void PrintArray();

}StaticArray;


int main()
{
	StaticArray stArray;
	stArray.InitArray();
	stArray.CreateArray(3);
	stArray.SetValue(0, 2.1);
	stArray.SetValue(1, 99.21);
	stArray.SetValue(2, 16.8);
	stArray.PrintArray();
	stArray.FreeArray();

	return 0;
}

void StaticArray::InitArray()
{
	this->iLength = 0;
	this->pArray = NULL;
}

void StaticArray::CreateArray(int size)
{
	this->iLength = size;
	this->pArray = (double*)malloc(sizeof(double) * size);
	if (this->pArray == NULL)
	{
		printf("No sufficient memory!");
	}
}

void StaticArray::FreeArray()
{
	if (this->pArray != NULL)
	{
		free(this->pArray);
		this->iLength = 0;
		this->pArray = NULL;
	}
}

void StaticArray::SetValue(int i, double value)
{
	if (this->pArray != NULL && i < this->iLength && i >= 0)
	{
		this->pArray[i] = value;
	}
	else
	{
		printf("The index or array is not OK.");
	}
}

void StaticArray::PrintArray()
{
	if (this->pArray != NULL && this->iLength != 0)
	{
		for (int i = 0; i < this->iLength; i++)
		{
			printf("%lf\n", this->pArray[i]);
		}
	}
	else
	{
		printf("The array is NULL.");
	}
}
