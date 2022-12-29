#include<iostream>
#include<string>
using namespace std;
class A {
public:
	double a, b;
public:
	A(double a, double b) {
		this->a = a;
		this->b = b;
	}
	virtual void show() {
		cout « "x=" « a «"\t y="«b«"\t Площадь фигуры(1-треугольник,2-эллипс,3-прямоугольник)="«sqr()« "\n";
	}
	virtual double sqr() = 0;
};
class B :public A {
public:
	B(double a, double b) :A(a, b) {}
	double sqr() {
		return a * b / 2;
	}
};
class C : public A {
public:
	C(double a, double b) :A(a, b) {}
	double sqr() {
		return 3.14 * a * b;
	}
};
class D : public A {
public:
	D(double a, double b) :A(a, b) {}
	double sqr() {
		return a * b;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	B b(3, 4);
	b.show();
	C c(3, 4);
	c.show();
	D d(3, 4);
	d.show();
	system("pause");
	return 0;
}