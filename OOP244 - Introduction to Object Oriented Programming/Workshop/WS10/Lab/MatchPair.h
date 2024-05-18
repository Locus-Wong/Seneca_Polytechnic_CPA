//Name: Tsz Wa Wong
//Email: twwong9@myseneca.ca
//Student ID: 152181228
//Date: 09 Apr 2024
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef MATCHPAIR_H
#define MATCHPAIR_H
namespace seneca
{
    template <typename T, typename U>
    struct Pair
    {
    public:
        T first;
        U second;
    };

    template<typename T, typename U>
    void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size)
    {
        Pair<T, U>* temp = new Pair<T, U>[size + 1];
        for (int k = 0; pArray && k < size; k++)
        {
            temp[k] = pArray[k];
        }
        temp[size].first = first;
        temp[size].second = second;
        delete[] pArray;
        pArray = temp;
        size++;
    }
    
    template<typename T, typename U>
    Pair<T, U>* matches(T arr1[], U arr2[], const int& size1, const int& size2, int& size3) // [] to indicate that arr1 and arr2 are arrays of elements of types T and U respectively.
    {
        Pair<T, U>* pt = nullptr;
        size3 = 0;
        for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				if (arr1[i] == arr2[j])
				{
					addDynamicPairElement(pt, arr1[i], arr2[j], size3);
				}
			}
		}
        return pt; //returns the address of the first element of the new dynamic array
    }

    template<typename T>
    void releaseMem(T* arr)
	{
        if(arr)
		delete[] arr;
	}
}
#endif
