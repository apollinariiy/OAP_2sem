#include <iostream>
#include<fstream>
#include <iomanip>
#include <iostream>
#include<fstream>
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include<fstream>
#include <iostream>
#include<fstream>
# define size 100
using namespace std;
void enter_new();
void out();
void search();
void ofile();
void ifile();
union forstud
{
	char str[40];
	int limb;
	float nim;
};
struct stud
{
	forstud name;
	forstud surname;
	forstud middlename;
	forstud enterdate;
	forstud type;
	forstud group;
	forstud faculty;
	forstud average;
};
stud students[size];
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	cout << "4-для выхода" << endl;
	cout << "4-для вывода в файл" << endl;
	cout << "5-для вывода из файла" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: search(); break;
		case 4: ofile(); break;
		case 5: ifile(); break;
		}
	} while (choice != 4);
}
void enter_new()
{
	cout << "ввод информации" << endl;
	if (current_size < size)
	{
		cout << "строка номер ";
		cout << current_size + 1;
		cout << endl << "фамилия" << endl;
		cin >> students[current_size].surname.str;
		cout << "имя" << endl;
		cin >> students[current_size].name.str;
		cout << "отчество" << endl;
		cin >> students[current_size].middlename.str;
		cout << "дата поступления: " << endl;
		cin >> students[current_size].enterdate.str;
		cout << "специальность:" << endl;
		cin >> students[current_size].type.str;
		cout << "группа:" << endl;
		cin >> students[current_size].group.limb;
		cout << "факультет:" << endl;
		cin >> students[current_size].faculty.str;
		cout << "средний балл:" << endl;
		cin >> students[current_size].average.nim;
		current_size++;


	}
	else
		cout << "введено максимальное кол-во строк";
	cout << "что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "номер выводимой строки: " << endl;
		cin >> n;
		cout << endl;
		cout << "фамилия" << endl;
		cout << students[n - 1].surname.str;
		cout << "имя" << endl;
		cout << students[n - 1].name.str;
		cout << "отчество" << endl;
		cout << students[n - 1].middlename.str;
		cout << "дата поступления: " << endl;
		cout << students[n - 1].enterdate.str;
		cout << "специальность:" << endl;
		cout << students[n - 1].type.str;
		cout << "группа:" << endl;
		cout << students[n - 1].group.limb;
		cout << "факультет:" << endl;
		cout << students[n - 1].faculty.str;
		cout << "средний балл:" << endl;
		cout << students[n - 1].average.nim;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "фамилия" << endl;
			cout << students[i].surname.str;
			cout << "имя" << endl;
			cout << students[i].name.str;
			cout << "отчество" << endl;
			cout << students[i].middlename.str;
			cout << "дата поступления: " << endl;
			cout << students[i].enterdate.str;
			cout << "специальность:" << endl;
			cout << students[i].type.str;
			cout << "группа:" << endl;
			cout << students[i].group.limb;
			cout << "факультет:" << endl;
			cout << students[i].faculty.str;
			cout << "средний балл:" << endl;
			cout << students[i].average.nim;
		}
	}
	cout << "что дальше?" << endl;
	cin >> choice;
}
void search()
{
	float aver;
	cout << "введите средний балл:" << "\n";
	cin >> aver;
	for (int z = 0; z < current_size; z++)
	{
		if (students[z].average.nim == aver)
		{
			cout << "фамилия" << endl;
			cout << students[z].surname.str;
			cout << "имя" << endl;
			cout << students[z].name.str;
			cout << "отчество" << endl;
			cout << students[z].middlename.str;
			cout << "дата поступления: " << endl;
			cout << students[z].enterdate.str;
			cout << "специальность:" << endl;
			cout << students[z].type.str;
			cout << "группа:" << endl;
			cout << students[z].group.limb;
			cout << "факультет:" << endl;
			cout << students[z].faculty.str;
			cout << "средний балл:" << endl;
			cout << students[z].average.nim;
		}
	}
	cout << "что дальше?" << endl;
	cin >> choice;
}
void ofile()
{
	int N = 10;
	string buf;
	int num;
	do {
		cout << "Введите количество: ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < num; i++)
	{
		cout << "\tЧеловек №" << i + 1 << '\n';
		file1 << "\tЧеловек №" << i + 1 << '\n';
		cout << "Фамилия:\n";
		file1 << "Фамилия: ";
		cin >> students[current_size].surname.str;
		file1 << students[current_size].surname.str;
		cout << "Имя:\n";
		file1 << "\nИмя: ";
		cin >> students[current_size].name.str;
		file1 << students[current_size].name.str << "\n";
		cout << "Отчество:\n";
		file1 << "Отчество: ";
		cin >> students[current_size].middlename.str;
		file1 << students[current_size].middlename.str << "\n";
		cout << "Дата поступления:\n";
		file1 << "Дата поступления: ";
		cin >> students[current_size].enterdate.str;
		file1 << students[current_size].enterdate.str << "\n";
		cout << "специальность:\n";
		file1 << "специальность: ";
		cin >> students[current_size].type.str;
		file1 << students[current_size].type.str << "\n";
		cout << "факультет:\n";
		file1 << "факультет: ";
		cin >> students[current_size].faculty.str;
		file1 << students[current_size].faculty.str << "\n";
	}
	cout << "\n\n";
	cout << "что дальше?" << endl;
	cin >> choice;
}
void ifile()
{
	int h = 0;
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
		h++;
		if (h == 7) {
			exit(0);
		}
	}
	cout << "что дальше?" << endl;
	cin >> choice;
}