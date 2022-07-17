// laba8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	qmanager* My_Queue = new qmanager;
	My_Queue->head = NULL;
	My_Queue->tail = NULL;

	int key;
	do {
		showQueue(My_Queue);
		cout << "------------------\n";
		cin >> key;
		system("CLS");
		switch (key) {
		case 1: insertToQueue(My_Queue); break;
		case 2: deletion(My_Queue); break;
		case 3: task(My_Queue); break;
		}
	} while (key != 10);
}