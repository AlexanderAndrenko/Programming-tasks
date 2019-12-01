#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void countElementsOfArrayB(double **p, int n);
void countMultiplicationOfMatrix(double A[], double B[], double result[]);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "Пожалуйста введите порядок квадратной матрицы: ";
	cin >> n;
	cout << endl;

	double **A = new double *[n];
	double **B = new double *[n];
	double **arrayOfMultiplication = new double*[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
		B[i] = new double[n];
		arrayOfMultiplication[i] = new double[n];
	}

	for (int row = 0; row < n; row++) //Рандомное заполнение двумерного массива А
	{
		for (int column = 0; column < n; column++) 
		{
			A[row][column] = rand() % 200 - 100;
		}
	}

	double **p = A;

	for (int row = 0; row < n; row++) 
	{
		for (int column = 0; column < n; column++)
		{
			cout << A[row][column] << endl;
		}
	}

	countElementsOfArrayB(p, n);

	for (int row = 0; row < n; row++)
	{
		for (int column = 0; column < n; column++)
		{
			cout << A[row][column] << endl;
		}
	}
	/*for (int i = 0; i < 10; i++)
	{
		cout << p << endl;
		p = p + 1;
	}*/

	system("pause");


	return 0;
}

void countElementsOfArrayB(double **p, int n)
{
	/*for (int row = 0; row < n; row++)
	{
		for (int column = 0; column < n; column++)
		{
			if (row <= column)
			{
				array[row][column] = 1.0 / (row + column - 1);
			}
			else
			{
				array[row][column] = 1.0 / (row + column + 1);
			}
		}
	}*/

	int row = 0, column = 0;

	for (int i = 0; i < n*n; i++)
	{
		if (row <= column)
		{
			**p = 1.0 / (row + column - 1);
		}
		else
		{
			**p = 1.0 / (row + column + 1);
		}

		if (column == n - 1)
		{
			row++;
			column = 0;
		}
		
		column++;
		p = p + 1;
	}
}
/*
void countMultiplicationOfMatrix(double A[], double B[], double result[])
{

}
*/