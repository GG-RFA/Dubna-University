#include <iostream>
#include <Windows.h>
using namespace std;
class polyn {
private:
	int n;
	double* a;
public:
	polyn(double* a, int n)
	{
		this->n = n;
		this->a = new double[n + 1];
		for (int i = 0; i <= n; i++)
		{
			this->a[i] = a[i];
		}
	}
	polyn(int n)
	{
		this->n = n;
		this->a = new double[n + 1];
		for (int i = 0; i <= n; i++)
		{
			this->a[i] = 0;
		}
	}
	void show() {
		for (int i = 0; i <= n; i++)
		{
			cout « a[i] « "\t";
		}
		cout « "\n";
	}

	polyn operator*(const polyn B)
	{
		polyn C(n + B.n);

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= B.n; j++)
			{
				C.a[i + j] += a[i] * B.a[j];
			}
		}
		return C;
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double b[] = { -2,3,4 };
	double b1[] = { 1,-2,3,2 };
	polyn A(b, 2);
	polyn B(b1, 3);
	A.show();
	B.show();
	polyn C(5);
	C = A * B;
	C.show();
	system("pause");
	return 0;
}
