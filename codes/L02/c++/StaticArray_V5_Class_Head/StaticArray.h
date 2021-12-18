/************************************************************************\


Copyright (c) 2021 HE, Xingxin


Module Name:

	A header file for static array.


Notes:
	[Optional]


History:
	Created on 12/18/2021 xingxin.he@mail.polimi.it


\************************************************************************/


class StaticArray
{
private:
        int iLength;
        double* pArray;
        void InitArray();
	void FreeArray();

public:
        StaticArray();
        ~StaticArray();
	void CreateArray(int size);
	void SetValue(int i, double value);
	void PrintArray();
};