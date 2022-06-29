#include <iostream>
using namespace std;
class A {
private:
	long long n;
public:
	void set(long long n) { this->n = n; }
	long long get() { return n; }
	~A() { cout « "Удаляем объект с полем:" « n « endl; }
};
int main() {
	setlocale(LC_ALL, "Russian");
	const int n = 10;
	A a[10];
	A* start, * finish;
	start = a;
	finish = start + n;
	for (int i = 0; i < n; i++)
		a[i].set(i);
	while (start != finish) {
		cout «(start++)->get() « '\t';
	}
	cout « endl;
	delete[]a;
	system("pause");
	return 0;
}