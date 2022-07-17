#include <iostream>
#include <time.h>
#include <stdlib.h>
# define N 10
using namespace std;
clock_t t1, t2;

void ShakerSort(int a[], int n)
{
	int left, right, i;
	left = 0;
	right = n - 1;
	while (left <= right)
	{
		for (i = right; i >= left; i--)
		{
			if (a[i - 1] > a[i])
			{
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
			}
		}
		left++;
		for (i = left; i <= right; i++)
		{
			if (a[i - 1] > a[i])
			{
				int temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
			}
		}
		right--;
	}
}

void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void PiramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}

void insOrd(int m[], int sm, int em, int e)
{
	int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}

void Merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
}

void SortMerge(int m[], int lm, int sm = 0)
{
	if (lm > 1)
	{
		SortMerge(m, lm / 2, sm);
		SortMerge(m, lm - lm / 2, sm + lm / 2);
		Merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
}

void print_array(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	cout << endl;
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A[N];
	int* C = new int[N];

	for (int i = 0; i < N; ++i) {
		srand(time(0) * (i - 5));
		A[i] = rand() % 100;
	}

	int size = 10;

	cout << "Массив A[]: ";
	print_array(A, size);
	memcpy(C, A, size * sizeof(int));
	PiramSort(C, size);
	cout << "Сортировка слиянием:" << endl;
	print_array(C, size);
	cout << "<><><><><><><><><><><><><><><>" << endl;
	memcpy(C, A, size * sizeof(int));
	PiramSort(C, size);
	cout << "Пирамидальная сортировка:" << endl;
	print_array(C, size);
	cout << "<><><><><><><><><><><><><><><>" << endl;
	memcpy(C, A, size * sizeof(int));
	ShakerSort(C, size);
	cout << "Шейкерная сортировка:" << endl;
	print_array(C, size);
	cout << "<><><><><><><><><><><><><><><>" << endl;

	cout << "Сама сортировка: " << endl;
	for (int p = 1000; p <= 5000; p += 1000)
	{
		cout << "Количество элементов = " << p << endl;
		cout << "1. Сортировка слиянием" << endl;
		cout << "2. Пирамидальная сортировка" << endl;
		cout << "3. Шейкерная сортировка" << endl;
		int* a = new int[p], * b = new int[p];
		srand(time(0));
		for (int i = 0; i < p; i++)
		{
			a[i] = rand() % (p * 10);
		}
		memcpy(b, a, p * sizeof(int));
		t1 = clock(); SortMerge(b, p);  t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << endl;
		memcpy(b, a, p * sizeof(int));
		t1 = clock(); PiramSort(b, p);  t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << endl;
		memcpy(b, a, p * sizeof(int));
		t1 = clock(); ShakerSort(b, p);  t2 = clock();
		cout << "Прошло " << t2 - t1 << " тактов времени" << endl;
		cout << endl;
	}
}