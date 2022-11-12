#include <iostream>;
#include <stdio.h>;
using namespace std;

struct Element
{
	Element* next;
	Element* previous;
	double value;
};

class List
{
public:
	Element* Head, * Tail, * Current, *temp;
	List() 
	{
		cout << "Введите значение первой double-переменной в списке - ";
		temp = new Element();
		cin >> temp->value;
		Head = temp;
		Head->previous = NULL;
		Current = Head;
		Tail = Head;
		Tail->next = NULL;

		cout << "\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - "<< Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
	}
	~List()
	{	
		Current = Head;
		while (Current->next != NULL)
		{
			Current = Current->next;
			delete Current->previous;
		}
		delete temp, Head, Tail, Current;
	}
	void Next() {
		if (Current != Tail)
		{
			Current = Current->next;
			cout << "\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - " << Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
		}
		else 
		{
			cout << "Ошибка! Конец списка!\n\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - " << Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
		}
	}
	void Prev() {
		if (Current != Head)
		{
			Current = Current->previous;
			cout << "\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - " << Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
		}
		else
		{
			cout << "Ошибка! Начало списка!\n\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - " << Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
		}
	}
	void AddNewElement()
	{
		temp = new Element();
		cout << "Введите значение новой double-переменной - ";
		cin >> temp->value;
		Tail->next = temp;
		temp->previous = Tail;
		temp->next = NULL;
		Tail = temp;
		cout << "\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - " << Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
	}
	void AddNewElement(double sp_key)
	{
		temp = new Element();
		temp->value = sp_key;
		Tail->next = temp;
		temp->previous = Tail;
		temp->next = NULL;
		Tail = temp;
	}
	int AddAfter(double k) {
		temp = new Element();
		Element* Checker = Head;

		while (Checker->next != NULL)
		{
			if (Checker->value == k)
			{
				temp = new Element();
				cout << "Введите новое значение - ";
				double keys = 0;
				cin >> keys;
				if (Checker == Tail)
				{
					AddNewElement(keys);
				}
				else 
				{
					temp->value = keys;
					temp->next = Checker->next;
					temp->previous = Checker;
					Checker->next = temp;
					Checker->next->next->previous = temp;
				}
				cout << "\nУСПЕХ!\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - " << Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
				return 1;
			}
			else {
				Checker = Checker->next;
			}
		}
		if (Checker->value == k)
		{
			temp = new Element();
			cout << "Введите новое значение - ";
			double keys = 0;
			cin >> keys;
			if (Checker == Tail)
			{
				AddNewElement(keys);
			}
			else
			{
				temp->value = keys;
				temp->next = Checker->next;
				temp->previous = Checker;
				Checker->next = temp;
				Checker->next->next->previous = temp;
			}
			cout << "\nУСПЕХ!\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - " << Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
			return 1;
		}
		cout << "\nНЕУДАЧА!\nНЕТ ЭЛЕМЕНТА!\nВыбранный элемент списка - " << Current << "\nСледующий элемент - " << Current->next << "\nЗначение элемента - " << Current->value << "\nПредыдущий элемент - " << Current->previous << endl;
		return -1;
	}
};

int main() {
	system("chcp 1251");
	system("cls");

	List* l = new List();

	while (true) 
	{
		cout << "\n1 - Следующий элемент\n2 - Предыдущий элемент\n3 - Добавить в конец\n4 - Добавить после определенной double-переменной\n0 - Выход";
		int answer = 0;
		cout << "\n\nВаш ответ - ";
		cin >> answer;
		cout << endl;

		switch (answer)
		{
		case 1:
			l->Next();
			break;
		case 2:
			l->Prev();
			break;
		case 3:
			l->AddNewElement();
			break;
		case 4:
			double key;
			cout << "Введите искомое вещественное число - ";
			cin >> key;
			l->AddAfter(key);
			break;
		case 0:
			delete l;
			return 1;
			break;
		default:
			break;
		}
	}
}