#include <iostream>
using namespace std;
class A {
private:
	int size;
	int* nums;
public:
	A(int size, int* nums) {
		this->size = size;
		this->nums = new int[size];
		for (int i = 0; i < size; i++)
			this->nums[i] = nums[i];
	}
	void show() {
		for (int i = 0; i < size; i++)
			cout « nums[i] « '\t';
		cout « '\n';
	}
	~A() {
		delete[]nums;
		cout « "**\n";
	}
	A(A& a) {
		size = a.size;
		nums = new int[size];
		for (int i = 0; i < size; i++)
			nums[i] = a.nums[i];
	}
	A& operator=(A& a) {
		delete[] nums;
		size = a.size;
		nums = new int[size];
		for (int i = 0; i < size; i++)
			nums[i] = a.nums[i];
		return *this;
	}
};
int main()
{
	int a[] = { 3,4,5,6 };
	A b(4, a);
	b.show();
	int c[] = { 10,15,20 };
	A d(3, c);
	d.show();
	A e(b);
	e = b = d;
	e.show();
	setlocale(LC_ALL, "Russian");
	system("pause");
	return 0;
}