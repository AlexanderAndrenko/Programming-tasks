#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

template<typename T>
void selectionSort(T sortedArray[], int sizeOfSortedArray)
{
	T minElement;
	int indexOfMinElement;

	for (int indexOfSortedPosition = 0; indexOfSortedPosition < sizeOfSortedArray; indexOfSortedPosition++)
	{
		minElement = sortedArray[indexOfSortedPosition];
		indexOfMinElement = indexOfSortedPosition;

		for (int index = indexOfSortedPosition; index < sizeOfSortedArray; index++)
		{
			if (minElement > sortedArray[index])
			{
				minElement = sortedArray[index];
				indexOfMinElement = index;
			}
		}

		sortedArray[indexOfMinElement] = sortedArray[indexOfSortedPosition];
		sortedArray[indexOfSortedPosition] = minElement;
	}
}

template<typename T>
void outputArrayOnDisplay(T array, int sizeOfSortedArray)
{
	for (int indexOfArray = 0; indexOfArray < sizeOfSortedArray; indexOfArray++)
	{
		cout << "Элемент " << indexOfArray + 1 << ": " << array[indexOfArray] << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	int array[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	
	selectionSort(array, 10);
	outputArrayOnDisplay(array, 10);

	system("pause");

	return 0;
}

