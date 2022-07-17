//Дан массив целых чисел, количество элементов которого надо ввести с клавиатуры. 
//Найти максимальный элемент массива и его номер, при условии, что все элементы различны. Найти минимальный элемент массива

#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
void insertSort(int* A, int size);


void main() {
	const int max = 1000;
	setlocale(LC_ALL, "rus");
	int B[max]; int maxB = 0, minB = 0, size, maxNum, minNum;
	srand(time(NULL));
	cout << "Размер массива:";
	cin >> size;
	cout << "B:";
	for (int i = 0; i < size; i++)
	{

		B[i] = -500 + rand() % 1000;
		cout << B[i] << " ";

	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{

		if (B[i] > maxB) {
			maxB = B[i];
			maxNum = i + 1;
		}
	}
	for (int i = 0; i < size; i++)
	{


		if (B[i] < minB) {
			minB = B[i];
			minNum = i + 1;
		}
	}
	cout << endl;
	cout << "Максимальный элемент B: " << maxB << " Его номер:" << maxNum;
	cout << endl;
	cout << "Минимальный элемент B: " << minB << " Его номер:" << minNum;
	cout << endl;
	insertSort(B, size);
	cout << "Отсортированный массив " << "B:";
	for (int i = 0; i < size; i++)
	{
		cout << B[i] << " ";
	}
	cout << endl;


}

void insertSort(int* A, int size)
{
	int t, i, j;
	for (i = 1; i < size; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] > t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
	}
}