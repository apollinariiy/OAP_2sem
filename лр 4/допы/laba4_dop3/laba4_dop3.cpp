// laba4_dop3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct sanat {
	string name;
	string location;
	string medicalProfile;
	int numberOfPackages;
};
sanat s[100];
int k = 0;
void fileread() {
	ifstream fin("input.txt");

	int count;
	string check;
	getline(fin, check);
	count = stoi(check);
	for (int i = 0; i < count; i++) {
		getline(fin, s[i].name);
		getline(fin, s[i].location);
		getline(fin, s[i].medicalProfile);

		getline(fin, check);
		s[i].numberOfPackages = stoi(check);
		k++;
	}
}

void show() {
	for (int i = 0; i < k; i++) {
		cout << "Struct number-" << i << endl << "--------------------------------" << endl;
		cout << "Name:" << s[i].name << endl;
		cout << "Location:" << s[i].location << endl;
		cout << "Medical Profile:" << s[i].medicalProfile << endl;
		cout << "Number of packages:" << s[i].numberOfPackages << endl;
		cout << "--------------------------------" << endl;
	}
}
void table() {
	cout << "| Medical Profile | Name |  Location |  NumberOfPackages |" << endl;
	cout << "|" << "  " << s[0].medicalProfile << "     " << s[0].name << "      " << s[0].location << "          " << s[0].numberOfPackages << "         |" << endl;
	cout << "|" << "  " << s[1].medicalProfile << "     " << s[1].name << "      " << s[1].location << "           " << s[1].numberOfPackages << "          |" << endl;
	cout << "|" << "--------------------------------------------------------" << "|" << endl;
	cout << "|" << "" << s[2].medicalProfile << "  " << s[2].name << "      " << s[2].location << "            " << s[2].numberOfPackages << "          |" << endl;
	cout << "|" << "" << s[3].medicalProfile << "  " << s[3].name << "      " << s[3].location << "          " << s[3].numberOfPackages << "          |" << endl;
	cout << "|" << "--------------------------------------------------------" << "|" << endl;
	cout << "|" << "  " << s[4].medicalProfile << "    " << s[4].name << "      " << s[4].location << "            " << s[4].numberOfPackages << "          |" << endl;
	cout << "|" << "  " << s[5].medicalProfile << "    " << s[5].name << "      " << s[5].location << "            " << s[5].numberOfPackages << "          |" << endl;
	cout << "|" << "--------------------------------------------------------" << "|" << endl;
}
void search() {
	string a;
	cout << "Inter medical profile";
	getline(cin, a);
	for (int i = 0; i < k; i++) {
		if (s[i].medicalProfile == a) {
			cout << s[i].name << endl << s[i].location << endl << s[i].numberOfPackages << endl << endl << endl;
		}
	}
}
bool comp1(sanat x, sanat y) {
	return x.medicalProfile > y.medicalProfile;
}
bool comp2(sanat x, sanat y) {
	return x.name < y.name;
}

int main()
{
	fileread();
	sort(s, s + k, comp1);
	sort(s, s + 2, comp2);
	sort(s + 2, s + 4, comp2);
	sort(s + 4, s + 6, comp2);
	table();
	search();

	/*Определить структуру для представления информации о наличии санаторных путевок, содержащую следующие поля :
	Назва - ние санатория, Место расположения, Лечебный профиль, Количество путевок.Представить введенные данные в виде таблицы,
		сгруппировав их по лечебным профилям санаториев.В пределах каждой группы данные отсортировать
		по названиям санато - риев.Организовать поиск информации и вывод результатов*/
}