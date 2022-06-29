#include<iostream>
#include<math.h>
#include<vector>
#include<cstdlib>
using namespace std;
class Vectors {
public:
	double a, b;
	void show() {
		cout« "x:" « a« "\t"« "y:" « b« endl;
	}
	Vectors(double x, double y) {
		a = x;
		b = y;
	}
	void Summa(Vectors c) {
		a += c.a;
		b += c.b;
	}
	void Summa(Vectors C, Vectors D) {
		a = C.a + D.b;
		b = C.a + D.b;
	}
	double Skalyar_proizv(Vectors c, Vectors d) {
		return c.a * d.a + d.b * c.b;
	}
	double Skalyar_proizv(Vectors c) {
		return c.a * a + b * c.b;
	}
	double Modul_vector(Vectors c) {
		return sqrt(pow(c.a, 2) + pow(c.b, 2));
	}
	double Modul_vector() {
		return sqrt(pow(a, 2) + pow(b, 2));
	}
	double CosAlpha(Vectors c, Vectors d) {
		return Skalyar_proizv(c, d) / (Modul_vector(c) * Modul_vector(d));
	}
	double CosAlpha(Vectors c) {
		return Skalyar_proizv(c) / (Modul_vector(c) * Modul_vector());
	}
	Vectors operator+(Vectors A) {
		Vectors C(0, 0);
		C.a = a + A.a;
		C.b = b + A.b;
		return C;
	}
	Vectors operator-(Vectors A) {
		Vectors C(0, 0);
		C.a = a - A.a;
		C.b = b - A.b;
		return C;
	}
	Vectors operator*(double alpha) {
		Vectors C(0, 0);
		C.a = a * alpha;
		C.b = b * alpha;
		return C;
	}
	double operator*(Vectors A) {
		double C;
		C = a * A.a + b * A.b;
		return C;
	}
	double operator!() {
		return sqrt(pow(a, 2) + pow(b, 2));
	}
	double operator^(Vectors A) {
		return (a * A.a + b * A.b) / (sqrt(pow(a, 2) + pow(b, 2)) * sqrt(pow(A.a, 2) + pow(A.b, 2)));
	}

};
int main()
{
	setlocale(LC_ALL, "Russian");
	double D = 0;
	double F = 0;
	Vectors A = Vectors(1, 2);
	Vectors B = Vectors(3, 4);
	Vectors C = Vectors(5, 6);
	C = A + B;
	C = (A, B);
	D = A * B;
	F = A ^ B;
	D = !A;
	C.show();
	cout « "D равно:" « D « "\n";
	cout « "F равно:" « F « "\n";
	cout« "Скалярное произведение равно:" « A.Skalyar_proizv(B, A)«"\n";
	cout« "Модуль вектора равен: "« A.Modul_vector(B)« "\n";
	cout« "Косинус равен:" « A.CosAlpha(B, A)« "\n";
	cout« "Сумма векторов равна: ";
	A.Summa(B);
	A.show();
	system("pause");
	return 0;
}