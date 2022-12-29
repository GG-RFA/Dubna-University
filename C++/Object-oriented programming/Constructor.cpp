#include<iostream>
#include<string>
using namespace std;
class A {
public:
	A() {
		cout « "конструктор A\n";
	}
	~A() {
		cout « "деструктор A\n";
	}
};
class B {
public:
	B() {
		cout « "конструктор B\n";
	}
	~B() {
		cout « "деструктор B\n";
	}
};
void C() {
	cout « "Мы в C\n";
	A a;
	B b;
	throw("Исключение C\n");
}
void D() {
	cout « "мы в D\n";
	try {
		A a;
		B b;
		C();
		cout « "Возврат из D\n";
	}
	catch (const char* s) {
		cout « s « '\n';
		throw;
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	cout « "мы в main\n";
	try {
		D();
	}
	catch (const char* s) {
		cout « s « '\n';
	}
	cout « "конец main\n";
	system("pause");
	return 0;
}
