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
	string S = "Табельный номер: ФИО учителя: Должность: Пол:";
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
	void show() {
		cout « tabel_number « "\t"« name_employee « "\t"« position « "\t" « sex « endl;
	}
	string get_string() { return S; }
};
/*void show(school_employee* q, int n) {
cout « "Табельный номер: ФИО учителя: Должность: Пол:" « endl;
for (int i = 0; i < n; i++)
{
q[i].show();
}
}*/
class classes {
protected:
	string num_class;
	int tabel_number;
	string specialization;
	int class_room;
	school_employee* v;
	string S = "Номер класса: Табельный номер: Специализация: Классная комната:";
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
	void show() {
		cout « num_class « "\t" « v->getTabel_Num() « "\t" « specialization « "\t" « class_room « endl;
	}
	string get_string() { return S; }
};
/*void show(classes* t, int n) {
cout « "Номер класса: Табельный номер: Специализация: Классная комната:" « endl;
for (int i = 0; i < n; i++)
{
t[i].show();
}
}*/
class pupils {
protected:
	string num_class;
	int order_num;
	string pupil_name;
	string sex;
	classes* g;
	string S = "Номер класс: Порядковый №: Пол:";

public:
	pupils(string order_class, int order_num, string pupil_name, string sex, classes* g) {
		this->num_class = num_class;
		this->order_num = order_num;
		this->pupil_name = pupil_name;
		this->sex = sex;
		this->g = g;
	}
	void show() {
		cout « g->getNumClass() « "\t" « order_num « "\t" « sex « endl;
	}
	string get_string() { return S; }
};
/*void show(pupils * r, int n) {
cout « "Номер класса: Табельный номер: Специализация: Классная комната:" « endl;
for (int i = 0; i < n; i++)
{
r[i].show();
}
} */
template<typename T> void show(T* r, int n) {
	cout « r->get_string() « endl;
	for (int i = 0; i < n; i++)
	{
		r[i].show();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	school_employee q[] = { school_employee(108, "Петров Станислав Васильевич", "Учитель", "М"),
	school_employee(101,"Петрова Валентина Григорьевна","Учитель ","Ж"),
	school_employee(102,"Рыбакова Анна Ивановна ","Завуч ","Ж"),
	school_employee(103,"Федоров Юрий Васильевич ","Директор","М"),
	school_employee(104,"Смирнов Антон Юрьевич ","Учитель ","М") };
	show(q, 5);
	classes t[] = { classes("10A", 101,"Иностранные языки ", 203,&q[0]),
	classes("11Б",100,"Математика и физика ",212,&q[1]) };
	show(t, 2);
	pupils r[] = { pupils("10A", 1, "Иванов Сергей Петрович ","М",&t[0]),
	pupils("10A", 2, "Костин Петр Васильевич ","М",&t[1]),
	pupils("10A", 3, "Матросова Елена Ивановна","Ж",&t[2]),
	pupils("11Б", 1, "Богданов Юрий Сергеевич ","М",&t[3]),
	pupils("11Б", 2, "Потапова Юлия Петровна ","Ж",&t[4]),
	pupils("11Б", 3, "Сорокина Ольга Петровна ","Ж",&t[5]),
	pupils("11Б", 4, "Сидоров Андрей Петрович ","М",&t[6]) };
	show(r, 7);
	system("pause");
	return 0;
}