#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

typedef float typeOfArray;

void outputTwoDemensionsArray(typeOfArray ** array, int row, int column);
void countMultiplicationOfMatrix(typeOfArray **FirstArray, typeOfArray **SecondArray, typeOfArray **result, int size);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "Пожалуйста введите порядок квадратной матрицы: ";
	cin >> n;
	cout << endl;

	//Выделение памяти под динамические массивы
	typeOfArray **A = new typeOfArray *[n];
	typeOfArray **B = new typeOfArray *[n];
	typeOfArray **arrayOfMultiplication = new typeOfArray*[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = new typeOfArray[n];
		B[i] = new typeOfArray[n];
		arrayOfMultiplication[i] = new typeOfArray[n];
	}

	for (int row = 0; row < n; row++) // заполнение двумерного массива А
	{
		for (int column = 0; column < n; column++)
		{
			if (row <= column)
			{
				A[row][column] = 1.0f / (row + column + 2.0f);
			}
			else
			{
				A[row][column] = 1.0f / (row + column + 1.0f);
			}
		}
	}

	outputTwoDemensionsArray(A, n, n);
	
	for (int i = 0; i < n; i++)//Освобождение оперативной памяти от динамических массивов
	{
		delete[] A[i];
		delete[] B[i];
		delete[] arrayOfMultiplication[i];
	}

	delete[] A;
	delete[] B;
	delete[] arrayOfMultiplication;

	system("pause");
	
	return 0;
}

void outputTwoDemensionsArray(typeOfArray ** array, int rowOfArray, int columnOfArray)
{
	for (int row = 0; row < rowOfArray; row++) //Вывод на экран массива А
	{
		for (int column = 0; column < columnOfArray; column++)
		{
			cout << array[row][column] << endl;
		}
	}
}

void countMultiplicationOfMatrix(typeOfArray ** FirstArray, typeOfArray ** SecondArray, typeOfArray ** result, int size)//В разработке
{
	typeOfArray IntermediateProduct = 0;

	
	for (; row < size; row++) //Требует доработки
	{
		int row = 0;
		int column = 0;
		result[row][column] = FirstArray[row][column] * SecondArray[column][row];
		for ( column < size; column++)
		{
			
		}
	}
}
