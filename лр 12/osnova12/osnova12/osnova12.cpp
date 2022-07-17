#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

// Добавить к проекту  функции смешанного и нисходящего обхода дерева с выводом  на консоль, проверки сбалансированности дерева и функцию в соответствии с вариантом из
// таблицы, представленной в лабораторной работе № 11,
// изменив ее так, чтобы функция соответствовала проекту данной лабораторной работы.

struct Tree
{
	int key;
	string str;
	struct Tree* left;
	struct Tree* right;
};
Tree* root = NULL;

Tree* CreateTree(Tree* root);
Tree* CreateEl(int k, string str);
Tree* AddEl(Tree* root);
Tree* DeleteEl(Tree* root, int key);
void PrintTree(Tree* root, int depth);
void PrintTree2(Tree* root, int depth);
void DeleteTree(Tree* root);
int chetn(Tree* root, int key);
int isBalanced(Tree* root);
int height(Tree* node);
int maxInt(int a, int b);
int main()
{
	setlocale(LC_ALL, "rus");
	int choice = 0;
	do
	{
		cout << "1 - добавление нового элемента\n";
		cout << "2 - удаление элемента\n";
		cout << "3 - вывод дерева в нисходящем порядке\n";
		cout << "4 - вывод дерева в смешанном порядке\n";
		cout << "5 - количество правых дочерних элементов\n";
		cout << "6 - проверка на сбалансированномть\n";
		cout << "7 - очистка дерева\n";
		cout << "0 - выход\n";
		cout << "\nНомер операции > "; cin >> choice;

		switch (choice)
		{

		case 1: {
			if (root == NULL)
				root = CreateTree(root);
			else AddEl(root);
			break;
		}

		case 2: {
			int key;
			cout << "Ключ > "; cin >> key;
			DeleteEl(root, key);
			break;
		}

		case 3: {
			PrintTree(root, 0);
			cout << endl << endl;
			break;
		}

		case 4: {
			PrintTree2(root, 0);
			cout << endl << endl;
			break;
		}

		case 6: {
			int r = isBalanced(root->right), l = isBalanced(root->left);
			if (isBalanced(root->right) == 1 || isBalanced(root->left) == 1)
				cout << "\nДерево  сбалансировано!\n";
			else
				cout << "\nДерево не сбалансировано!\n";
		}

		case 7: {
			DeleteTree(root);
			cout << endl << endl;
			root = NULL;
			break;
		}

		case 5: {
			cout << "Количество узлов с четными ключами > " << chetn(root, root->key) << endl;
			break;
		}

		case 0: {
			break;
		}
		}
	} while (choice != 0);

}

Tree* CreateTree(Tree* root)
{
	int key;
	string str;
	if (root == NULL)
	{
		cout << "Ключ корня > "; cin >> key;
		cout << "Строка корня > "; cin >> str;
		root = CreateEl(key, str);
		cout << "\nКорень дерева создан!\n\n";
	}
	return root;
}

Tree* CreateEl(int k, string str)
{
	Tree* interm = new Tree[sizeof(Tree)];
	interm->key = k;
	interm->str = str;
	interm->left = interm->right = NULL;
	return interm;
}

Tree* AddEl(Tree* root)
{
	int key; string str;
	cout << "Ключ элемента > "; cin >> key;
	if (key == root->key)
	{
		cout << "Ключ должнен быть уникальным, измените значение!\n";
		cout << "Ключ элемента > "; cin >> key;
	}
	cout << "Строка элемента > "; cin >> str; cout << endl << "Элемент добавлен!\n";
	Tree* prev = root; // из-за ошибки "Потенциально неинициализируемая переменная"
	while (root)
	{
		prev = root;
		if (key < root->key)
			root = root->left;
		else root = root->right;
	}
	root = CreateEl(key, str);
	if (key < prev->key)
		prev->left = root;
	else
		prev->right = root;
	return root;
}

Tree* DeleteEl(Tree* root, int key)
{
	Tree* d, * prevd, * r, * prevr;
	d = root; prevd = NULL;
	while (d != NULL && d->key != key)
	{
		prevd = d;
		if (d->key > key)
			d = d->left;
		else
			d = d->right;
	}

	if (d == NULL)
	{
		cout << "Элемент не найден!";
		return root;
	}

	if (d->right == NULL)
		r = d->left;
	else if (d->left == NULL)
		r = d->right;
	else {
		prevr = d;
		r = d->left;
		while (r->right != NULL)
		{
			prevr = r;
			r = r->right;
		}

		if (prevr == d)
			r->right = d->right;
		else {
			r->right = d->right;
			prevr->right = r->left;
			r->left = prevr;
		}
	}

	if (d == root)
		root = r;
	else {
		if (d->key < prevd->key)
			prevd->left = r;
		else
			prevd->right = r;
	}

	int Dkey = d->key;
	cout << "Удален элемент с ключом " << Dkey << "\n";
	d = NULL;
	return root;
}
int how = 0;
void PrintTree(Tree* root, int depth)
{
	if (root)
	{
		// смешанный обход - слева направ0
		PrintTree(root->right, depth);
		how++;
		cout << root->key << ' ';
		how++;
		PrintTree(root->left, depth);
		how++;
	}
}

void PrintTree2(Tree* root, int depth)
{
	if (root)
	{
		// нисходящий обход - сверху вниз
		PrintTree2(root->left, depth);
		PrintTree2(root->right, depth);
		cout << root->key << ' ';
	}
}

void DeleteTree(Tree* root)
{
	if (root != NULL)
	{
		DeleteTree(root->left);
		DeleteTree(root->right);
		root = NULL;
	}
}

//количество узлов с четными ключами
int depth = 0;
int sum = 0;

int chetn(Tree* root, int key)
{
	if (root->right != NULL)
	{
		chetn(root->right, key);
		sum++;
	}
	
	return sum;
}

int maxInt(int a, int b)
{
	return (a >= b) ? a : b;
}

int height(Tree* node)
{
	if (node == NULL)
		return 0;

	return 1 + maxInt(height(node->left), height(node->right));
}

int isBalanced(Tree* root)
{
	int lh;
	int rh;

	if (root == NULL)
		return 1;

	lh = height(root->left);
	rh = height(root->right);

	if (abs(lh - rh) == 0 && isBalanced(root->left) && isBalanced(root->right))
		return 1;

	return 0;
}