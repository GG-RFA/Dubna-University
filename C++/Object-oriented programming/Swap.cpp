#include <iostream>
#include <string>
using namespace std;
template <class X> void Swap(X& a, X& b) {
	X c = a; a = b; b = c;
}
int main()
{
	int b = 10, c = 15;
	Swap(b, c);
	cout « b « '\t' « c « endl;
	setlocale(LC_ALL, "Russian");
	system("pause");
	return 0;
}