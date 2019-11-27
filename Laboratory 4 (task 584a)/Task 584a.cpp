#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string multiplication(string x, int y) // Функция умножения двух чисел, результат которого выйдет за границы допустимых значений существующих типов перменных
{
	int nextRank = 0; // Переменная nextRank хранит число переноса из младшего разряда в старший
	int intermediateCalculation;
	string result = ""; //Результат умножения двух чисел

	for (int i = x.size() - 1; i >= 0; i--)
	{
		intermediateCalculation = int(x[i] - '0')*y + nextRank; // При умножении числа из определённого рязряда на другое число, прибавляем к нему число переносимое из младщих разрядов

		nextRank = intermediateCalculation / 10; // Если полученное число больше 9, то есть выходит за границы разряда, то необходимое число переноса записываем в nextRank

		result = char(intermediateCalculation % 10 + '0') + result; //В начало числа записываем значения новых порядков.
	}

	while (nextRank)//Если умножение закончено, но перменная переноса nextRank хранит данные переноса, необходимо записать их в начало числа
	{
		result = char(nextRank % 10 + '0') + result;

		nextRank = nextRank / 10;
	}

	return result;
}


int main()
{
	
	int n;
	string str = "1";

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		str = multiplication(str, i);
	}

	cout << str << endl; // Вывод числа на экран 

	cout << str.size() << endl;// Вывод количества символов

		
	system("pause");

	return 0;
}