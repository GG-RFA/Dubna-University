#include <iostream>
using namespace std;
class A {
private:
	int n;
public:
	A* next;
	A(int n)
	{
		this->n = n;
		next = NULL;
		cout « "Создаем объект N" « n « endl;
	}
	~A() {
		if (next != NULL) {
			delete next;
			cout « "Удаляем объект N" « n « endl;
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	cout « "Создаем цепочку объектов" « endl;
	int n = 0;
	A* first = new A(n);
	A* p = first;
	while (n < 10) {
		p->next = new A(++n);
		p = p->next;
	}
	cout « "Удаляем первый объект" « endl;
	delete first;
	system("pause");
	return 0;
}