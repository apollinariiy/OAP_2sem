//----------------------------------------------------ДОП1----------------------------------------------------------------------------
//Дан массив из 10 элементов.Первые 4 элемента упорядочить по возрастанию, последние 4 по убыванию.
#include <iostream>
#include <cstdlib>
	using namespace std;

	void main() {
		setlocale(LC_CTYPE, "RU");
		int size = 10;
		int* B;
		B = new int[size];
		int i = 0;
		cout << "Рандомно сгенерированный массив:" << endl;
		for (i = 0; i < size; i++) {
			B[i] = rand() % 100;
			cout << B[i] << ' ';
		}cout << endl;

		cout << endl;
		cout << "Первые 4 элемента упорядочены по возрастанию, последние 4 по убывани:\n";
		for (int start = 0; start < 5; ++start)
		{
			int smallest = start;
			for (int current = start + 1; current < size; ++current)
			{
				if (B[current] < B[smallest])
					smallest = current;
			}
			swap(B[start], B[smallest]);
		}

		for (int start = 6; start < size; ++start)
		{
			int smallest = start;
			for (int current = start + 1; current < size; ++current)
			{
				if (B[current] > B[smallest])
					smallest = current;
			}
			swap(B[start], B[smallest]);
		}
		for (int i = 0; i < size; ++i)
		{
			if (B[i] > 0)
			{
				cout << B[i] << ' ';
			}
		}
		cout << endl;
	}

