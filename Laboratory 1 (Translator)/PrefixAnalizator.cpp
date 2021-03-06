#include "pch.h"
#include <iostream>
#include <clocale>
#include <string>

using namespace std;

bool Operation1(char Symbol)
{
	if (Symbol == '!')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Operation2(char Symbol)
{
	if (Symbol == '+' || Symbol == '-' || Symbol == '*' || Symbol == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool prefixAnalizatorStack(string value)
{
	while (value.size() != 1)
	{
		int indexOfPosition = value.size() - 1;

		while(!Operation1(value.at(indexOfPosition)) && !Operation2(value.at(indexOfPosition)))
		{
			indexOfPosition--;

			if (indexOfPosition == -1)
			{
				return false;
			}
		}

		if (Operation1(value.at(indexOfPosition)))
		{
			if (value.size() - indexOfPosition - 1 == 0)
			{
				return false;
			}
			value[indexOfPosition] = 'a';
			value.erase(indexOfPosition + 1, 1);
		}
		else
		{
			if (value.size() - indexOfPosition - 1 == 1)
			{
				return false;
			}
			value[indexOfPosition] = 'a';
			value.erase(indexOfPosition + 1, 2);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string expression;

	while (true)
	{
		cout << "Пожалуйста введите префиксное арифметическое выражение: ";
		cin >> expression;

		if (expression == "exit")
		{
			break;
		}

		if (prefixAnalizatorStack(expression))
			cout << "Выражение префиксное!\n";
		else
			cout << "Выражение не префиксное!\n";

		cout << "Для выхода введите \"exit\"\n";
	}	
	
	system("pause");

	return 0;
}