
#include <iostream>
#include <string>


using namespace std;


template <typename T>
class Qeque
{
public:
	Qeque();
	~Qeque();
	void reverseTopLast();
	void reverse();
	void showList();
	T& GetData(int index);
	void sort();
	T pop();
	void push(T data);
	void clear();
	int GetSize() { return Size; }

	T& operator[](const int index);
private:

	template <typename T>
	struct Node
	{
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
Qeque<T>::Qeque()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
Qeque<T>::~Qeque()
{
	clear();
}

template<typename T>
void Qeque<T>::reverseTopLast()
{
	T tmp = this->head->data;
	Node<T>* pointer = this->head;
	while (pointer->pNext)
		pointer = pointer->pNext;
	this->head->data = pointer->data;
	pointer->data = tmp;
}
template<typename T>
void Qeque<T>::reverse()
{
	Qeque<T>* arr = new Qeque<T>();
	Node<T>* tmp = this.head;
	for (int i = 0; i < this.size; i++)
	{
		arr->push(tmp->data);
		tmp = tmp->pNext;
	}
	this->head= arr->head;
}
template<typename T>
void Qeque<T>::showList()
{
	for (int i = 0; i < this->GetSize(); i++)
		cout << this->GetData(i) << endl;

	cout << "\n\n";
}

template<typename T>
T& Qeque<T>::GetData(int index)
{
	Node<T>* show = head;
	if (index == 0) { return show->data; }

	else
	{
		for (int i = 0; i < index; i++)
			show = show->pNext;
		return show->data;
	}
}




template <typename T>
void Qeque<T>::sort() {

	Node<T>* left = this->head;                 //Первый элемент — это пусть будет голова
	Node<T>* right = this->head->pNext;          //Второй элемент — это пусть будет следующий за головой элемент

	Node<T>* temp = new Node<T>;              //Временное звено для хранения переставляемого всех значений переставляемого звена

	while (left->pNext) {                 //Обходим по всем звеньям, за исключением крайнего правого
		while (right) {              //Обходим по всем звеньям, включая крайний правый (по всем относительно первого левого на текущий момент)
			if ((left->data) > (right->data)) {        //Проверяем необходимость перестановки
				temp->data = left->data;               //И переставляем все внутренние элементы, за исключением указателей связи, местами
				left->data = right->data;             //Сейчас у нас имеется только x, поэтому только его
				right->data = temp->data;             //иначе бы  нужно было это проделывать для каждого несвязующего элемента
			}
			right = right->pNext;                    //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
		}
		left = left->pNext;                              //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
		right = left->pNext;                             //Поскольку второй указатель убежал немного вперёд, обязательно возвращаем его назад, это следующий элемент относительно текущего первого

	}
}






template<typename T>
T Qeque<T>::pop()
{
	if (Size == 1)
	{
		T data = head->data;
		Node<T>* ptr = head;
		head = nullptr;
		delete ptr;
		Size--;
		return data;
	}

	Node<T>* ptr = head;
	while(ptr->pNext->pNext)
		ptr = ptr->pNext;
	T data = ptr->pNext->data;
	Node<T>* tmp = ptr->pNext;
	ptr->pNext = nullptr;
	delete tmp;
	Size--;
	return data;
	}





template<typename T>
void Qeque<T>::push(T data)
{
	head = new Node<T>(data, head);
	++Size;
}

template<typename T>
void Qeque<T>::clear()
{

	while (Size)
	{
		pop();
	}
}




template <typename T>
T& Qeque<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->pNext;
	}
}

int stateMenu;
void Menu()
{
	cout << "(0) exit" << endl
		<< "(1) Add n elements to qeque" << endl
		<< "(2) Remove from qeque" << endl
		<< "(3) Show" << endl
		<< "(4) Clear" << endl
		<< "(5) Add element" << endl
		<< "(6) Sort qeque" << endl
		<< "Make your choice:";
	cin >> stateMenu;

}



int main()
{
	Menu();
	string a;
	string d;
	int actions,
		n = 0;
	Qeque<string>* list = new Qeque<string>();



	while (stateMenu != 0)
	{
		switch (stateMenu)
		{
		case 1:
			system("cls");
			cout << "Amount of elements: ";
			cin >> n;
			for (int i = 0; i < n; i++)
				list->push("Element " + to_string(i+1));
			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");
			system("cls");
			list->pop();
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			list->showList();
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			list->clear();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			cout << "Enter Data ";
			cin >> d;
			list->push(d);
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			list->sort();
			list->showList();
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}
