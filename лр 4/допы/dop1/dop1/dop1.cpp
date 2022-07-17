// laba4dop2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct train {
	string pointOfDestination;
	int trainNumber;
	int departureTime;
};

train a[8];
int k = 0;

void fileread() {
	ifstream fin("input.txt");

	int count;
	string check;
	getline(fin, check);
	count = stoi(check);
	for (int i = 0; i < count; i++) {
		getline(fin, a[k].pointOfDestination);
		getline(fin, check);
		a[k].trainNumber = stoi(check);
		getline(fin, check);
		a[k].departureTime = stoi(check);
		k++;
	}
}
void show() {
	string tmp;
	for (int i = 0; i < k; i++) {
		cout << "--------------------------------" << endl;
		cout << "Point of destination:" << a[i].pointOfDestination << endl;
		cout << "Train number:" << a[i].trainNumber << endl;
		tmp = to_string(a[i].departureTime);
		if (tmp.size() == 4)
			cout << "Departure time-> " << tmp[0] << tmp[1] << ":" << tmp[2] << tmp[3] << endl;
		else
			cout << "Departure time-> " << tmp[0] << ":" << tmp[1] << tmp[2] << endl;
	}
}
void timesearch(int time) {
	int b = true;
	string tmp;
	for (int i = 0; i < k; i++) {
		if (a[i].departureTime > time) {
			b = false;
			cout << "--------------------------------" << endl;
			cout << "Point of destination:" << a[i].pointOfDestination << endl;
			cout << "Train number:" << a[i].trainNumber << endl;
			tmp = to_string(a[i].departureTime);
			if (tmp.size() == 4)
				cout << "Departure time-> " << tmp[0] << tmp[1] << ":" << tmp[2] << tmp[3] << endl;
			else
				cout << "Departure time-> " << tmp[0] << ":" << tmp[1] << tmp[2] << endl;
		}
	}
	if (b)
		cout << "No trains after this time";
}
bool comp(train a, train b) {
	return a.pointOfDestination < b.pointOfDestination;
}

int main()
{
	fileread();
	show();
	sort(a, a + 8, comp);
	cout << endl << endl << endl;
	show();
	int time;
	cin >> time;
	system("CLS");
	timesearch(time);
}