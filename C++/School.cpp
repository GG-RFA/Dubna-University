#include <iostream>
#include <string>
using namespace std;

template <typename T>
void insertSort(T data[], int n) {
	int i = 0;
	T key;
	for (int j = 1; j < n; j++) {
		key = data[j];
		for (i = j; i > 0; i--) {
			if (data[i - 1] < key) {
				break;
			}
			data[i] = data[i - 1];
		}
		data[i] = key;
	}
}
class pupil {
private:
	string num_class;
	int num_magazine;
	string FIO;
	string sex;
public:
	pupil() : num_class(""), num_magazine(0), FIO(""), sex("") {};
	pupil(string num_class, int num_magazine, string FIO, string sex) : num_class(num_class), num_magazine(num_magazine), FIO(FIO), sex(sex) {};
	string toString() {
		return num_class + '\t' + to_string(num_magazine) + '\t' + FIO + '\t' + sex + '\n';
	}
	int operator <(pupil& st) {
		return (sex < st.sex) || (sex == st.sex) && (FIO < st.FIO);
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 6;
	pupil A[n] = { pupil("10A", 1, "Иванов Сергей Петрович","М"),
	pupil("10A", 2, "Костин Петр Васильевич","М"),
	pupil("10A", 3, "Матросова Елена Ивановна","Ж"),
	pupil("11Б", 1, "Богданов Юрий Сергеевич","М"),
	pupil("11Б", 2, "Потапова Юлия Петровна","Ж"),
	pupil("11Б", 3, "Сорокина Ольга Петровна","Ж") };
	insertSort(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i].toString();
	cout << '\n';
	return 0;
}