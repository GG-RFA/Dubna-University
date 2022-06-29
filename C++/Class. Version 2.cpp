#include <iostream>
#include <string>
using namespace std;
class A {
public:
	int n;
	int* a;
	A(int n, int start) {
		this->n = n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = start++;
	}
	~A() { delete[] a; }
	int& operator[](int i) {
		return a[i];
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	A b(3, 10);
	for (int i = 0; i < b.n; i++)
		cout « b[i] « '\t';
	cout « endl;
	system("pause");
	return 0;
}