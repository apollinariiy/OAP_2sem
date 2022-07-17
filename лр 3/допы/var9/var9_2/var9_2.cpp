#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;
/* 2. Ввести с клавиатуры строку символов, состоящую из слов,
разделенных пробелами, и записать ее в файл. Прочитать из файла данные
и вывести на экран порядковый номер слова минимальной длины. Посчитать
количество символов в слове. */

string fileOut(string* pStrOut)
{
	ofstream file1("file9_2_1.txt");
	file1 << *pStrOut;
	file1.close();
	return *pStrOut;
}

string fileIn(string* pStrIn)
{
	string StrIn, min = "0000000";
	short counter = 1, SequenceNum;
	ifstream file2("file9_2_1.txt");
	while (file2)
	{
		file2 >> StrIn;
		if (StrIn.length() < min.length())
		{
			min = StrIn;
			SequenceNum = counter;
		}
		counter++;
	}
	cout << "Порядковый номер самого короткого слова: " << SequenceNum << '\n';
	file2.close();
	return StrIn;
}

int main()
{
	setlocale(LC_ALL, "ru");
	string strOut, strIn;
	string* pStrOut = &strOut, * pStrIn = &strIn;
	cout << "Введите группы цифр, разделенные пробелом:\n";
	getline(cin, strOut);
	fileOut(pStrOut);
	fileIn(pStrIn);
}