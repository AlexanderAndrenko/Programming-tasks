#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void searchAllAddendums(int n);
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
	int i = 4;

	while (sequenceOfAddendums[0] < n - 3) 
	/*Так как первое слагаемое может быть самым большим, то последняя комбинация - это когда первое слагаемое максимально, а остальные 4 равны единице. 
	Так как условие строгое, то первое слагаемое должно быть всегда строго меньше, чем искомое число n на три.*/
	{
		if(sequenceOfAddendums[i - 1] > sequenceOfAddendums[i] || i == 0)
		{
			sequenceOfAddendums[i]++;

			for (; i < 4; i++) //Присваиваем последующим слагаемым значение - единица
			{
				sequenceOfAddendums[i + 1] = 1;
			}

			if (checkSum(sequenceOfAddendums, n)) //Проверяем слагаемые на равность искомому числу и выводим на экран
			{
				outputAddendum(sequenceOfAddendums);
			}
		}
		else 
		{
			i--;
		}		
	}

	cout << "Найдены все возможные комбинации слагаемых числа " << n << endl;
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
		if (i != 4)
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