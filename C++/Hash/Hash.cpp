#include<iostream>
#include<string>
using namespace std;
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
		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
		Node(Node* n, Node* next = nullptr)
		{
			this->data = n->data;
			this->next = next;
		}
	};

	Node<T>* head;
	int size;

public:

	List()
	{
		head = nullptr;
		size = 0;
	}

	void pushBack(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}

		else
		{
			Node<T>* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = new Node<T>(data);
		}
		++size;
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	friend ostream& operator<<(ostream& out, const List<T>& arg)
	{
		Node<T>* curr = arg.head;
		while (curr)
		{
			out << "-->" << curr->data;
			curr = curr->next;
		}
		return out;
	}

};

class Data /* Класс с данными */
{
private:
	int id;
	string PN;
	string ND;
	string MF;
	int price;
public:
	Data()
	{
		this->id = 0;
		this->ND = "";
		this->ND = "";
		this->MF = "";
		this->price = 0;
	}

	Data(int id, string PN, string ND, string MF, int price)
	{
		this->id = id;
		this->PN = PN;
		this->ND = ND;
		this->MF = MF;
		this->price = price;
	}

	friend int operator%(const Data& arg, int val)
	{
		if (val == 0)
		{
			throw runtime_error("zero division error");
		}
		return arg.id % val;

	}

	friend ostream& operator<<(ostream& out, const Data& arg)
	{
		out << "[" << arg.id << " " << arg.PN << " " << arg.ND << " " << arg.MF << " " << arg.price << "]";
		return out;
	}

};

template<class T>

class Hash

{

private:
	int K;
	List<T>* blocks;
	int checkPrime(int n)
	{
		if (n == 1 || n == 0)
		{
			return 0;
		}
		for (int i = 2; i < n / 2; i++)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}

	int getPrime(int n)
	{
		if (n % 2 == 0)
		{
			n++;
		}

		while (!checkPrime(n))
		{
			n = n + 2;
		}
		return n;
	}

	int hashFunction(T key)
	{
		return key % K;
	}

public:

	Hash(int size)
	{
		this->K = getPrime(size);
		blocks = new List<T>[K];
	}

	void insert(T data)
	{
		int index = hashFunction(data);
		blocks[index].pushBack(data);
	}

	void show()
	{
		for (int index = 0; index < K; index++)
		{
			cout << "ячейка[" << index << "]" << blocks[index] << endl;
		}
	}

};

int main() {
	setlocale(0, "");
	const int N = 7;
	Data mass[] = {
	Data(1234,"21093-8402010-00", "Капот", "АО «АвтоВАЗ»", 1900),
	Data(1235,"21140-8402910-00", "Капот", "АО «АвтоВАЗ»", 3900),
	Data(1236,"21140-8403010-01", "Крыло переднее правое", "ПАО «КАМАЗ»", 1200),
	Data(1237,"21083-6816083", "Ручка подлокотника левая", "АО «АвтоВАЗ»", 80),
	Data(1239,"21083-1003011 ", "Головка блока в сборе", "АО «АвтоВАЗ»", 16580),
	Data(1242,"406-1006262 ", "Фланец промежуточного вала", "ОАО «ГАЗ» ", 175),
	Data(1245, "21140-3711010-00","Фара правая","ЗАО «АВТОСВЕТ»", 1700)
	};

	Hash<Data> table(N);

	for (int index = 0; index < N; index++)
	{
		table.insert(mass[index]);
	}
	table.show();
	return 0;

}

