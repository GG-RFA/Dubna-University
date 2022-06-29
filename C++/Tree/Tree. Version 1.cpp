#include <iostream>
#include <string>
using namespace std;

// Узел
template <class T>
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
// Дерево
template <class T>
class BinaryTree {
private:
    Node<T>* root;
public:
    BinaryTree() {
        root = NULL;
    }
    bool isEmpty() { // проверка на пустое дерево
        return root == NULL;
    }
    Node<T>* joinTree(Node<T>* ndLeft, Node<T>* ndRight) {
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
    Node<T>* delNode(T data) {
        if (root == NULL) return NULL;
        Node<T>* parent = root;
        if (data == root->getData()) {
            root = joinTree(root->getLeft(), root->getRight());
            return parent;
        }
        Node<T>* current = root;
        while (current) {
            if (data < current->getData()) { //идем вниз налево
                parent = current;
                current = current->getLeft();
            }
            else if (data > current->getData()) { // идем вниз направо
                parent = current;
                current = current->getRight();
            }
            else {  // Уже существует
                if (parent->getLeft() == current)
                    parent->setLeft(joinTree(current->getLeft(), current->getRight()));
                else
                    parent->setRight(joinTree(current->getLeft(), current->getRight()));
                return current;
            }
        }
        return NULL;
    }
    Node<T>* update(T& item) {
        Node<T>* current = root;
        if (current != NULL && current->getData() == item) {
            current->getData() = item;
        }
        else insert(item);
        return NULL;
    }
    Node<T>* insert(T data) { //вставка новых данных
        if (root == NULL) {
            root = new Node<T>(data);
            return root;
        }
        Node<T>* current = root;
        while (true) {
            if (data < current->getData()) { //идем вниз налево
                if (current->getLeft() == NULL) {
                    current->setLeft(new Node<T>(data));
                    return current->getLeft();
                }
                current = current->getLeft();
            }
            else if (data > current->getData()) { // идем вниз направо
                if (current->getRight() == NULL) {
                    current->setRight(new Node<T>(data));
                    return current->getRight();
                }
                current = current->getRight();
            }
            else {  // Уже существует
                return NULL;
            }
        }
    }
    void show() {  // обход всего дерева в порядке возрастания данных
        show(root);
    }
    void show(Node<T>* node) {  // обход поддерева в порядке возрастания данных
        if (node != NULL) {
            show(node->getLeft());
            cout << node->getData() << '\n';
            show(node->getRight());
        }
    }
    void del() {  // удаление всего дерева
        del(root);
        root = NULL;
    }
    void del(Node<T>* node) {  // удаление узлов поддерева
        if (node != NULL) {
            del(node->getLeft());
            del(node->getRight());
            delete(node);
        }
    }
    Node<T>* find(T data) {  // поиск данных по ключу
        Node<T>* current = root;
        while (current != NULL) {
            if (data < current->getData()) { //идем вниз налево
                current = current->getLeft();
            }
            else if (data > current->getData()) { // идем вниз направо
                current = current->getRight();
            }
            else {
                break; //найденный элемент
            }
        }
        return current; // если текущее зач-е пустое, то ничего не найдено
    }

};

class Details { //создаем класс Запчастей
private:
    string vendor_code;
    string detail_name;
    string manufacturer;
    int price;
public:
    Details() {
        vendor_code = "";
        detail_name = "";
        manufacturer = "";
        price = 0;
    }
    Details(string vendor_code, string detail_name, string manufacturer, int price) {
        this->vendor_code = vendor_code;
        this->detail_name = detail_name;
        this->manufacturer = manufacturer;
        this->price = price;
    }
    Details(Details& a) {
        vendor_code = a.vendor_code;
        detail_name = a.detail_name;
        manufacturer = a.manufacturer;
        price = a.price;
    }
    Details* getData() {
        Details* a = new Details();
        a->vendor_code = vendor_code;
        a->detail_name = detail_name;
        a->manufacturer = manufacturer;
        a->price = price;
        return a;
    }
    void setData(Details& a) {
        vendor_code = a.vendor_code;
        detail_name = a.detail_name;
        manufacturer = a.manufacturer;
        price = a.price;
    }
    Details& operator =(const Details& a) {
        //проверка на самоприсваивание
        if (this == &a) {
            return *this;
        }
        vendor_code = a.vendor_code;
        detail_name = a.detail_name;
        manufacturer = a.manufacturer;
        price = a.price;
        return *this;
    }
    bool operator==(Details a) {
        return(detail_name == a.detail_name) && (vendor_code == a.vendor_code);
    }
    bool operator <(Details a) {
        return (detail_name < a.detail_name) || ((detail_name == a.detail_name) && (vendor_code < a.vendor_code));
    }
    bool operator >(Details a) {
        return (detail_name > a.detail_name) || ((detail_name == a.detail_name) && (vendor_code > a.vendor_code));
    }
    friend bool operator==(const Details& a1, const Details& a2);
    friend bool operator<(const Details& a1, const Details& a2);
    friend bool operator>(const Details& a1, const Details& a2);
    friend std::ostream& operator<< (std::ostream& out, const Details& a);
};
bool operator==(const Details& a1, const Details& a2) {
    return(a1.detail_name == a2.detail_name) && (a1.vendor_code == a2.vendor_code);
}
bool operator<(const Details& a1, const Details& a2) {
    return (a1.detail_name < a2.detail_name) || ((a1.detail_name == a2.detail_name) && (a1.vendor_code < a2.vendor_code));
};
bool operator>(const Details& a1, const Details& a2) {
    return (a2.detail_name < a1.detail_name) || ((a2.detail_name == a1.detail_name) && (a2.vendor_code < a1.vendor_code));
};
std::ostream& operator<< (std::ostream& out, const Details& a)
{
    out << "Запчасти('" << a.vendor_code << "', '" << a.detail_name << "', '" << a.manufacturer << "', " << a.price << ")";
    return out;
}
int main() {
    setlocale(LC_ALL, "Russian");

    // заполнение данными бинарного дерева
    const int n = 7;
    Details R[] = { {"21093-8402010-00", "Капот", "АО «АвтоВАЗ»", 1900},
                    {"21140-8402910-00", "Капот", "АО «АвтоВАЗ»", 3900},
                    {"21140-8403010-01", "Крыло переднее правое","ПАО «КАМАЗ» ", 1200},
                    {"21083-6816083", "Ручка подлокотника левая","АО «АвтоВАЗ»", 80},
                    {"21083-1003011", "Головка блока в сборе","АО «АвтоВАЗ»", 16580 },
                    {"406-1006262", "Фланец промежуточного вала", "ОАО «ГАЗ» ", 175},
                    {"21140-3711010-00","Фара правая","ЗАО «АВТОСВЕТ»", 700}
    };

    BinaryTree<Details>* binaryTree = new BinaryTree<Details>();
    Node<Details>* nd;
    Details a;
    for (int i = 0; i < n; i++) {
        nd = binaryTree->insert(R[i]);
        if (nd == NULL)
            cout << "NULL" << '\t';
        else cout << R[i] << '\n';
    }
   
    cout << '\n';
    cout << (binaryTree->isEmpty() ? "Дерево пустое" : "Дерево не пустое") << '\n'; //проверка на наличие дерева

    // просмотр всего дерева 
    binaryTree->show();
    cout << '\n';
   

    // проверка программы поиска по ключу
    a = { "21140-8403010-00","Крыло переднее правое","ПАО «КАМАЗ»",1200 };
    nd = binaryTree->find(a);
    if (nd == NULL) {
        cout << a << " не найдено\n";
    }

    a = { "21140-8403010-01", "Крыло переднее правое", "ПАО «КАМАЗ»", 1200 };
    nd = binaryTree->find(a);
    if (nd != NULL) {
        cout << nd->getData() << " найдено\n";
    }
    //удаление узла
    a= { "21140-8403010-00", "Крыло переднее правое","ПАО «КАМАЗ» ", 1200 },
        nd = binaryTree->delNode(a);
    if (nd == NULL) {
        cout << a << "не найдено\n";
    }
    a = { "21140-8403010-01", "Крыло переднее правое","ПАО «КАМАЗ» ", 1200 },
        nd = binaryTree->delNode(a);
    if (nd != NULL) {
        cout<<nd->getData()<< " найдено\n";
    }
    //замена строки
    a = { "21083-1003011", "Головка блока в сборе","ОАО «ГАЗ»", 16580 },
        nd = binaryTree->find(a);
    if (nd!= NULL) {
        nd = binaryTree->delNode(a);
        nd = binaryTree->update(a);
        cout << '\n';
        cout << (binaryTree->isEmpty() ? "Дерево пустое" : "Дерево не пустое") << '\n'; //проверка на наличие дерева
        binaryTree->show();
        cout << '\n';
    }
    // удаление дерева
    binaryTree->del();
    cout << (binaryTree->isEmpty() ? "Дерево пустое" : "Дерево не пустое") << '\n';
    return 0;
}
