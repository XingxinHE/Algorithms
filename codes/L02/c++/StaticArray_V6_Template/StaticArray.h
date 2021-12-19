/************************************************************************\


Copyright (c) 2021 HE, Xingxin


Module Name:

	A header file for generic static array.


Notes:
	[Optional]


History:
	Created on 12/18/2021 xingxin.he@mail.polimi.it


\************************************************************************/


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





