#include "pch.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

string multiplication(string firstNumber, int secondNumber); // Функция умножения двух чисел, результат которого выйдет за границы допустимых значений существующих типов переменных
string exponentiation(int base, int power); //Функция возведения числа в степень
string addition(string firstNumber, string secondNumber); //Функция сложения двух больших чисел
string factorial(int base); //Функция нахождения факториала
void outputDigitsOfNumber(string outputNumber);

int main()
{	
	setlocale(LC_ALL, "Russian");

	int baseOfFactorial;
	int baseOfExponentiation;
	int powerOfExponentiation;

	cout << "Программа расчета числа n!+a^b\n";
	cout << "Введите основание факториала: ";
	cin >> baseOfFactorial;
	cout << "Введите основание степени: ";
	cin >> baseOfExponentiation;
	cout << "Введите показатель степени: ";
	cin >> powerOfExponentiation;
	
	string resultOfFactorial = "";
	string resultOfExponentiation = "";
	string totalResult = "";

	resultOfFactorial = factorial(baseOfFactorial);
	resultOfExponentiation = exponentiation(baseOfExponentiation, powerOfExponentiation);
	totalResult = addition(resultOfFactorial, resultOfExponentiation);

	cout << endl << "Результат вычисления:\n";

	outputDigitsOfNumber(totalResult);
	
	system("pause");

	return 0;
}

string multiplication(string firstNumber, int secondNumber) // Функция умножения двух чисел, результат которого выйдет за границы допустимых значений существующих типов перменных
{
	int nextRank = 0; // Переменная nextRank хранит число переноса из младшего разряда в старший
	int intermediateCalculation;
	string result = ""; //Результат умножения двух чисел

	for (int i = firstNumber.size() - 1; i >= 0; i--)
	{
		intermediateCalculation = int(firstNumber[i] - '0')*secondNumber + nextRank; // При умножении числа из определённого рязряда на другое число, прибавляем к нему число переносимое из младщих разрядов

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

string exponentiation(int base, int power)
{
	string result = to_string(base);//Результат возведения в степень

	for (int countOfPower = 1; countOfPower < power; countOfPower++) //Цикл возведения в степень. Возведение в степень, это умножение числа самого на себя n раз.
	{
		result = multiplication(result, base);
	}

	return result;
}

string addition(string firstNumber, string secondNumber)
{
	string result = "";
	int indexOfFirstNumber = firstNumber.size() - 1;
	int indexOfSecondNumber = secondNumber.size() - 1;
	int nextRank = 0; // Переменная nextRank хранит число переноса из младшего разряда в старший
	int intermediateCalculation;

	while (indexOfFirstNumber >= 0 || indexOfSecondNumber >= 0)
	{
		if (indexOfFirstNumber >= 0 && indexOfSecondNumber >= 0)
		{
			intermediateCalculation = int(firstNumber[indexOfFirstNumber] - '0') + int(secondNumber[indexOfSecondNumber] - '0') + nextRank;
			nextRank = intermediateCalculation / 10;
		}
		else if (indexOfFirstNumber >= 0 && indexOfSecondNumber < 0)
		{
			intermediateCalculation = int(firstNumber[indexOfFirstNumber] - '0') + nextRank;
			nextRank = intermediateCalculation / 10;
		}
		else
		{
			intermediateCalculation = int(secondNumber[indexOfSecondNumber] - '0') + nextRank;
			nextRank = intermediateCalculation / 10;
		}

		result = char(intermediateCalculation % 10 + '0') + result;

		indexOfFirstNumber--;
		indexOfSecondNumber--;
	}

	while (nextRank)//Если сложение закончено, но перменная переноса nextRank хранит данные переноса, необходимо записать их в начало числа
	{
		result = char(nextRank % 10 + '0') + result;

		nextRank = nextRank / 10;
	}



	return result;
}

string factorial(int base)
{

	string result = "1";

	for (int i = 2; i <= base; i++)
	{
		result = multiplication(result, i);
	}

	return result;
}

void outputDigitsOfNumber(string outputNumber)
{
	int indexOfElement = 0;

	for (int rankOfDigit = outputNumber.size(); rankOfDigit > 0; rankOfDigit--)
	{		
		cout << outputNumber[indexOfElement] << " * " << 10 << "^" << rankOfDigit - 1 << endl;
		indexOfElement++;
	}
}
