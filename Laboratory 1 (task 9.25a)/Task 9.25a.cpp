#include <iostream>
#include <string>
#include <clocale>

using namespace std;

long long int converterStringToInt(string originalNumber);
bool equalSymbol(char compareSymbol);

int main()
{
	setlocale(LC_ALL, "Russian");

	string inputNumber;

	cout << "Введите любое число: ";
	cin >> inputNumber;

	cout << "Обработанное функцией число: " << converterStringToInt(inputNumber) << endl;

	system("pause");

	return 0;
}

long long int converterStringToInt(string originalNumber)
{
	long long int outputNumber;

	for (int i = 0; ; i++) //Поиск начала числа
	{
		if (equalSymbol(originalNumber[i]))
			{
				originalNumber = originalNumber.erase(0, i); //Стираем все символы, до первого символа числа
				break;
			}
	}
	
	for (int i = 0; ; i++) //Поиск конца числа
	{
	
		if (equalSymbol(originalNumber[i]) == false)
			{
				originalNumber = originalNumber.substr(0, i); //Оставляем подстроку только с числом
				outputNumber = atoll(originalNumber.c_str()); //Конвертируем число из типа string в тип long long integer
				return outputNumber;
			}
	}
}

bool equalSymbol(char comparedSymbol)
{
	char validCharacters[10] = { '-', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	for (int i = 0; i < 10; i++)
	{
		if (comparedSymbol == validCharacters[i])
		{
			return true;
		}
	}

	return false;
}