#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void searchAllAddendums(int n);
void nextSequenceOfAddendums(int sequenceOfAddendums[], bool *findedSequence, int n);
bool moreThenNext(int sequenceOfAddendums[]);
bool checkSum(int sequenceOfAddendums[], int n);
void outputAddendum(int sequenceOfAddendums[]);

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите натуральное число больше или равное пяти: ";
	int n = 0;
	while (n < 5) //Защита ввода
	{
		cin >> n;

		if (n < 5 || n % 1 != 0)
		{
			cout << "Вы ввели ненатуральное или меньше пяти число. Повторите попытку снова: ";
		}
	}

	searchAllAddendums(n);

	system("pause");

	return 0;
}

void searchAllAddendums(int n)
{
	int sequenceOfAddendums[5] = { 1, 1, 1, 1, 1 };
	bool nextSequence = true;

	while (nextSequence)
	{
		if (moreThenNext(sequenceOfAddendums) && checkSum(sequenceOfAddendums, n))
		{
			outputAddendum(sequenceOfAddendums);
			nextSequence = false;
		}

		//nextSequenceOfAddendums(sequenceOfAddendums, &nextSequence, n);

		for (int i = 0; i < 5; i++)
		{
			while (checkSum(sequenceOfAddendums, n) == false)//Увеличиваем первый элемент пока сумма слагаемых не станет равна искомому числу
			{
				sequenceOfAddendums[i]++;
			}
			
			


		}
	}
	
}

void nextSequenceOfAddendums(int sequenceOfAddendums[], bool *findedSequence, int n) //Функция перебора возможных слагаемых
{
	
}

bool moreThenNext(int sequenceOfAddendums[])//Функция проверки, что каждое последующее число меньше или равно предыдущему.
{
	for (int i = 0; i < 4; i++)
	{
		if (sequenceOfAddendums[i] >= sequenceOfAddendums[i + 1] && i == 3)
		{
			return true;
		}
		
		if (sequenceOfAddendums[i] <= sequenceOfAddendums[i + 1])
		{
			return false;
		}
	}
}

bool checkSum(int sequenceOfAddendums[], int n)//Функция проверки, что сумма слагаемых равна заданному числу
{
	int check = 0;

	for (int i = 0; i < 5; i++)
	{
		check += sequenceOfAddendums[i];
	}
	
	if (check == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void outputAddendum(int sequenceOfAddendums[])//Функция вывода массива слагаемых на экран консоли
{
	for (int i = 0; i < 5; i++)
	{
		if (i != 5)
		{
			cout << sequenceOfAddendums[i] << " + ";
		}
		else
		{
			cout << sequenceOfAddendums[i];
		}
	}
	cout << endl;
}