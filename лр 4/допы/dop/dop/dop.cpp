// 4labadop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct exams {
	string fio;
	int numberOfExams;
	pair <string, int> ExamsAndMarks[100];
};
exams ex[100];
int k = 0;
void fileread() {
	ifstream fin("input.txt");

	int count;
	string check;
	getline(fin, check);
	count = stoi(check);
	for (int i = 0; i < count; i++) {
		getline(fin, ex[k].fio);
		getline(fin, check);
		ex[k].numberOfExams = stoi(check);
		for (int i = 0; i < ex[k].numberOfExams; i++) {
			getline(fin, ex[k].ExamsAndMarks[i].first);
			getline(fin, check);
			ex[k].ExamsAndMarks[i].second = stoi(check);
		}
		k++;
	}
}
void show() {
	for (int i = 0; i < k; i++) {
		cout << "Struct number-" << i << endl << "--------------------------------" << endl;
		cout << "FIO:" << ex[i].fio << endl;
		cout << "Number of exams:" << ex[i].numberOfExams << endl;
		cout << "Exams and marks:" << endl << "===============" << endl;
		for (int j = 0; j < ex[i].numberOfExams; j++) {
			cout << "Exam:" << ex[i].ExamsAndMarks[j].first << " " << "Mark:" << ex[i].ExamsAndMarks[j].second << endl;
		}
		cout << "===============" << endl;
	}
}
bool check(int n) {
	cout << ex[n].fio;
	for (int j = 0; j < ex[n].numberOfExams; j++)
		if (ex[n].ExamsAndMarks[j].second < 4 || ex[n].ExamsAndMarks[j].second > 5)
			return false;

	return true;
}
int statistics() {
	int count = 0;
	bool a = true;
	for (int i = 0; i < k; i++) {
		a = true;
		for (int j = 0; j < ex[i].numberOfExams; j++)
			if (ex[i].ExamsAndMarks[j].second < 4 || ex[i].ExamsAndMarks[j].second > 5)
				a = false;
		if (a)
			count++;
	}

	return count * 100 / k;
}
int main()
{
	fileread();
	show();
	int n;
	cin >> n;
	if (check(n))
		cout << "All marks are 4 or 5\n";
	else
		cout << "Not all marks are 4 or 5\n";
	cout << statistics();
	//1. Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля : ФИО студента,
	//    число экзаменов, полученные оценки.Определить функции для обработки отдельного объекта(например, для проверки,
	//      сданы ли все экзамены на 4 и 5).Написать функцию для обработки массива структур.В результате обработки требуется
	//    вычислить характеристику успеваемости студентов, то есть отношение числа студентов,
	//    сдавших экзамены на 4 и 5, к общему числу студентов, в процентах.
}