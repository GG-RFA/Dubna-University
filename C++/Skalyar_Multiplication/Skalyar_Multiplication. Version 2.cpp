#include<iostream>
#include<math.h>
#include<vector>
#include<cstdlib>
using namespace std;

class angel { // (5) ..фиктивный тип
/* преобразовали нужную нам переменную alpha во фразе
"friend Vectors operator*(Vectors, angel); "
так как их у нас две, он не понимает что alpha должна быть double
поэтому с помощью этого класса мы делаем преобразование типа переменной alpha
имя, типы, количество параметров совпадают
*/
	double s;
public:
	double getA() { return s; }
	void setA(double a) { s = a; }
	angel(double s) {
		this->s = s; // функция копирования
	}
};
class Vectors {
private: double a, b;
public:

	void show() {
		cout « "x:" « a « "\t"« "y:" « b « endl;
	}
	Vectors(double x, double y) {
		a = x;
		b = y;
	}
	void Summa(Vectors c) {
		a += c.a;
		b += c.b;
	}
	void Summa(Vectors c, Vectors d) {
		a = c.a + d.b;
		b = c.a + d.b;
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
		Vectors c(0, 0);
		c.a = a + A.a; // отношение к вектору а !это модуль !а // умножаем вектор на вектор
		c.b = b + A.b;
		return c;
	}
	/*_____________________________________________________________________________*/
	Vectors operator*(double alpha) {
		Vectors C(0, 0);
		C.a = a * alpha; // для А
		C.b = b * alpha;
		return C;
	}
	double operator*(Vectors B) {
		return a * B.a + b * B.b; // для А
	}
	// умножение а и б:
	// double A*B=A.x * B.x + A.y * B.y
	// нужно найти:
	// f = A^B = (A*B)/(|A|*|B|)

	/*double operator/(Vectors A, Vectors B) {

	return (A.a * B.a + A.b * B.b) / ((fabs A) * (fabs B));
	}
	*/



	friend Vectors operator*(double, Vectors); // помогает прочитать значение а и b вне класса когда а и b private
	friend Vectors operator*(Vectors, angel); // (5)// помогает прочитать значение а и b вне класса когда а и b private
};

Vectors operator*(double a, Vectors A) { // используем а и b из класса
	Vectors B(0, 0); // умножили вектор B на угол альфа
	B.a = a * A.a;
	B.b = a * A.b;
	return B;
}



// 1 координата a': а * косинус альфа - b * синус альфа
// 2 координата b': a * синус альфа + b * косинус альфа

Vectors operator*(Vectors A, angel alpha) { // (5)
	Vectors C(0, 0);
	double x = alpha.getA();
	C.a = A.a * cos(x) - A.b * sin(x);
	C.b = A.a * sin(x) + A.b * cos(x);
	return C;
}




/* class povorot
double a;
povorot (double a)
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	Vectors A = Vectors(3, 4);
	Vectors B = Vectors(4, -3);
	Vectors C = Vectors(0, 0);
	angel f(5);
	C = A * f;
	C.show();
	C = 7 * A;
	C.show();
	//C = 3 * A;
	/*C.show();
	/*_____________________________________________________________________________*/
	/*cout « "Скалярное произведение равно: " « A.Skalyar_proizv(B, A) « "\n";
	cout « "Модуль вектора равен: "« A.Modul_vector(B) « "\n";
	cout « "Косинус равен: " « A.CosAlpha(B, A)« "\n";
	cout « "Сумма векторов равна: ";
	cout « "d = ";
	A.Summa(B);
	A.show();
	C.show();
	B.show();
	cout « "поворот векторов" « "\t";
	C.show();
	*/
	/*_____________________________________________________________________________*/
	return 0;
}
