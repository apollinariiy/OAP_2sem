#include "Header.h"

void push(struct Stack*& MyStack) {
	char chislo[9];
	cout << "����� ���������, ������� q\n����: ";
	while (cin >> chislo && *chislo != 'q') {
		Stack* data = new Stack;
		data->number = atoi(chislo);
		data->next = MyStack->head;
		MyStack->head = data;
	}
	cout << "���� �������!\n";
	return;
}

void clearStack(Stack*& MyStack) {
	if (!MyStack->head) { cout << "���� ����!\n"; }
	else {
		while (MyStack->head) {
			Stack* delStack = MyStack->head;
			MyStack->head = MyStack->head->next;
			delete delStack;
		}
		cout << "���� ������!\n";
	}
}


void showStack(Stack*& MyStack) {
	Stack* data = MyStack->head;
	if (!MyStack->head) { cout << "���� ����\n"; }
	else { cout << "����� �����: \n"; }
	while (data) {
		cout << data->number << "\n";
		data = data->next;
	}
}

void find(Stack* MySt1, Stack* MySt2, Stack* MySt3) {
	if (!MySt1->head) { cout << "���� ����!\n"; }
	else {
		Stack* MyStack1 = new Stack;
		MyStack1->head = MySt1->head;
		int a[20];
		int n = 0;
		while (MyStack1->head) {
			a[n] = MyStack1->head->number;
			MyStack1->head = MyStack1->head->next;
			n++;
		}

		int b[20], c[20];
		int k = 0, l = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				b[k] = a[i];
				k++;
			}
			if (a[i] < 0) {
				c[l] = a[i];
				l++;
			}
		}

		for (int i = 0; i < k; i++) {
			Stack* data = new Stack;
			data->number = b[i];
			data->next = MySt2->head;
			MySt2->head = data;
		}

		for (int i = 0; i < l; i++) {
			Stack* data = new Stack;
			data->number = c[i];
			data->next = MySt3->head;
			MySt3->head = data;
		}
	}
}

void WriteInFile(Stack* MySt, string fileName) {
	if (!MySt->head) { cout << "���� ������\n"; }
	else {
		ofstream FILE;
		FILE.open(fileName);
		Stack* MyStack = new Stack;
		MyStack->head = MySt->head;
		FILE << "����� �����: ";
		while (MyStack->head) {
			FILE << "\n\t\t" << MyStack->head->number;
			MyStack->head = MyStack->head->next;
		}
		cout << "���� ������� � ���� " << fileName << endl;
		
	}
}

void ReadFromFile(Stack* MySt, string fileName) {
	int indicate;
	ifstream FILE;
	FILE.open(fileName, ofstream::app);
	if (!(FILE >> indicate)) { cout << "���� ����\n"; }
	else {
		while (indicate) {
			Stack* data = new Stack;
			data->number = indicate;
			data->next = MySt->head;
			MySt->head = data;
			if (!(FILE >> indicate)) { break; }
		}
		cout << "������ �������!\n";
	}
	FILE.close();
}
