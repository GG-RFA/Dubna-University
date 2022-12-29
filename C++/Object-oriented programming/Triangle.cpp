#include <iostream>
#include <string>
using namespace std;
class Point3D {
protected:
	int x;
	int y;
	int z;
	string name;
public:
	Point3D(int x, int y, int z, string name) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->name = name;
	}
	Point3D() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->name = name;
	}
	virtual void show() {
		cout «"point " + name« "\tx=" « x « "\t y=" « y « "\t z=" « z « endl;
	}
	double length(Point3D C) {
		return sqrt(pow((C.x - x), 2) + pow((C.y - y), 2) + pow((C.z - z), 2));
	}
	bool equality(Point3D C) {
		if (length(C) == 0)
			return true;
		else
			return false;
	}
};
class Triangle :public Point3D {
public:
	Point3D A, B, C;
	string name;
public:Triangle(Point3D A, Point3D B, Point3D C, string name) {
	this->A = A;
	this->B = B;
	this->C = C;
	this->name = name;
}
	  void show() {
		  A.show();
		  B.show();
		  C.show();
	  }
	  double triangle_square() {
		  double p;
		  p = (A.length(B) + B.length(C) + C.length(A)) / 2;
		  return sqrt(p * (p - A.length(B)) * (p - B.length(C)) * (p - C.length(A)));
	  }
	  void sort(double* arr) {
		  int size = 3;
		  int temp;
		  for (int i = 0; i < size - 1; i++) {
			  for (int j = 0; j < size - i - 1; j++) {
				  if (arr[j] > arr[j + 1]) {
					  temp = arr[j];
					  arr[j] = arr[j + 1];
					  arr[j + 1] = temp;
				  }
			  }
		  }
	  }
	  bool equality(Triangle ABC) {
		  double a[] = { A.length(B),B.length(C),C.length(A) };
		  double b[] = { ABC.A.length(ABC.B),ABC.B.length(ABC.C),ABC.C.length(ABC.A) };
		  sort(b);
		  sort(a);
		  return((b[0] == a[0]) && (b[1] == a[1]) && (b[2] == a[2]));
	  }
};
class Pyramide : public Point3D {
protected:
	Point3D A, B, C, D;
	string name;
public:
	Pyramide(Point3D A, Point3D B, Point3D C, Point3D D) {

	}
	double triangle_square() {
		Triangle ABC(A, B, D, "ABD"), ABC1(A, B, C, "ABC"), ABC2(B, C, D, "BCD"), ABC3(A, C, D, "ACD");
		cout « ABC.triangle_square() + ABC1.triangle_square() + ABC2.triangle_square() + ABC3.triangle_square();
		double p;
		p = (A.length(B) + B.length(C) + C.length(A)) / 2;
		return sqrt(p * (p - A.length(B)) * (p - B.length(C)) * (p - C.length(A)));
	}
	bool equality(Pyramide ABCD) {

	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Point3D A(1, 2, 3, "First");
	Point3D B(4, 5, 6, "Second");
	Point3D C(7, 8, 9, "Third");
	Point3D A1(10, 11, 12, "Fourth");
	Point3D B1(13, 14, 15, "Fifth");
	Point3D C1(16, 17, 18, "Sixth");
	Triangle ABC(A, B, C, "ABC");
	Triangle ABC1(A1, B1, C1, "ABC1");
	if (ABC.equality(ABC1)) {
		cout « "Треугольники равны" « endl;
	}
	else {
		cout « "Треугольники не равны" « endl;
	}
	if (A.equality(B)) {
		cout « "Точки равны";
	}
	else {
		cout « "Точки не равны";
	}
	cout « "Расстояние между точками:" « A.length(B);
	system("pause");
	return 0;
}