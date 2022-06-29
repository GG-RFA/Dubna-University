#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class school_employee {
protected:
	int tabel_number;
	string name_employee;
	string position;
	string sex;
public:
	school_employee(int tabel_number, string name_employee, string position, string sex) {
		this->tabel_number = tabel_number;
		this->name_employee = name_employee;
		this->position = position;
		this->sex = sex;
	}
	int getTabel_Num() {
		return tabel_number;
	}
	virtual void show() {
		cout « "Табельный номер:"« tabel_number « "\t ФИО учителя:"« name_employee «"\t Должность:"« position «"\t Пол:" « sex « endl;
	}
};
class classes {
protected:
	string num_class;
	int tabel_number;
	string specialization;
	int class_room;
	school_employee* v;
public:
	classes(string num_class, int tabel_number, string specialization, int class_room, school_employee* v) {
		this->num_class = num_class;
		this->tabel_number = tabel_number;
		this->specialization = specialization;
		this->class_room = class_room;
		this->v = v;
	}
	string getNumClass() {
		return num_class;
	}
	virtual void show() {
		cout « "Номер класса:" « num_class « "\t Табельный номер:" « v->getTabel_Num() « "\t Специализация:" « specialization « "\t Классная комната:" « class_room « endl;
	}
};
class pupils {
protected:
	string num_class;
	int order_num;
	string pupil_name;
	string sex;
	classes* g;

public:
	pupils(string order_class, int order_num, string pupil_name, string sex, classes* g) {
		this->num_class = num_class;
		this->order_num = order_num;
		this->pupil_name = pupil_name;
		this->sex = sex;
		this->g = g;
	}
	virtual void show() {
		cout « "Номер класс:" « g->getNumClass() «"\t Порядковый №:" « order_num « "\t Пол:" « sex « endl;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	school_employee q[] = { school_employee(108, "Петров Станислав Васильевич", "Учитель", "М") };
	q[0].show();
	classes t[] = { classes("10A", 101,"Иностранные языки", 203, &q[0]) };
	t[0].show();
	pupils r[] = { pupils("10A", 1, "Иванов Сергей Петрович","М", &t[0]) };
	r[0].show();
	system("pause");
	return 0;
}