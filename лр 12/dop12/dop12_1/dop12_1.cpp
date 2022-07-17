 //Дано N чисел, N > 0. Создать дерево из N вершин, в котором каждая левая дочерняя вершина является листом, а правая дочерняя вершина является внутренней.
// Для каждой внутренней вершины вначале создавать левую дочернюю вершину, а затем правую(если она существует); 
 //каждой создаваемой вершине присваивать очередное значение из исходного набора.


#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
struct El
{
	int data;
	El* left;
	El* right;
};

 El* root = NULL;

 El* CreateEl(int data)
{
	El* interm = new El[sizeof(El)];
	interm->data = data;
	interm->left = interm->right = NULL;
	return interm;
}

void printT(El* p, int level)
{
	if (p)
	{
		printT(p->left, level + 1);
		for (int i = 0; i < level; i++) 
			cout << "   ";
		cout << p->data << endl;
		printT(p->right, level + 1);
	}
}

El* f(El* rt, int n, int count)
{
	static int loop = 0, data = 0;
	loop++; data++;

	if (loop<= n)
	{
		if (root == NULL && count == 0)
		{
			root = CreateEl(data);
			++count;
			f(root, n, count);
			return root;
		}
		else if (count == 1)
		{
			rt->left = CreateEl(data);
			++count;
			f(rt, n, count);
		}
		else if (count == 2)
		{
			--count;
			rt->right = CreateEl(data);
			f(rt->right, n, count);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0;
	cout << "Введите число N (количество вершин) > "; cin >> n;
	root = f(root, n, 0);
	printT(root, 0);
}
