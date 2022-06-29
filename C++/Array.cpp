#include <iostream>
#include <string>
using namespace std;
class A {
private:

};
int main() {
	setlocale(LC_ALL, "Russian");
	char a[] = "Здравствуй,мир";
	char b[] = { 'П','р','и','в','е','т','\0' };
	cout « a « endl;
	for (int i = 0; i < sizeof(a) / sizeof(char); i++)
		cout « a[i];
	cout « endl;
	for (int i = 0; a[i] != '\0'; i++)
		cout « a[i];
	cout « endl;
	cout « b « endl;
	system("pause");
	return 0;
}