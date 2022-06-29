#include <string>
#include <iostream>
#include <Windows.h>
#define NULL '\0'//определение null в символьном контексте
using namespace std;
//Создаем класс студентов
class student {
	//Объявляем модификатор доступа типа private
private:
	//Объявляем необходимые переменные
	int number;
	string name;
public:
	//Создаем конструкторы одной переменной
	void SetNumber(int number)
	{
		this->number = number;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	//Создаем конструкторы двух переменных
	student(int number, string name) {
		this->number = number;
		this->name = name;
	}
	//конструктор с нулевыми параметрами
	student() {
		this->number = 0;
		this->name = NULL;
	}
	//Создаем функцию вывода
	void show() {
		cout << "Имя: " << name << "\t Номер: " << number << endl;
	}
	//Функция для возвращения переменной number
	int GetNumber() {
		return number;
	}
	//Функция для возвращения переменной name
	string GetName() {
		return name;
	}
};
//Создаем класс животных
class animals {
	//Объявляем модификатор доступа типа private
private:
	//Объявляем необходимые переменные
	string family;
	string name;
public:
	//Создаем конструкторы одной переменной
	void SetFamily(string family)
	{
		this->family = family;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	//Создаем конструкторы двух переменных
	animals(string family, string name) {
		this->family = family;
		this->name = name;
	}
	//конструктор с нулевыми параметрами
	animals() {
		this->family = NULL;

		this->name = NULL;
	}
	//Создаем функцию вывода
	void show() {
		cout << "Владелец: " << family << "\t Кличка собаки: " << name << endl;
	}
	//функция для возвращения значения family
	string GetFamily() {
		return family;
	}
	//функция для возвращения значения name
	string GetName() {
		return name;
	}
};
//Создаем шаблон для организации структуры
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
//Создаем шаблон для реализации списка с информацией о студентах
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
	//Функция для проверки
	void put(T s1) {
		if (current1 != hight1) {
			steck1[current1++] = s1;
		}
		else cout << "Ошибка!\n\n";
	}
	T get() {
		if (current1 > 0) {
			T t = T(steck1[--current1]);
			return t;
		}

		else {
			cout << "Ошибка!\n\n";
			return student();
		}
	}
};
//Создаем шаблон для реализации списка с информацией о животных
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
	//Функция для проверки
	void put(T s2) {
		if (current2 != hight2) {
			steck2[current2++] = s2;
		}
		else cout << "Ошибка!\n\n";
	}
	T get() {
		if (current2 > 0) {
			T t = T(steck2[--current2]);
			return t;
		}
		else {
			cout << "Ошибка!\n\n";
			return animals();
		}
	}
};
//Главная функция программы
int main() {
	setlocale(LC_ALL, "Russian");
	spisok1<student> students(2);
	//Создание объектов класса students
	students.put(student(3, "Иванов Иван"));
	students.put(student(10, "Сидорова Юля"));
	students.put(student(2, "Петрова Павла"));
	student p = students.get();
	//отображение значении 
	p.show();
	p = students.get();
	p.show();
	p = students.get();
	p.show();
	spisok2<animals> dog(1);
	//Создание объектов класса animals
	dog.put(animals("Иванов Иван", "Дружок"));
	dog.put(animals("Сидорова Юля", "Муска"));
	animals t = dog.get();
	t.show();
	t = dog.get();
	t.show();
	system("pause");//задержка консольного окна
	return 0;
}

