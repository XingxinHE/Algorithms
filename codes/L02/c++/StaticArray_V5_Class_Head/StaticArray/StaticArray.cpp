#include "StaticArray.h"

#include <cstdio>
#include <cstdio>

StaticArray::StaticArray()
{
        StaticArray::InitArray();
}

StaticArray::~StaticArray()
{
        StaticArray::FreeArray();
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