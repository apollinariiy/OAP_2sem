/*1 доп
Дополнить проект, разработав функцию
deleteList (удаление списка) и функцию
countList (подсчет числа элементов списка).
В содержимом списка отразить информацию
в соответствии со своим вариантом из лабораторной
работы № 4. Создать интерфейс в виде меню.
Клиенты банка. Ф.И.О., тип счета (срочный,
льготный и т. д.), номер счета, сумма
на счете, дата последне-го изменения.
Выбор по номеру счета.
*/
#include <iostream>
#include "List.h"
using namespace std;
void insert(address* e, address** phead, address** plast)
{
	address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

address* setelement()
{
	address* temp = new address();
	if (!temp)
	{
		cerr << "ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "введите фамилию: ";
	cin >> temp->surname;
	cout << "введите имя: ";
	cin >> temp->name;
	cout << "введите отчество: ";
	cin >> temp->parentname;
	cout << "адрес: ";
	cin >> temp->type;
	cout << "введите год рождения: ";
	cin >> temp->number;
	cout << "пол: ";
	cin >> temp->sum;
	
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputlist(address** phead, address** plast)
{
	address* t = *phead;
	if (t == NULL)
	{
		cout << "список пуст!" << endl;
	}
	while (t)
	{
		cout << "фамилия:" << t->surname << endl;
		cout << "имя:" << t->name << endl;
		cout << "отчество:" << t->parentname << endl;
		cout << "адрес:" << t->type << endl;
		cout << "год рождения:" << t->number << endl;
		cout << "пол:" << t->sum << endl;
		
		t = t->next;
	}
	cout << "" << endl;
}
void find(char number[NAME_SIZE], address** phead)
{
	address* t = *phead;
	while (t)
	{
		if (!strcmp(number, t->number)) break;
		t = t->next;
	}
	if (!t)
		cerr << "имя не найдено" << endl;
	else
		cout << "фамилия:" << t->surname << endl;
	cout << "имя:" << t->name << endl;
	cout << "отчество:" << t->parentname << endl;
	cout << "адрес:" << t->type << endl;
	cout << "год рождения:" << t->number << endl;
	cout << "пол:" << t->sum << endl;
	
}
void countlist(address** phead, address** plast)
{
	address* t = *phead;
	int i = 0;
	while (t != NULL)
	{
		i++;
		t = t->next;
	}
	cout << "количество элементов=" << i << endl;
}
void delall(address** phead, address** plast)
{
	address* t = *phead;
	while (t != NULL)
	{

		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		t = t->next;
		delete t;
	}
	cout << "список очищен!" << endl;
}
int main()
{
	address* head = NULL;
	address* last = NULL;
	setlocale(LC_CTYPE, "rus");
	int choice;
	char s[80]; int c;
	cout << endl;
	cout << "1. ввод элемента" << endl;
	cout << "2. вывод на экран" << endl;
	cout << "3. поиск" << endl;
	cout << "4. количсетво элементов" << endl;
	cout << "5. очищение списка" << endl;
	cout << "6. выход" << endl;
	cout << endl;
	for (;;)
	{
		cout << "ваш выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1: insert(setelement(), &head, &last);
			break;
		case 2: outputlist(&head, &last);
			break;
		case 3: { char fnumber[NAME_SIZE];
			cout << "введите год рождения: ";
			cin >> fnumber;
			find(fnumber, &head);
		}
			  break;
		case 4: {

			countlist(&head, &last);
		}
			  break;
		case 5: {
			delall(&head, &last);
		}
			  break;
		case 6: exit(0);
		default: exit(1);
		}
	}
 return 0;
}