
#include <iostream>
#include <string>
using namespace std;

template<typename T>
void ShellSort(T data[], int n) {
	int i = 0;
	T key;
	int step = n / 2;
	while (step > 0) {
		for (int j = step; j < n; j++) {
			key = data[j];
			for (i = j; i > 0; i -= step) {
				if (data[i - step] < key) {
					break;
				}
				data[i] = data[i - step];
			}
			data[i] = key;
		}
		/*for (int k = 0; k < n; k++);
			cout << data[k] << ' ';
			cout << '\n';
			step /= 2;*/
	}
}

class parts {
private:
	string vendor_code;
	string part_name;
	string manufacturer;
	int price;
public:
	parts() : vendor_code(""), part_name(""), manufacturer(""), price(0) {};
	parts(string vendor_code, string part_name, string manufacturer, int price) : vendor_code(vendor_code), part_name(part_name), manufacturer(manufacturer), price(price) {};
	string toString() {
		return vendor_code + '\t' + part_name + '\t' + manufacturer + '\t' + to_string(price) + '\n';
	}
	int operator <(parts& st) {
		return (manufacturer < st.manufacturer) || (manufacturer == manufacturer) && (vendor_code < vendor_code);
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 7;
	parts A[n] = { parts("21093-8402010-00", "Капот", "АО «АвтоВАЗ»", 1900),
	parts("21140-8402910-00 ", "Капот", "АО «АвтоВАЗ»", 3900),
	parts("21140-8403010-01", "Крыло переднее правое", "ПАО «КАМАЗ» ", 1200),
	parts("21083-6816083", "Ручка подлокотника левая", "АО «АвтоВАЗ»",80),
	parts("21083-1003011 ", "Головка блока в сборе", "АО «АвтоВАЗ»",16580),
	parts("406-1006262", "Фланец промежуточного вала", "ОАО «ГАЗ» ",175),
	parts("21140-3711010-00","Фара правая","ЗАО «АВТОСВЕТ»",1700) };
	ShellSort(A, n);
	for (int i = 0; i < n; i++)
	cout << A[i].toString();
	cout << '\n';
	return 0;
}