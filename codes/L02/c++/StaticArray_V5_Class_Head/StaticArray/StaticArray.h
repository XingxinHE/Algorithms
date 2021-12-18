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