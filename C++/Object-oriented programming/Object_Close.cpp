#include <iostream>
#include <string>

using namespace std;
class A
{
public: string name;
	  A(string name) { this->name = name; }
	  //A() { name = "***"; }
	  ~A() { cout « "Закрыть объект" « "\n"; }
	  void show() { cout « name « "\n"; }
};
int main() {
	setlocale(0, "");
	A a("A"), b("B");
	A* c = new A("C");
	a.show(); b.show(); c->show();
	delete c;
	return 0;
}