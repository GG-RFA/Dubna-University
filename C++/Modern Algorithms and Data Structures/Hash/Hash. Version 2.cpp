#include<iostream>
#include<string>
#include<cstring>

template<class T>
class List
{
private:
    template<class T>
    class Node
    {
    public:
        T data;
        Node* next;
        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
        Node(Node* n, Node* next = nullptr) {
            this->data = n->data;
            this->next = next;
        }
    };
    Node<T>* head;
    int size;
public:
    List() {
        head = nullptr;
        size = 0;
    }
    void pushBack(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
        }
        else {
            Node<T>* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node<T>(data);
        }
        ++size;
    }
    bool isEmpty() { return head == nullptr; }
    friend std::ostream& operator<<(std::ostream& out, const List<T>& arg) {
        Node<T>* curr = arg.head;
        while (curr) {
            out << "-->" << curr->data;
            curr = curr->next;
        }
        return out;
    }
};

class Data {
private:
    std::string article;
    std::string name;
    std::string pr;
    int price;
public:
    Data() {
        this->article = "";
        this->name = "";
        this->pr = "";
        this->price = 0;
    }
    Data(std::string article, std::string name, std::string pr, int price) {
        this->article = article;
        this->name = name;
        this->pr = pr;
        this->price = price;
    }
    friend int operator%(const Data& arg, int val) {
        const char* str = arg.article.c_str();
        /*if (val == 0) {
            throw std::runtime_error("zero division error");
        }*/
        int code = 0;
        for (int index = 0; index < strlen(str); index++) {
            int cc = static_cast<unsigned char>(str[index]);
            //std::cout << cc << " ";
            code += cc;
        }
        //std::cout << std::endl;
        return code % val;
    }
    friend std::ostream& operator<<(std::ostream& out, const Data& arg) {
        out << "[" << arg.article << " " << arg.name << " " << arg.pr << " " << arg.price << "]";
        return out;
    }
};

template<class T>
class Hash
{
private:
    int K;
    List<T>* blocks;
    int checkPrime(int n) {
        if (n == 1 || n == 0) {
            return 0;
        }
        for (int i = 2; i < n / 2; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n) {
        if (n % 2 == 0) {
            n++;
        }
        while (!checkPrime(n)) {
            n = n + 2;
        }
        return n;
    }
    int hashFunction(T key) {
        return key % K;
    }
public:
    Hash(int size) {
        this->K = getPrime(size);
        blocks = new List<T>[K];
    }
    void insert(T data) {
        int index = hashFunction(data);
        blocks[index].pushBack(data);
    }
    void show() {
        for (int index = 0; index < K; index++) {
            std::cout << "ячейка[" << index << "]" << blocks[index] << std::endl;
        }
    }
};

int main() {
    setlocale(0, "");
    const int N = 3;
    Data mass[] = {
        Data("21093-8402010-00", "Иванов Сергей Степанович", "Разнорабочий", 28000),
        Data("21140-8402910-00", "Краснов Сергей Георгиевич", "Сантехник", 32000),
        Data("21140-8403010-01", "Бендер Остап Ибрагимович", "Директор", 62000),
        Data("21083-6816083", "Петров Сергей Степанович", "Электрик", 36000),
        Data("21083-1003011", "Кирпичев Владимир Викторович", "Начальник смены", 48000),
        Data("406-1006262", "Абрамов Иван Петрович", "Электрик", 36000),
        Data("21140-3711010-00", "Абрамов Иван Петрович", "Электрик", 36000)
    };
    Hash<Data> table(N);
    for (int index = 0; index < sizeof(mass) / sizeof(Data); index++) {
        table.insert(mass[index]);
    }
    table.show();
    return 0;
}