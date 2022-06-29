#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class personal {
protected:
	int tabel_number;
	string name_employee;
	string position;
	int salary;
public:
	personal(int tabel_number, string name_employee, string position, int salary) {
		this->tabel_number = tabel_number;
		this->name_employee = name_employee;
		this->position = position;
		this->salary = salary;
	}
	personal(int tabel_number) {
		this->tabel_number = tabel_number;
	}
	virtual void show() {
		cout «"Табельный номер:"« tabel_number «"\t ФИО работника:"« name_employee «"\t Должность:"« position «"\t Оклад:" « salary « endl;
	}
};
class group :public personal {
protected:
	string num_group;
	string name_group;
public:
	group(string num_group, string name_group, personal p) :personal(p) {
		this->num_group = num_group;
		this->name_group = name_group;
	}
	string getNumGroup() {
		return num_group;
	}
	/* group(string num_group) {
	this->num_group = num_group;
	} */
	virtual void show() {
		cout « "Номер группы:" « num_group « "\t Имя группы:" « name_group « "\t Табельный номер:" «tabel_number « endl;
	}
};
class children {
protected:
	int order_num;
	string name_children;
	string data;
	group* g;
public:
	children(int order_num, string name_children, string data, group* f) {
		this->order_num = order_num;
		this->name_children = name_children;
		this->data = data;
		this->g = f;
	}
	virtual void show() {
		cout « "Порядковый номер:" « order_num «"\t ФИО ребенка:" « name_children « "\t Дата рождения:" «data «"\t номер группы:"« g->getNumGroup() « endl;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	personal q[] = { personal(108, "Самохина В.П.", "Ст.воспитатель", 32000),
	personal(109, "Смирнов А.С.", "воспитатель", 20000) };
	q[0].show();
	group t[] = { group("М", "Младшая",q[0]) };
	t[0].show();
	children r[] = { children(1001, "Иванов Алеша", "2009-10-30", &t[0]) };
	r[0].show();
	system("pause");
	return 0;
}