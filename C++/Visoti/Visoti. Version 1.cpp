#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
class Visoti {
private:
	long int a;
	long int b;
public:
	Visoti() {
		int a[6] = { 2,4,6,8,10,12 };
		for (int i = 0; i < 6; i++) {
			a[i] = 0;
		}
	}
	void max() {
		int a[6] = { 2,4,6,8,10,12 };
		int max = a[0];
		for (int i = 1; i < 6; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
	}
	void min() {
		int a[6] = { 2,4,6,8,10,12 };
		int min = a[0];
		for (int i = 1; i < 6; i++) {
			if (a[i] < min) {
				min = a[i];
			}
		}
	}
	void perepad() {
		int a[6] = { 2,4,6,8,10,12 };
		int summa = 0;
		for (int i = 1; i < 6; i++)
			summa += a[i];
	}
	void krutizna() {
		int a[6] = { 2,4,6,8,10,12 };
		double srednee = 0;
		int summa = 0;
		for (int i = 1; i < 6; i++)
			summa += a[i];
		srednee = summa / i;
	}
	void sravnenie() {
		int a[6] = { 2,4,6,8,10,12 };
		int b[6] = { 1,3,5,7,9,11 };
		for (int i = 1; i < 6; i++)
			for (int j = 1; j < 6; j++)

	}
};
int main()
{
	Visoti a[6];
	for (int i = 0; i < 6; i++)
	{

	}
	setlocale(LC_ALL, "Russian");
	system("pause");
	return 0;
}