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

	for (int row = 0; row < n; row++) // заполнение двумерного массива В
	{
		for (int column = 0; column < n; column++)
		{			
			B[row][column] = static_cast<typeOfArray>(rand() % 200 - 100);
		}
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
	cout << "Матрица А:\n";
	outputTwoDemensionsArray(A, n, n);
	cout << endl;

	cout << "Матрица В:\n";
	outputTwoDemensionsArray(B, n, n);
	cout << endl;

	countMultiplicationOfMatrix(A, B, arrayOfMultiplication, n);

	cout << "Произведение двух матриц:\n";
	outputTwoDemensionsArray(arrayOfMultiplication, n, n);
	
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
	for (int row = 0; row < rowOfArray; row++) //Вывод на экран массива
	{
		for (int column = 0; column < columnOfArray; column++)
		{
			cout << "Элемент " << row + 1 << column + 1 << ": " <<array[row][column] << endl;
		}
	}
}

void countMultiplicationOfMatrix(typeOfArray ** FirstArray, typeOfArray ** SecondArray, typeOfArray ** result, int size) //Функция умножения двух квадратных матриц
{
	for(int rowOfMultArray = 0; rowOfMultArray < size ; rowOfMultArray++)
	{
		typeOfArray IntermediateProduct = 0;

		for (int columnOfMultArray = 0; columnOfMultArray < size; columnOfMultArray++)
		{
			for (int i = 0; i < size; i++)
			{
				IntermediateProduct += FirstArray[rowOfMultArray][i] * SecondArray[i][columnOfMultArray];
			}
			
			result[rowOfMultArray][columnOfMultArray] = IntermediateProduct;
			IntermediateProduct = 0;
		}
	}
}