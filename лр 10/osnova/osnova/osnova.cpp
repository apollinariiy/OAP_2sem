#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

// ============================ ВАРИАНТ 3 ============================

double square(int n, int i)
{
	if (i < n) return (sqrt(1 + (n + i) * square(n, i + 1)));
	else return sqrt(1 + (n + n));
}




// ============================ ВАРИАНТ 5 ============================

double factorial(int n)
{
	if (n < 0) return 0;
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}


double cNM(int n, int m)
{
	return factorial(n) / (factorial(m) * factorial(n - m));
}


double cCount(int n, int m)
{
	if (m > n || m < 0 || n < 0) return 0;
	if (m == 0 || n == m) return 1;
	else return cNM(n - 1, m) + cNM(n - 1, m - 1);
}




// ============================ ДОП 1 ============================

void dop1(int size, int* arr, int tmp)
{

	ofstream file("data.txt", ios_base::app);
	for (int i = 0; i <= size; i++) {
		arr[tmp] = i;
		if (tmp == size - 1) {
			for (int j = 0; j < size; j++)
			{
				cout << arr[j];
				file << arr[j];
			}
			cout << " ";
			file << " ";
		}
		else
			dop1(size, arr, tmp + 1);
	}
}




// ============================ ДОП 2 ============================

char c[50] = {};
char tr[50] = {};
int count = 0;

void dop2(string s, int count)
{
	if (count == strlen(c))
	{
		cout << s << endl;
		return;
	}

	for (int i = 0; i < strlen(c); i++)
	{
		if (!tr[i])
		{
			count++;
			string save = s;
			s += c[i];
			tr[i] = 1;
			dop2(s, count);
			count--;
			s = save;
			tr[i] = 0;
		}
	}
}




// ============================ ДОП 3 ============================

static char dop3(char* arr, const int& n, int m) {
	if (m < 26) dop3(arr, n, m + 1);
	if (m == 26) return arr[n + m];
}




// ============================  MAIN  ============================

int main()
{
	setlocale(LC_ALL, "russian");


	int i = 1;
	cout << "1st task: " << square(4, i) << endl;


	cout << "2nd task: " << cCount(7, 3) << endl;


	int A;
	cout << "Dop 1:\nEnter A: ";
	cin >> A;
	int* arr = new int[A];
	if (A == 1)
	{
		cout << 0 << " ";
		cout << 1 << '\n';

	}
	else
		for (int i = 1; i <= A; i++)
		{
			arr[0] = i;
			dop1(A, arr, 1);
		}


	cout << "Dop 2:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "\nEnter number:\n";
		cin >> c;
		cout << "All reshuffles:\n";
		dop2("", 0);
	}


	int max = 26;
	constexpr int size = 52;
	char array[size];
	int n = 0;
	for (int i = 0; i < max; i++)
	{
		array[i] = 'a' + i;
		array[i + max] = 'a' + i;
	}
	do
	{
		cout << "Введите число n меньше 26 и больше нуля: ";
		cin >> n;
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". " << array[i + 1] << endl;
		}
		cout << endl;
		cout << "Искомый символ: " << dop3(array, n, 0) << endl;
	} while (n);

}