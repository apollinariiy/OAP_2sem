 //Ввести массивы А и В.В массив С перенести четные элементы массива А и нечетные элемента массива В.Массив С отсортировать по убыванию, 
 //используя алгоритмы сортировок : «пузырек», сортировка Хоара.

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
using namespace std;
void qs(int* c, int first, int last);
void main()
{
    setlocale(LC_ALL, "rus");
    int a[5], b[6], c[11];
    int q = 0;
    int* p = a; int* r = b; int* s = c;
    int i, j, k, tmp;

    cout << "Массив A: " << endl;
    for (int i = 0; i < 6; i++) {
        *p = rand() % 40;
        cout << *p << "\t";
        p++;
    }
    cout << endl;

    cout << "Массив B: " << endl;
    for (int i = 0; i < 6; i++) {
        *r = rand() % 40;
        cout << *r << "\t";
        r++;
    }
    cout << endl;

    p = a;
    r = b;
    for (i = 0; i < 6; i++) {
        if (a[i] % 2 == 0)
        {
            *s = a[i];
            cout << *s << "\t";
            s++;
        }
    }
    for (i = 0; i < 6; i++) {
        if (b[i] % 2 != 0) {
            *s = b[i];
            cout << *s << "\t";
            s++;
        }
    }
    s = c;
    int size = 11;
    cout << endl;
    cout << "Сортировка методом пузырька:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (c[i] < c[j]) swap(c[i], c[j]);
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (c[i] >= 0) {
            cout << c[i] << " ";
        }
    }
    cout << endl;

    cout << "Сортировка методом Хоара:\n";
    
    qs(c, 0, size - 1);
    	for (int i = 0; i < size; i++)
    	{
    		if (c[i] >= 0) {
    			cout << c[i] << " ";
    		}
    	}
    _getch();
}
void qs(int* c, int first, int last)
{
    int i = first, j = last, x =c[(first + last) / 2];

    do {
        while (c[i] < x) i++;
        while (c[j] > x) j--;

        if (i <= j) {
            if (c[i] < c[j]) swap(c[i], c[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        qs(c, i, last);
    if (first < j)
        qs(c, first, j);
}
