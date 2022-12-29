//Подключаем все необходимые библиотеки
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
//Создание класса "Pryam"
class Pryam {
	//Объявление модификатора доступа типа “protected”- доступ открыт классам, производным от данного
protected:
	//Обьявление необходимых переменных типа double
	double x;
	double y;
	double z;
	double m;
	double n;
	double p;
	//Создание конструктора для переменных
public:
	Pryam(double x, double y, double z, double m, double n, double p) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->m = m;
		this->n = n;
		this->p = p;
	}
	//Создание функции для нахождения расстояния от прямой до начала координат
	double distance() {//расстояние от прямой до начала координат
		//Реализация формулы
		double d1 = y * p - n * z;
		double d2 = z * m - x * p;
		double d3 = x * n - y * m;
		return sqrt(d1 * d1 + d2 * d2 + d3 * d3) / sqrt(m * m + n * n + p * p);
	}
	//Создание функции для нахождения угла между прямой и осями координат
	double* corner() {//угол между прямой и осями координат
		//Реализация формулы
		double S = sqrt(m * m + n * n + p * p);
		double* v = new double[3];
		v[0] = m / S;
		v[1] = n / S;
		v[2] = p / S;
		return v;
	}

	//Создание функции для нахождения расстояния между 2 прямыми
	double distance_between(Pryam A) {//Расстояние между 2 прямыми
		//Реализация формулы
		double d1 = n * A.p - p * A.n;
		double d2 = m * A.p - p * A.m;
		double d3 = m * A.n - A.m * n;
		double K = sqrt(d1 * d1 + d2 * d2 + d3 * d3);
		d1 = d1 / K;
		d2 = d2 / K;
		d3 = d3 / K;
		double p = d1 * A.x + d2 * A.y + d3 * A.z;
		return abs(d1 * x + d2 * y + d3 * z - p);
	}
};
//Главная функция программы
int main()
{
	setlocale(LC_ALL, "Russian");
	//Присвоение значении полям
	Pryam M1(-2, 1, 4, 0, 2, -3);
	Pryam M2(0, 1, -4, 1, -2, 6);
	cout << "Расстояние от прямой до начала координат:" << M1.distance() << '\n'; //Вывод результата
	double* z = M1.corner();
	cout << "\n Угол между прямыми:" << z[0] << "\t" << z[1] << "\t" << z[2] << "\n"; //Вывод результата
	cout << "\n Расстояние между прямыми:" << M1.distance_between(M2) << '\n'; //Вывод результата
	system("pause"); //Задержка окна
	return 0;
}

