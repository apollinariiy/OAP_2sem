//Отдел кадров. Ф.И.О. работника, образование, специальность, подразделение, должность, оклад, дата поступления на предприятие. Выбор по стражу работы. Даты реализовать с помощью битового поля, должность  с помощью перечисления.
#include <iostream>
#include<fstream>
# define str_len 256
# define size 100
using namespace std;
void enter_new();
void out();
void del();
void search();
struct notebook
{
	char name[str_len];
	char surname[str_len];
	char middlename[str_len];
	unsigned day : 4;
	unsigned month : 4;
	unsigned year : 4;
	char addres[str_len];
	int phone;
	char place_of_work[str_len];
	char position[str_len];
};
struct notebook people_in_notebook[size];
int current_size = 0; int choice; int got;
notebook all;
notebook b;
int l, z, x;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для удаления" << endl;
	cout << "4-для поиска информации" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: del(); break;
		case 4: search(); break;


		}
	} while (choice != 5);
}
void enter_new()
{
	cout << "ввод информации" << endl;
	if (current_size < size)
	{
		cout << "строка номер ";
		cout << current_size + 1;
		cout << endl << "фамилия" << endl;
		cin >> people_in_notebook[current_size].surname;
		cout << "имя" << endl;
		cin >> people_in_notebook[current_size].name;
		cout << "отчество" << endl;
		cin >> people_in_notebook[current_size].middlename;
		cout << "дата поступления: " << endl;
		cout << "день:";
		cin >> l; b.day = l;
		cout << endl;
		cout << "месяц:";
		cin >> z; b.month = z;
		cout << endl;
		cout << "год:";
		cin >> x; b.year = x;
		cout << endl;
		cout << "образование:" << endl;
		cin >> people_in_notebook[current_size].addres;
		cout << "оклад:" << endl;
		cin >> people_in_notebook[current_size].phone;
		cout << "специальность:" << endl;
		cin >> people_in_notebook[current_size].place_of_work;
		cout << "должность:" << endl;
		cin >> people_in_notebook[current_size].position;
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
		cout << "номер выводимой строки: " << endl; cin >> n; cout << endl;
		cout << "фамилия" << endl;
		cout << people_in_notebook[n - 1].surname;
		cout << endl;
		cout << "имя" << endl;
		cout << people_in_notebook[n - 1].name;
		cout << endl;
		cout << "отчество" << endl;
		cout << people_in_notebook[n - 1].middlename;
		cout << endl;
		cout << "дата поступления: " << endl;
		cout << "день:";
		cout << l;
		cout << endl;
		cout << "месяц:";
		cout << z;
		cout << endl;
		cout << "год:";
		cout << x;
		cout << endl;
		cout << "образование:" << endl;
		cout << people_in_notebook[n - 1].addres;
		cout << endl;
		cout << "оклад:" << endl;
		cout << people_in_notebook[n - 1].phone;
		cout << endl;
		cout << "специальность:" << endl;
		cout << people_in_notebook[n - 1].place_of_work;
		cout << endl;
		cout << "должность:" << endl;
		cout << people_in_notebook[n - 1].position;
		cout << endl;


	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "фамилия" << endl;
			cout << people_in_notebook[i].surname;
			cout << endl;
			cout << "имя" << endl;
			cout << people_in_notebook[i].name;
			cout << endl;
			cout << "отчество" << endl;
			cout << people_in_notebook[i].middlename;
			cout << endl;
			cout << "дата рождения: " << endl;
			cout << "день:";
			cout << l;
			cout << endl;
			cout << "месяц:";
			cout << z;
			cout << endl;
			cout << "год:";
			cout << x;
			cout << endl;
			cout << "образование:" << endl;
			cout << people_in_notebook[i].addres;
			cout << endl;
			cout << "оклад:" << endl;
			cout << people_in_notebook[i].phone;
			cout << endl;
			cout << "специальность:" << endl;
			cout << people_in_notebook[i].place_of_work;
			cout << endl;
			cout << "должность:" << endl;
			cout << people_in_notebook[i].position;
			cout << endl;

		}
	}
	cout << "что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nномер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			people_in_notebook[de1] = people_in_notebook[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			people_in_notebook[i] = all;
	cout << "что дальше?" << endl;
	cin >> choice;
}
void search()
{
	
	cout << "дата поступления:" << endl << endl;
	cin >> got;
	for (int q = 0; q < current_size; q++)
	{
		if (got==x)
		{
			cout << "фамилия" << endl;
			cout << people_in_notebook[q].surname;
			cout << endl;
			cout << "имя" << endl;
			cout << people_in_notebook[q].name;
			cout << endl;
			cout << "отчество" << endl;
			cout << people_in_notebook[q].middlename;
			cout << endl;
			cout << "дата поступления: " << endl;
			cout << "день:";
			cout << l;
			cout << endl;
			cout << "месяц:";
			cout << z;
			cout << endl;
			cout << "год:";
			cout << x;
			cout << endl;
			cout << "образование:" << endl;
			cout << people_in_notebook[q].addres;
			cout << endl;
			cout << "оклад:" << endl;
			cout << people_in_notebook[q].phone;
			cout << endl;
			cout << "специальность:" << endl;
			cout << people_in_notebook[q].place_of_work;
			cout << endl;
			cout << "должность:" << endl;
			cout << people_in_notebook[q].position;
			cout << endl;
		}
	}
	cout << "что дальше?" << endl;
	cin >> choice;
}
