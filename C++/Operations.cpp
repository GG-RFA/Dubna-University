﻿* #include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	try {
		int a = 5, b = 0;
		throw "YuraGuy";
		cout « a / b « endl;
	}
	catch (const char* YuraGuy)
	{
		cout «YuraGuy«endl;
	}
	cin.get();
	system("pause");
	return 0;
}
*/
#include <iostream>;
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int num1;
	int num2;
	int var = 2;

	while (var--)
	{
		cout « "Введите значение num1: ";
		cin » num1;
		cout « "Введите значение num2: ";
		cin » num2;

		cout « "num1 + num2 = " « num1 + num2 « endl;
		cout « "num1 / num2 = ";

		try //код, который может привести к ошибке, располагается тут
		{
			if (num2 == 0)
			{
				throw 123; //генерировать целое число 123
			}
			cout « num1 / num2 « endl;
		}
		catch (int i)//сюда передастся число 123
		{
			cout « "Ошибка №" « i « " - на 0 делить нельзя!!!!" « endl;
		}

		cout « "num1 - num2 = " « num1 - num2 « endl;
		cout « "=================================" « endl « endl;
	}

	cout « "Программа завершила работу!" « endl;

	return 0;
}
