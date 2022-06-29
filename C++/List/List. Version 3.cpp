#include<iostream>
#include<vector>
#include<string>
using namespace std;
class students {
public:
	int number;
	string name;
	students(int number, string name) {
		this->number = number;
		this->name = name;
	}
};
string to_string(students k) { return to_string(k.number) + k.name; }
int main() {
	setlocale(LC_ALL, "rus");
	try {
		int i;
		cin » i;
		if (i == 0) throw "деление на ноль";
		int* j = new int[i];
		if (i == 1) throw 100;
		if (i == 2) throw 200.0;
		if (i == 3) throw students(1, "Вася");
	}
	catch (const double k) {
		cout « k « endl;
	}
	catch (const int k) {
		cout « k « endl;
	}
	catch (const char* s) {
		cout « s «endl;
	}
	catch (const students& k) {
		cout « to_string(k) « endl;
	}
	catch (...)
	{
		cout « "Произошла ошибочка,мисье Гау\n";
	}
	system("pause");
	return 0;
}