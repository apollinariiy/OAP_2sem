/*3. Содержимое текстового файла f, разделенное на строки, переписать в текстовый файл g, перенося при этом
		в конец каждой строки все входящие в нее цифры(с сохранением исходного взаимного порядка,
		как среди цифр, так и среди остальных литер строки).Использовать очереди*/

#include <iostream>
#include <fstream>
#include<string>
using namespace std;

struct Queue
{
	char size;
	Queue* next;
};

struct qmanager {
	Queue* head;
	Queue* tail;
};

void insertToQueue(qmanager* My_Queue, char n)
{
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
char deletion(qmanager* My_Queue) {
	Queue* p = new Queue;
	Queue* previous = new Queue;
	p = My_Queue->tail;
	previous = NULL;
	while (p->next && p->next->next) {
		p = p->next;
	}
	if (My_Queue->head == My_Queue->tail) {
		char a;
		a = p->size;
		My_Queue->tail = My_Queue->head = NULL;
		delete(p);
		return(a);
	}
	else {
		char a;
		My_Queue->head = p;
		previous = p;
		p = p->next;
		a = p->size;
		previous->next = NULL;
		delete(p);
		return a;
	}
}

int main()
{
	
	qmanager* My_Queue = new qmanager;
	My_Queue->head = NULL;
	My_Queue->tail = NULL;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	string z;

	while (getline(fin, z)) {
		for (int i = 0; i < z.length(); i++) {
			if ((z[i] >= '0') && (z[i] <= '9'))
				insertToQueue(My_Queue, z[i]);
		}
		fout << z;

		while (My_Queue->head) {
			fout << deletion(My_Queue);
		}
		fout << endl;
	}
}