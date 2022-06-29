#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class Auto_Detail {
private:
    string num;
    string name_details;
    string manufacturer;
    int price;
public:
    Auto_Detail(string num, string name_details, string manufacturer, int price) : num(num), name_details(name_details), manufacturer(manufacturer), price(price) {}
    
    bool operator < (Auto_Detail a) 
    {
        return num < a.num || (num == a.num && manufacturer < a.manufacturer);
    }

    friend std::ostream& operator<< (std::ostream&, const Auto_Detail&);
};

std::ostream& operator<< (std::ostream& out, const Auto_Detail& a)
{
    out << "Автозапчасти('" << a.num << "', " << a.name_details << ", '" << a.manufacturer << "', '" << a.price << "')\n";
    return out;
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    // Первый способ создания и заполнения вектора при его создании
    vector<Auto_Detail> Auto_Details1 = { Auto_Detail("21093-8402010-00", "Капот", "АО «АвтоВАЗ»", 1900),
                                          Auto_Detail("21140-8402910-00", "Капот", "АО «АвтоВАЗ»", 3900),
                                          Auto_Detail("21140-8403010-01", "Крыло переднее правое", "ПАО «КАМАЗ»", 1200),
                                          Auto_Detail("21083-6816083", "Ручка подлокотника левая", "АО «АвтоВАЗ»", 80),

    };
    // вывод на экран данных вектора "Auto_Details1"
    for (auto& a : Auto_Details1) std::cout << a; std::cout << '\n';

    // Второй способ создания и заполнения вектора после его создании 
    vector<Auto_Detail> Auto_Details2;
    Auto_Details2.insert(Auto_Details2.end(), Auto_Detail("21083-1003011 ", "Головка блока в сборе", "АО «АвтоВАЗ»", 16580));
    Auto_Details2.insert(Auto_Details2.end(), Auto_Detail("406-1006262 ", "Фланец промежуточного вала", "ОАО «ГАЗ» ", 175));
    Auto_Details2.insert(Auto_Details2.end(), Auto_Detail("21140-3711010-00", "Фара правая", "ЗАО «АВТОСВЕТ»", 1700));
    for (auto& a : Auto_Details2) std::cout << a; std::cout << '\n';

    vector<Auto_Detail> Auto_Details;
    // Копирование данных вектора "Auto_Details1" в вектор "Auto_Details"
    Auto_Details = Auto_Details1;
    for (auto& a : Auto_Details) std::cout << a; std::cout << '\n';

    // Копирование данных вектора "Auto_Details2" в конец вектора "Auto_Details"
    copy(Auto_Details2.begin(), Auto_Details2.end(), back_inserter(Auto_Details));
    for (auto& a : Auto_Details) std::cout << a; std::cout << '\n';

    // Сортировка вектора "Auto_Details"
    sort(Auto_Details.begin(), Auto_Details.end());
    for (auto& a : Auto_Details) std::cout << a; std::cout << '\n';
    Auto_Details1.clear();
    if (Auto_Details.empty()) std::cout << "вектор пустой\n";
    Auto_Details2.clear();
    Auto_Details.clear();
    return 0;
}
