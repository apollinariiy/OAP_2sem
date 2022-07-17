//Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж).Реализовать выборку по полу и году рождения. 
# include <iostream> 
#include <iostream>
#include <fstream>
#include <string>
# define str_len 30                               
# define size 30  
int choice;
using namespace std;
struct Gorozhanin //структура
{
	char name[str_len];
	int year_of_birth;
	char adres[str_len];
	char pol[str_len];
};
struct Gorozhanin list_of_gorozhanin[size];
struct Gorozhanin bad;
int current_size = 0;
void enter_new() //функция ввода
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		
		printf("\n Строка номер %d \n", current_size + 1);

		printf(" ФИО \r\n");
		getchar();
		gets_s(list_of_gorozhanin[current_size].name);
		
		printf(" Год рождения \n");
		cin >> list_of_gorozhanin[current_size].year_of_birth;
		

		printf(" Пол(м_ж) \n");
		cin >> list_of_gorozhanin[current_size].pol;

		printf(" Адрес \n");
		getchar();
		gets_s(list_of_gorozhanin[current_size].adres);
		printf("\n ");
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
}
void ofile()
{
	int N = 10;
	string buf;
	int num;
	do {
		cout << "Введите количество грожданинов: ";
		cin >> num;
	} while (num < 1 || num > N);
	fflush(stdin);
	ofstream file1("information.txt");
	for (int i = 0; i < num; i++)
	{
		cout << "\tГрожданин №" << i + 1 << '\n';
		file1 << "\tГрожданин №" << i + 1 << '\n';
		cout << "Введите ФИО клиента:\n";
		file1 << "ФИО клиента: ";
		cin >> list_of_gorozhanin[current_size].name;
		file1 << list_of_gorozhanin[current_size].name ;
		cout << "Введите год рождения:\n";
		file1 << "\nГод: ";
		cin >> list_of_gorozhanin[current_size].year_of_birth;
		file1 << list_of_gorozhanin[current_size].year_of_birth << "\n";
		cout << "Введите пол:\n";
		file1 << "Пол: ";
		cin >> list_of_gorozhanin[current_size].pol;
		file1 << list_of_gorozhanin[current_size].pol << "\n";
		cout << "Введите адрес:\n";
		file1 << "Адрес: ";
		cin >> list_of_gorozhanin[current_size].adres;
		file1 << list_of_gorozhanin[current_size].adres << "\n\n";
	}
	cout << "\n\n";
}
void ifile()
{
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}
}
void del() //функция удаления
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_gorozhanin[de1] = list_of_gorozhanin[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list_of_gorozhanin[i] = bad;

}


void outputOneStructure(Gorozhanin oneGorozhanin) //вывод одной строки 
{
	cout << "Фамилия ";
	cout << oneGorozhanin.name << endl;
	cout << "Год рождения ";
	cout << oneGorozhanin.year_of_birth << endl;
	cout << "Адрес  ";
	cout << oneGorozhanin.adres << endl;
	cout << "Пол(м,ж) ";
	cout << oneGorozhanin.pol << endl;
	cout << endl;
}


void out() //функция вывода информации
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		outputOneStructure(list_of_gorozhanin[n - 1]);
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			outputOneStructure(list_of_gorozhanin[i]);
		}
	}
}
void search() //функция поиска информаци
{
	int year_for_search = 0;
	char  pol_for_search[str_len];
	cout << "Введите год рождения для поиска" << endl;;
	cin >> year_for_search;
	cout << endl;;
	int amount = 0;
	bool ignorePol = false;
	if (strcmp(pol_for_search, "*") == 0) {
		ignorePol = true;
	}
	printf("Результат:\n");
	for (int i = 0; i < size; i++)
	{
		
			if (year_for_search == list_of_gorozhanin[i].year_of_birth)
			{
				amount++;
				outputOneStructure(list_of_gorozhanin[i]);
			}
		
	}
	printf("Всего найдено:%d\n\n", amount);


}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Данных нет" << endl;
	do
	{
		cout << "Введите:" << endl;
		cout << "1-для удаления записи" << endl;
		cout << "2-для ввода новой записи" << endl;
		cout << "3-для поиска по году рождения" << endl;
		cout << "4-для вывода записи(ей)" << endl;
		cout << "5-для ввода в файл" << endl;
		cout << "6-для вывода из файла" << endl;
		cout << "6-для выхода" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3: search(); break;
		case 4:  out();	break;
		case 5: ofile();	break;
		case 6: ifile();	break;
		}
	} while (choice != 5);
}