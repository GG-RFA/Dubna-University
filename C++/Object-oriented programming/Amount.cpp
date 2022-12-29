#include<iostream>
#include<string>
using namespace std;
class A {
protected:
	double a;
	string name;
public:
	A(double a, string name) {
		this->a = a;
	}
	virtual void show() {
		cout « "x=" « a «"\t y="«"\t Объем фигуры(1-куб,2-циллиндр,3-окружность,4-пирамида)="«Vol()« "\n";
	}
	virtual double Vol() = 0;
};
class Coub :public A {
public:
	Coub(double a, string name) :A(a, name) {}
	double Vol() {
		return pow(a, 3);
	}
};
class Cylinder : public A {
public:
	Cylinder(double a, string name) :A(a, name) {}
	double Vol() {
		return 3.14 * pow(a, 3);
	}
};
class Ball : public A {
public:
	Ball(double a, string name) :A(a, name) {}
	double Vol() {
		return 4 / 3 * 3.14 * pow(a, 2);
	}
};
class Pyramide :public A {
public:
	Pyramide(double a, string name) :A(a, name) {}
	double Vol() {
		return (a / 2) * (a / sqrt(2));
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Coub coub(3, "Куб");
	coub.show();
	Cylinder cylinder(3, "Циллинр");
	cylinder.show();
	Ball ball(3, "Шар");
	ball.show();
	Pyramide pyramide(3, "Пирамида");
	pyramide.show();
	system("pause");
	return 0;
}