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
		cout « "Имя " « name « "\t Номер: " « number « endl;
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
		cout « "Владелец: " « family « "\t кличка собаки: " « name « endl;
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

template <class T> class spisok1 {
private:
	T* steck1;
	int current1;
	int hight1;
public:
	spisok1(int hight1) {
		steck1 = new T[hight1];
		current1 = 0;
		this->hight1 = hight1;
	}

	void put(T s1) {
		if (current1 != hight1) {
			steck1[current1++] = s1;
		}
		else cout « "Ошибка\n\n";
	}
	T get() {
		if (current1 > 0) {
			T t = T(steck1[--current1]);
			return t;
		}
		else {
			cout « "Ошибка\n\n";
			return student();
		}
	}
};
template <class T> class spisok2 {
private:
	T* steck2;
	int current2;
	int hight2;
public:
	spisok2(int hight2) {
		steck2 = new T[hight2];
		current2 = 0;
		this->hight2 = hight2;
	}

	void put(T s2) {
		if (current2 != hight2) {
			steck2[current2++] = s2;
		}
		else cout « "Ошибка\n\n";
	}
	T get() {
		if (current2 > 0) {
			T t = T(steck2[--current2]);
			return t;
		}
		else {
			cout « "Ошибка\n\n";
			return animals();
		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	spisok1<student> students(2);
	students.put(student(3, "Иванов Иван"));
	students.put(student(10, "Сидорова Юля"));
	students.put(student(2, "Петрова Павла"));
	student p = students.get();
	p.show();
	p = students.get();
	p.show();
	p = students.get();
	p.show();
	spisok2<animals> dog(1);
	dog.put(animals("Иванов Иван", "Дружок"));
	dog.put(animals("Сидорова Юля", "Муска"));
	animals t = dog.get();
	t.show();
	t = dog.get();
	t.show();
	system("pause");
}