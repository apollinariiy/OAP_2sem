#include "heap.h"
#include <iostream>
#include <fstream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else if (A2->x > A1->x)
		rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
bool buildHeap(char* FileName, heap::Heap& h)   // Построение кучи из файла
{
	bool rc = true;   int n;
	ifstream inFile;
	inFile.open(FileName, std::ios::out);
	if (!inFile)
	{
		cout << "Невозможно открыть файл" << endl;
		exit(1);
	}
	while (inFile >> n)
	{
		int* a = new int;
		*a = n;
		h.insert((void*)a);
	}
	inFile.close();
	return rc;
}
//-------------------------------
void SaveHeap(heap::Heap& h, char* FileName)    // Функция записи в файл
{
	ofstream  outFile(FileName, ios_base::out | ios_base::trunc);
	if (!outFile)
	{
		cout << "Ошибка открытия выходного файла" << std::endl;
		return;
	}
	int* a = new int;
	for (int u = 0, y = 0; u < h.size; u++)
	{
		a = (int*)h.storage[u];
		outFile << *a;
		outFile << endl;
	}
	outFile.close();
}
//-------------------------------
void Union(heap::Heap& h, heap::Heap& newh)
{
	int k;
	cout << "Введите ключи для новой кучи: ";
	do
	{
		AAA* a = new AAA;
		cin >> k;
		if (k == 0)
			break;
		a->x = k;
		newh.insert(a);
	} while (true);
	cout << "Ваша куча" << endl;
	newh.scan(0);
	while (newh.size)
	{
		h.insert(newh.extractI(1));
	}
	newh.deleteHeap();
	cout << "Объединение завершено." << endl;
}
//-------------------------------


void menu()
{
	cout << "1 - Вывод кучи на экран" << endl;
	cout << "2 - Добавить элементы" << endl;
	cout << "3 - Удалить максимальный элемент" << endl;
	cout << "4 - Удалить минимальный элемент" << endl;
	cout << "5 - Удалить i-й элемент" << endl;
	cout << "6 - Очистить кучу" << endl;
	cout << "7 - Запись в файл" << endl;
	cout << "8 - Вывод из файла" << endl;
	cout << "9 - Объединить кучи" << endl;
	cout << "10 - Четные элементы" << endl;
	cout << "11 - Нечетные элементы" << endl;
	cout << "12 - Сумма всех элементов" << endl;
	cout << "0 - Выход" << endl;
}
//-------------------------------
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	int k, i;
	int choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(15, cmpAAA);
	menu();
	for (;;)
	{
		cout << "Ввод: ";  cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
			h1.scan(0);
			break;
		case 2:
		{	cout << "Введите ключи: ";
		do
		{
			AAA* a = new AAA;
			cin >> k;
			if (k == 0)
				break;
			a->x = k;
			h1.insert(a);
		} while (true);
		}
		break;
		case 3:
			if (h1.extractMax())
				cout << "Удаление успешно завершено." << endl;
			break;
		case 4:
			if (h1.extractMin())
				cout << "Удаление успешно завершено." << endl;
			break;
		case 5:
			cout << "Ввведите номер удаляемого элемента: " << endl;
			cin >> i;
			if (h1.extractI(i))
				cout << "Удаление успешно завершено." << endl;
			break;
		case 6:
			h1.deleteHeap();
			break;
		case 7:
		{
			char u[6];
			cout << "Введите имя файла: (A.txt)" << endl;
			cin >> u;
			SaveHeap(h1, u);
			break;
		}
		case 8:
		{
			//h1.deleteHeap();
			char u[6];
			cout << "Введите имя файла: (A.txt)" << endl;
			cin >> u;
			buildHeap(u, h1);
			break;
		}
		case 9:
		{
			Union(h1, h2);
			break;
		}
		case 10:
		{
			int count = 0;
			for (int i = 0; i < h1.size; i++)
			{
				int* rc = (int*)h1.storage[i];
				if (*rc % 2 == 0)
					count++;
			}
			cout << count << endl;
			break;
		}
		case 11:
		{
			int count = 0;
			for (int i = 0; i < h1.size; i++)
			{
				int* rc = (int*)h1.storage[i];
				if (*rc % 2 != 0)
					count++;
			}
			cout << count << endl;
			break;
		}
		case 12:
		{
			int sum = 0;
			for (int i = 0; i < h1.size; i++)
			{
				int* rc = (int*)h1.storage[i];

				sum += *rc;
			}
			cout << sum << endl;
			break;
		}
		default:
			cout << endl << "Введена неверная команда!" << endl;
		}
		menu();
	} return 0;
}