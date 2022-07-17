//----------------------------------------------------ДОП2----------------------------------------------------------------------------
    // Дан массив из 15 целых чисел на отрезке [-5; 5]. Упорядочить массив, удалив повторяющиеся элементы.

#include <iostream>
#include <cstdlib>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "RU");
    
    int m = 15;
    int s1 = 0, s2 = 0;
    
    int* arr = new int[m]; 
    int* brr = new int[m];

    for (int i = 0; i < m; i++)
    {
        arr[i] = -5 + rand() % (5 + 5 + 1);
        cout << arr[i] << " ";
    }
    cout << "\n"; 
    
    cout << "Упорядоченный массив с удаленными повторяющимися элементами: " << endl;
    int CurIndex = 0;
    bool Found;
    for (int i = 0; i < 20; i++)
    {
        Found = false;
        for (int j = 0; j < CurIndex; j++)
            if (brr[j] == arr[i])
            {
                Found = true;
                break;
            }
        if (!Found)
            brr[CurIndex++] = arr[i];
    }
    // Создаём динамический массив с размерностью равной кол-ву уникальных элементов исходного и переписываем в него элементы из временного массива
    int* DimFinal = new int[CurIndex];
    for (int i = 0; i < CurIndex; i++)
    {
        DimFinal[i] = brr[i];
    }

    for (int start = 0; start < CurIndex; ++start)
    {
        int smallest = start;
        for (int current = start + 1; current < CurIndex; ++current)
        {
            if (DimFinal[current] < DimFinal[smallest])
                smallest = current;
        }
        swap(DimFinal[start], DimFinal[smallest]);
    }
    for (int i = 0; i < CurIndex; ++i)
    {
        if (DimFinal[i] > -10 && DimFinal[i] < 10)
        {
            cout << DimFinal[i] << ' ';
        }
    }
    cout << endl;
}

