#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

template <typename T>
T maxElementFunc(T array[], int sizeOfArray) //Поиск максимального значения в одномерном массиве
{
	T maxElement = array[0];

	for (int index = 0; index < sizeOfArray; index++)
	{
		if (maxElement < array[index])
		{
			maxElement = array[index];
		}
	}

	return maxElement;
}

template <typename T>
void selectionSort(T **sortedArray, int numberOfRowSortedArray, int numberOfColumnSortedArray)
{
	int indexOfMaxElement;

	T *intermediateArray = new T[numberOfColumnSortedArray];
	
	for (int indexOfSortedPosition = 0; indexOfSortedPosition < numberOfRowSortedArray; indexOfSortedPosition++)
	{
		for (int i = 0; i < numberOfColumnSortedArray; i++) //Присваиваем промежуточному массиву, данные строки с которой работаем в даннный момент
		{
			intermediateArray[i] = sortedArray[indexOfSortedPosition][i];
		}
		
		indexOfMaxElement = indexOfSortedPosition;

		for (int index = indexOfSortedPosition; index < numberOfRowSortedArray; index++)
		{
			if (maxElementFunc(sortedArray[indexOfSortedPosition], numberOfColumnSortedArray) < maxElementFunc(sortedArray[index], numberOfColumnSortedArray))
			{
				for (int i = 0; i < numberOfColumnSortedArray; i++)
				{
					intermediateArray[i] = sortedArray[index][i];
				}				
				indexOfMaxElement = index;
			}
		}

		for (int i = 0; i < numberOfColumnSortedArray; i++)
		{
			sortedArray[indexOfMaxElement][i] = sortedArray[indexOfSortedPosition][i];
			sortedArray[indexOfSortedPosition][i] = intermediateArray[i];
		}
	}
}

template <typename T>
void outputArrayOnDisplay(T array, int numberOfRowSortedArray, int numberOfColumnSortedArray) //Вывод на экран двумерного массива
{
	for (int indexOfRowArray = 0; indexOfRowArray < numberOfRowSortedArray; indexOfRowArray++)
	{
		for (int indexOfColumnArray = 0; indexOfColumnArray < numberOfColumnSortedArray; indexOfColumnArray++)
		{
			cout << array[indexOfRowArray][indexOfColumnArray] << " ";
		}

		cout << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	
	cout << "Введите количество строк матрицы: ";
	cin >> n;
	cout << "Введите количество столбцов матрицы: ";
	cin >> m;

	int **array = new int*[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[m];
	}


	cout << "Введите элементы матрицы!\n";

	for (int row = 0; row < n; row++)
	{
		for (int column = 0; column < m; column++)
		{
			cin >> array[row][column];
		}
	}

	selectionSort(array, n, m);
	outputArrayOnDisplay(array, n, m);
	
	system("pause");

	return 0;
}