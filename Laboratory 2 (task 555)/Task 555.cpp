#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void outputPascalTriangle(int n);
void outputOneString(int array[]);
void calculatedNextString(int array[], int sizeOfArray);

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите необходимое для вывода на экран количество строк треугольника Паскаля: ";
	cin >> n;

	n = n + 2; //Число элементов в строке равно номеру строки, т.к. первый и последний элемент будут нулевыми, увеличиваем размер массива на два.

	outputPascalTriangle(n);

	system("pause");

	return 0;
}

void outputPascalTriangle(int n) //Входной параметр - количество строк, которые необходимо вывести на экран.
{
	int *useArray = new int[n];

	useArray[0] = 0;
	useArray[1] = 1;

	for (int i = 2; i < n; i++) //Заполнение массива нулями(избавление от мусора)
	{
		useArray[i] = 0;
	}

	for (int i = 0; i < n - 2; i++) //Расчёт и вывод на экран первых n строк треугольника Паскаля. n - 2 - т.к. мы увеличивали значение n на два.
	{
		outputOneString(useArray);
		calculatedNextString(useArray, n);
	}

	delete useArray;
}

void outputOneString(int array[]) // Функция вывода массива на экран
{
	for (int i = 1; ; i++)
	{
		if (array[i] != 0)
		{
			cout << array[i] << " ";
		}
		else
		{
			cout << endl;
			break;
		}
	}
}

void calculatedNextString(int array[], int sizeOfArray) // Функция расчёта следующей строки треугольника Паскаля
{
	int *copyArray = new int[sizeOfArray];

	for (int i = 0; i < sizeOfArray; i++) //Делаем копию массива
	{
		copyArray[i] = array[i];
	}

	for (int i = 1; i < sizeOfArray; i++)
	{
		array[i] = copyArray[i] + copyArray[i - 1];
	}

	delete copyArray;
}
