#include "Header.h"

void insertToQueue(qmanager* My_Queue)  //Добавление элемента в очередь
{
	char n;
	cin >> n;

	Queue* p = new Queue;
	p->size = n;

	if (My_Queue->head == NULL) {
		My_Queue->head = My_Queue->tail = p;
		p->next = NULL;
	}
	else {
		p->next = My_Queue->tail;
		My_Queue->tail = p;
	}
	system("CLS");
}

void showQueue(qmanager* My_Queue) {
	Queue* p = new Queue;
	p = My_Queue->tail;
	int count = 0;
	while (p) {
		cout << p->size << " ";
		p = p->next;
		count++;
	}
	cout << "---- size = " << count << endl;
}
void deletion(qmanager* My_Queue) {
	Queue* p = new Queue;
	Queue* previous = new Queue;
	p = My_Queue->tail;
	previous = NULL;
	while (p->next && p->next->next) {
		p = p->next;
	}
	if (My_Queue->head == My_Queue->tail) {
		My_Queue->tail = My_Queue->head = 0;
		delete(p);
	}
	else {
		My_Queue->head = p;
		previous = p;
		p = p->next;
		previous->next = NULL;
		delete(p);
	}
}
void task(qmanager* My_Queue) {
	//Создать очередь для символов и функции для ввода, вывода и удаления элементов очереди.Ввести символы с клавиатуры.
	//	Ввести эталонный символ и проверить, имеется ли он в очереди.
	//	При его наличии в очереди, удалить все элементы до него.
	char n;
	cin >> n;
	int k = 1;
	Queue* p = new Queue;
	p = My_Queue->tail;
	while (p) {
		if (p->size == n) {
			Queue* a = new Queue;
			a = p;
			Queue* previous = a;
			a = a->next;
			while (k <= 2) {
				if (a->next == NULL)
					My_Queue->head = previous;
				if (a == My_Queue->tail) {
					My_Queue->tail = a->next;
				}
				if (previous)
					previous->next = a->next;
				Queue* tmp = a;
				a = a->next;
				delete(tmp);
				k++;
			}
		}
		p = p->next;
	}
	system("CLS");
}