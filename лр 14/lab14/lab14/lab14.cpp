// В соответствии со своим вариантом построить хеш - таблицы разного размера(например, 16, 32 или 32, 64, 128) с коллизиями.
// Исследовать время поиска в хеш - таблицах. В приложении Excel построить соответствующие графики.
// Реализовать динамическую хеш-таблицу с открытой адресацией для хранения строк. Таблица должна увеличивать свой размер вдвое при достижении
// 50% заполнения.

//#include "stdafx.h"
#include "Hash.h"
#include <iostream>
using namespace std;
struct AAA //основная хэшевая структура
{
	int key;
	const char* mas;
	AAA(int k, const char* z)
	{
		key = k;  mas = z;

	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	AAA a1(1, "one"), a2(2, "two"), a3(4, "three"), a4(2, "four");
	int siz = 10, choice, k, siz2 = 0, siz3 = 0;
	cout << "Введите размер хеш-таблицы" << endl; 	cin >> siz;
	siz2 = siz / 2;
	siz3 = 2 * siz;
	Object H = create(siz, key);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: { AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;	cin >> k;
			a->key = k;
			cout << "введите строку" << endl; cin >> str;
			a->mas = str;

			int count = 0;

			if (H.N == H.size)
				cout << "Таблица заполнена" << endl;
			else
				H.insert(a);
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));
		}  break;
		}
	}
	return 0;
}