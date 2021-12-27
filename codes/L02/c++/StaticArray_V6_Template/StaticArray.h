/************************************************************************\


Copyright (c) 2021 HE, Xingxin


Module Name:

	A header file for generic static array.


Notes:
	[Optional]


History:
	Created on 12/18/2021 xingxin.he@mail.polimi.it


\************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include <cstring>



template <class T>
class StaticArray
{
private:
        int iLength;
        T* pArray;
        void InitArray();
	void FreeArray();

public:
        StaticArray();
        ~StaticArray();
	void CreateArray(int size);
	void SetValue(int i, T value);
	void PrintArray();
};



template <class T>
StaticArray<T>::StaticArray()
{
	this->InitArray();
}

template <class T>
StaticArray<T>::~StaticArray()
{
	this->FreeArray();
}

template <class T>
void StaticArray<T>::InitArray()
{
	this->iLength = 0;
	this->pArray = NULL;
}

template <class T>
void StaticArray<T>::CreateArray(int size)
{
	this->iLength = size;
	this->pArray = (T*)malloc(sizeof(T) * size);
	if (this->pArray == NULL)
	{
		printf("No sufficient memory!");
	}
}

template <class T>
void StaticArray<T>::FreeArray()
{
	if (this->pArray != NULL)
	{
		free(this->pArray);
		this->iLength = 0;
		this->pArray = NULL;
	}
}

template <class T>
void StaticArray<T>::SetValue(int i, T value)
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

template <class T>
void StaticArray<T>::PrintArray()
{
	if (this->pArray != NULL && this->iLength != 0)
	{
		for (int i = 0; i < this->iLength; i++)
		{
			char const *typen = typeid(T).name();
			if( !strcmp(typen, "double"))
			{
				printf("%s: %lf ", typen, pArray[i]);
			}
			else if (!strcmp(typen, "int"))
			{
				printf("%s: %d ", typen, pArray[i]);
			}
			
			printf("\n");
		}
	}
	else
	{
		printf("The array is NULL.");
	}
}


