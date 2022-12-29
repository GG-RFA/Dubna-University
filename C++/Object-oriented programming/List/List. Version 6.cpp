#include <string>
#include <iostream>
#include <Windows.h>
#define NULL '\0'

using namespace std;
class student {
private:
	int number;
	string name;
public:
	void SetNumber(int number)
	{
		this->number = number;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	student(int number, string name) {
		this->number = number;
		this->name = name;
	}
	student() {
		this->number = 0;
		this->name = NULL;
	}
	void show() {
		cout « "Имя " « name « " Номер: " « number « endl;
	}
	int GetNumber() {
		return number;
	}
	string GetName() {
		return name;
	}

};
class animals {
private:
	string family;
	string name;
public:
	void SetFamily(string family)
	{
		this->family = family;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	animals(string family, string name) {
		this->family = family;
		this->name = name;
	}
	animals() {
		this->family = NULL;
		this->name = NULL;
	}
	void show() {
		cout « "Владелец " « family « " кличка собаки: " « name « endl;
	}
	string GetFamily() {
		return family;
	}
	string GetName() {
		return name;
	}

};
class Auto {
private:
	string mark;
	int capacity;
	int power;
public:
	Auto(string mark, int capacity, int power) {
		this->mark = mark;
		this->capacity = capacity;
		this->power = power;
	}
	void SetMark(string mark) {
		this->mark = mark;
	}
	void SetCapacity(int capacity) {
		this->capacity = capacity;
	}
	void SetPower(int power) {
		this->power = power;
	}
	Auto() {
		this->mark = NULL;
		this->capacity = 0;
		this->power = 0;
	}
	void show() {
		cout « "Марка автомобиля:" « mark « "\t Вместимость:" « capacity « "\t Мощность автомобиля:" « power « endl;
	}
	string GetMark() {
		return mark;
	}
	int GetCapacity() {
		return capacity;
	}
	int GetPower() {
		return power;
	}
};
template <class T>class struct1 {
private:
	T s1;
	struct1* next;
public:
	struct1(T s, struct1* d) {
		next = d;
		s1 = s;
	}
	T getT() { return s1; }
	struct1* getstruct1() { return next; }
};

template <class T>void spisok(T* s, int n) {
	struct1<T>* start = NULL;
	for (int i = 0; i < n; i++) {
		start = new struct1<T>(s[i], start);
	}
	struct1<T>* next = start;
	while (next != NULL) {
		next->getT().show();
		next = next->getstruct1();
	}
}

template <class V>class struct2 {
private:
	V a2;
	struct2* next;
public:
	struct2(V a, struct2* f) {
		next = f;
		a2 = a;
	}
	V getV() { return a2; }
	struct2* getstruct2() { return next; }
};
template <class V>void list(V* a, int g) {
	struct2<V>* start = NULL;
	for (int j = 0; j < g; j++) {
		start = new struct2<V>(a[j], start);
	}
	struct2<V>* next = start;
	while (next != NULL) {
		next->getV().show();
		next = next->getstruct2();
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	student students[] = {
	student(3, "Иванов Иван"),
	student(10, "Сидорова Юля"),
	student(2, "Петрова Павла")
	};
	int n = sizeof(students) / sizeof(student);
	spisok(students, n);

	animals dog[] = {
	animals("Иванов Иван","Дружок"),
	animals("Сидорова Юля", "Муска")
	};
	int n1 = sizeof(dog) / sizeof(animals);
	spisok(dog, n1);

	Auto cars[] = {
	Auto("BWV-5",5,200),
	Auto("Toyota",7,350)
	};
	int n2 = sizeof(cars) / sizeof(Auto);
	list(cars, n2);
	system("pause");
}