




//Преподаватели. Фамилия преподавателя, название экзамена, дата экзамена. Выбор по фамилии.

#include <iostream>  
#include<fstream>
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define size 100  
using namespace std;
void enter_new();
void out();
void search();
void ofile();
void ifile();

union forLombard
{
	char str[20];
	int limb;
};
struct Lombard
{
	forLombard name;
	forLombard predmet;
	forLombard data;
};
Lombard raspisanie[size];
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите число:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	cout << "4-для вывода в файл" << endl;
	cout << "5-для вывода из файла" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  search();	break;
		case 4:  ofile();	break;
		case 5:  ifile();	break;
		}
	} while (choice != 4);
}
void ofile()
{
	int N = 10;
	string buf;
	int num;
	do {
		cout << "Введите количество экзаменов: ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < num; i++)
	{
		cout << "\tЭкзамен №" << i + 1 << '\n';
		file1 << "\tЭкзамен №" << i + 1 << '\n';
		cout << "Фамилия преподователя";
		file1 << "Фамилия преподовател:";
		cin >> raspisanie[current_size].predmet.str;
		file1 << raspisanie[current_size].predmet.str;
		cout << "Название предмета:\n";
		file1 << "\nНазвание предмета: ";
		cin >> raspisanie[current_size].name.str;
		file1 << raspisanie[current_size].name.str << "\n";
		cout << "Дата:\n";
		file1 << "Дата: ";
		cin >> raspisanie[current_size].data.str;
		file1 << raspisanie[current_size].data.str << "\n" << "\n\n";
	}
	cout << "\n\n";
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
		if (h == 4) {
			exit(0);
		}

	}
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер  ";
		cout << current_size + 1;
		cout << "\n";
		cout << "                     " << "Расписание экзаменов" << "\n";
		cout << endl << "Фамилия преподователя:" << endl;
		cin >> raspisanie[current_size].predmet.str;
		cout << "Название предмета:" << endl;
		cin >> raspisanie[current_size].name.str;
		cout << "Дата:" << endl;
		cin >> raspisanie[current_size].data.str;
		current_size++;

	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывести 1 строку" << endl;
	cout << "2-вывести все строки" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки: " << endl;
		cin >> n;
		cout << endl;
		cout << "                     " << "Расписание" << "\n";
		cout << "Фамилия преподователя:";
		cout << raspisanie[n - 1].predmet.str;
		cout << endl;
		cout << "Название экзмаена:";
		cout << raspisanie[n - 1].name.str;
		cout << endl;
		cout << "Дата:";
		cout << raspisanie[n - 1].data.str;
		cout << endl;
		
		
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "                     " << "Расписание экзаменов" << "\n";
			cout << endl << "Фамилия преподователя:";
			cout << raspisanie[i].predmet.str << endl;
			cout << "Название предмета:" ;
			cout << raspisanie[i].name.str << endl;
			cout << "Дата:";
			cout << raspisanie[i].data.str << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	char name[16];
	cout << "Введите фамилию:" << "\n";
	cin >> name;
	for (int z = 0; z < current_size; z++)
	{
		if (strcmp(name, raspisanie[z].predmet.str) == 0)
		{
			cout << " " << "\nРасписание: " << "\n\n";
			cout << "Фамилия:";
			cout << raspisanie[z].predmet.str;
			cout << endl;
			cout << "Имя:";
			cout << raspisanie[z].name.str;
			cout << endl;
			cout << "Дата рождения:";
			cout << raspisanie[z].data.str;
			cout << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}