#include <iostream>
#include <math.h>
using namespace std;
class Visoti {
private:
	int a;
	int b;
public:
	Visoti(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void maximum() {
		int a[] = { 2,4,6,8,10,12 };
		int max = a[0];
		for (int i = 1; i < 6; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
	}
	void minimum() {
		int a[] = { 2,4,6,8,10,12 };
		int min = a[0];
		for (int i = 1; i < 6; i++) {
			if (a[i] < min) {
				min = a[i];
			}
		}
	}
	void difference() {
		int a[] = { 2,4,6,8,10,12 };
		int sum = 0;
		for (int i = 1; i < 6; i++)
			sum += a[i];
	}
	void krutizna() {
		int a[] = { 2,4,6,8,10,12 };
		double average = 0;
		int sum = 0;
		for (int i = 1; i < 6; i++)
			sum += a[i];
		average = sum / 6;
	}
	double comparison() {
		int a[] = { 2,4,6,8,10,12 };
		int b[] = { 1,3,5,7,9,11 };
		for (int i = 1; i < 6; i++)
			for (int j = 1; j < 6; j++)
				if (a[i] = b[j]) {
					return true;
				}
				else
					return false;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	int a[6] = { 2,4,6,8,10,12 };
	int b[6] = { 1,3,5,7,9,11 };
	Visoti V(a, b);
	cout « "Максимальное значение:" « V.maximum() « endl;
	cout « "Минимальное значение:" « V.minimum() « endl;
	cout « "Сумма элементов:" « V.difference() « endl;
	cout « "Среднее значение:" « V.krutizna() « endl;
	cout « "Сравнение:" « V.comparison() « endl;
	system("pause");
	return 0;
}