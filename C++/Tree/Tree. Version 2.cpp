#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>
//Создаём узел дерева
class Node {
private:
    T data;
    Node* left;
    Node* right;
public:
    Node(T& data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    T getData() {
        return data;
    }
    void setData(T& data) {
        this->data = data;
    }
    Node* getLeft() {
        return left;
    }
    void setLeft(Node* node) {
        this->left = node;
    }
    Node* getRight() {
        return right;
    }
    void setRight(Node* node) {
        this->right = node;
    }
};
template <class T>
//Создаём дерево
class tree {
private:
    Node<T>* root;
public:
    tree() : root(NULL) { }
    void deleteroot(Node<T>*);
    Node<T>* joinTree(Node<T>*, Node<T>*);
    Node<T>* deletenode(T&);
    void update(T&, T&);
    Node<T>* get_root() {
        return root;
    }
    Node<T>* insert(T)
        ;
    void show() {
        show(root);
    }
    void show(Node<T>*);
    Node<T>* find(T);
    bool empty();
    int heightoftree(Node<T>*);
};
template <class T>
void tree<T>::deleteroot(Node<T>* n) //удаление дерева
{
    if (n)
    {
        deletenode(n->getLeft());
        deletenode(n->getRight());
        delete n;
    }
}
template<class T>
Node<T>* tree<T>::joinTree(Node<T>* ndLeft, Node<T>* ndRight) {
    if (ndLeft == NULL) return ndRight;
    if (ndRight == NULL) return ndLeft;
    Node<T>* nd = ndLeft->getRight();
    if (nd == NULL) {
        ndLeft->setRight(ndRight);
        return ndLeft;
    }
    ndLeft->setRight(joinTree(nd->getLeft(), nd->getRight()));
    nd->setLeft(ndLeft);
    nd->setRight(ndRight);
    return nd;
}
template<class T>
Node<T>* tree<T>::deletenode(T& data) //удаление узла дерева
{
    if (root == NULL) return NULL;
    Node<T>* parent = root;
    if (data == root->getData()) {

        root = joinTree(root->getLeft(), root->getRight());
        return parent;
    }
    Node<T>* current = root;
    while (current) {
        if (data < current->getData()) {
            parent = current;
            current = current->getLeft();
        }
        else if (data > current->getData()) {
            parent = current;
            current = current->getRight();
        }
        else {
            if (parent->getLeft() == current)
                parent->setLeft(joinTree(current->getLeft(), current->getRight()));
            else
                parent->setRight(joinTree(current->getLeft(), current->getRight()));
            return current;
        }
    }
    return NULL;
}
template<class T>
void tree<T>::update(T& item1, T& item2) //обновление данных
{
    Node<T>* current = root;
    while (current != NULL)
    {
        if (item1 < current->getData()) {
            current = current->getLeft();
        }
        else if (item1 > current->getData()) {
            current = current->getRight();
        }
        else if (item1 == current->getData()) {
            current->setData(item2);
            return;
        }
    }
}
template <class T>
Node<T>* tree<T>::insert(T data) { //вставка новых данных
    if (root == NULL) {
        root = new Node<T>(data);
        return root;
    }
    Node<T>* temp = root;
    while (true) {
        if (data < temp->getData()) { //идем вниз налево
            if (temp->getLeft() == NULL) {
                temp->setLeft(new Node<T>(data));
                return temp->getLeft();
            }
            temp = temp->getLeft();
        }
        else if (data > temp->getData()) { // идем вниз направо
            if (temp->getRight() == NULL) {
                temp->setRight(new Node<T>(data));
                return temp->getRight();
            }
            temp = temp->getRight();
        }
        else { // Уже существует
            return NULL;
        }
    }
}
template<typename T>
void tree<T>::show(Node<T>* n) { // обход поддерева в порядке возрастания данных
    if (n) {
        show(n->getLeft());
        cout << n->getData() << endl;
        show(n->getRight());
    }
}
template<typename T>
Node<T>* tree<T>::find(T data) { // поиск данных
    Node<T>* temp = root;
    while (temp != NULL) {
        if (data < temp->getData()) //идем вниз налево
        {
            temp = temp->getLeft();
        }
        else if (data > temp->getData()) // идем вниз направо
        {
            temp = temp->getRight();
        }
        else if (data == temp->getData())
        {
            break; //найденный элемент
        }
    }
    return temp; // если текущее зач-е пустое, то ничего не найдено
}
template<typename T>
bool tree<T>::empty()
{
    return root == NULL;
}
//  нахождения высоты дерева
template<typename T>
int tree<T>::heightoftree(Node<T>* node)
{
    if (node == 0) return 0;
    int left = 0, right = 0;
    if (node->getLeft() != NULL)
    {
        left = heightoftree(node->getLeft());
    }
    else left = -1;
    if (node->getRight() != NULL)
    {
        right = heightoftree(node->getRight());
    }
    else right = -1;
    //используя тернарный оператор, определяем max
    int max = left > right ? left : right;
    return max + 1;
}
class Details { //Создаём класс запчастей
private:
    string vendor_code;
    string detail_name;
    string manufacturer;
    int price;
public:
    Details() : vendor_code(""), detail_name(""), manufacturer(""), price(0) { }
    Details(string vendor_code, string detail_name, string manufacturer, int price)
    {
        this->vendor_code = vendor_code;
        this->detail_name = detail_name;
        this->manufacturer = manufacturer;
        this->price = price;
    }
    Details(Details& temp) {
        vendor_code = temp.vendor_code;
        detail_name = temp.detail_name;
        manufacturer = temp.manufacturer;
        price = temp.price;
    }
    Details* get_Data();
    void set_Data(Details&);
    bool operator <(Details temp) { return (detail_name < temp.detail_name) || ((detail_name == temp.detail_name) && (manufacturer < temp.manufacturer)); }
    bool operator >(Details temp) { return (detail_name > temp.detail_name) || ((detail_name == temp.detail_name) && (manufacturer > temp.manufacturer)); }
    bool operator ==(Details temp) { return (vendor_code == temp.vendor_code); }
    friend bool operator<(const Details&, const Details&);
    friend bool operator>(const Details&, const Details&);
    friend bool operator==(const Details&, const Details&);
    Details& operator =(const Details&);
    friend ostream& operator<< (ostream&, const Details&);
};
Details* Details::get_Data()
{
    Details* temp = new Details();
    temp->vendor_code = vendor_code;
    temp->detail_name = detail_name;
    temp->manufacturer = manufacturer;
    temp->price = price;
    return temp;
}
void Details::set_Data(Details& temp) {
    vendor_code = temp.vendor_code;
    detail_name = temp.detail_name;
    manufacturer = temp.manufacturer;
    price = temp.price;
}

bool operator<(const Details& a1, const Details& a2) {
    return (a1.manufacturer < a2.manufacturer) || ((a1.manufacturer == a2.manufacturer) && (a1.detail_name < a2.detail_name));
}
bool operator>(const Details& a1, const Details& a2) {
    return (a2.manufacturer < a1.manufacturer) || ((a2.manufacturer == a1.manufacturer) && (a2.detail_name < a1.detail_name));
}
bool operator==(const Details& a1, const Details& a2) {
    return (a1.vendor_code == a2.vendor_code);
}
Details& Details::operator=(const Details& temp)
//проверка на самоприсваивание
{
    if (this == &temp) {
        return *this;
    }
    vendor_code = temp.vendor_code;
    detail_name = temp.detail_name;
    manufacturer = temp.manufacturer;
    price = temp.price;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const Details& a) //Вывод значений массива
{
    out << "Запчасти('" << a.vendor_code << "', '" << a.detail_name << "', '" << a.manufacturer << "', " << a.price << ")";
    return out;
}
int main() {
    setlocale(LC_ALL, "Russian");
    // заполнение данными полного бинарного дерева
    const int n = 7;
    Details table[] = {
        {"21093-8402010-00", "Капот", "АО «АвтоВАЗ»", 1900},
        {"21140-8402910-00", "Капот", "АО «АвтоВАЗ»", 3900},
        {"21140-8403010-01", "Крыло переднее правое", "ПАО «КАМАЗ» ", 1200},
        {"21083-6816083", "Ручка подлокотника левая", "АО «АвтоВАЗ»", 80},
        {"21083-1003011 ", "Головка блока в сборе", "АО «АвтоВАЗ»", 16580},
        {"406-1006262 ", "Фланец промежуточного вала", "ОАО «ГАЗ» ", 175},
        {"21140-3711010-00","Фара правая","ЗАО «АВТОСВЕТ»",1700}
    };
    tree<Details>* trees = new tree<Details>();
    Node<Details>* nd;
    for (int i = 0; i < n; i++) {
        nd = trees->insert(table[i]);
        if (nd == NULL) {
            cout << "NULL" << '\n';
        }
        else {
            cout << table[i] << '\n';
        }
    }
    cout << endl;
    cout << (trees->empty() ? "Дерево пустое" : "Дерево не пустое") << endl; //проверка на наличие дерева
    trees->show(); // просмотр всего дерева
    Details find_element = { "21140-8403010-01", "", "", 1200 }; // проверка поиска 
    if ((nd = trees->find(find_element)) == NULL) {
        cout << "Данная строка не найдена" << endl;
    }
    else {
        cout << nd->getData() << endl;
    }
    //удаляем узел дерева, соответствующий 3-й строке таблицы
    find_element = { "21140-8403010-01", "Крыло переднее правое", "ПАО «КАМАЗ» ", 1200 };
    if ((nd = trees->find(find_element)) == NULL)
    {
        cout << "Данная строка не найдена" << endl;
    }
    else {
        nd = trees->deletenode(find_element);
        cout << endl;
        trees->show();
        cout << endl;
    }
    //заменяем данные в узле дерева, соответствующие 5-й строке таблицы
    find_element = { "21083-1003011 ", "Головка блока в сборе", "АО «АвтоВАЗ»", 16580 };
    Details change("21083-1003011 ", "Головка блока в сборе", "ОАО «ГАЗ» ", 23480);
    if ((nd = trees->find(find_element)) == NULL) {
        cout << "Данная строка не найдена. Добавляем строку" << endl;
        nd = trees->insert(change);
        trees->show();
    }
    else {
        trees->update(find_element, change);
        cout << endl;
        trees->show();
        cout << endl;
    }
    //подсчёт высоты дерева
    int count = trees->heightoftree(trees->get_root());
    if (trees->empty()) {
        cout << "Дерево пустое" << endl;
    }
    else cout << "Высота дерева: " << count << endl;
    system("pause");
    return 0;
}
