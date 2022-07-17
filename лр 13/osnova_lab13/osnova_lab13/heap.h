#pragma once 
using namespace std;

struct AAA // просто структура 
{
	int x; // интовое значение икс 
	void print(); // вывод этого значения 
	int getPriority() const; //интовое значение приоритета 
};

namespace heap
{
	enum CMP // перечисление 
	{
		LESS = -1, EQUAL = 0, GREAT = 1 // ... 
	};

	struct Heap //структура хип 
	{
		int size; //инт 
		int maxSize; //инт 
		void** storage; // данные 

		CMP(*compare)(void*, void*); //функция сравнения (в мейне), которая берет два указателя на войд 

		Heap(int maxsize, CMP(*f)(void*, void*)) // структруа, в которую мы передаем макссайз, и какое то значение из функции сравнения 
		{
			size = 0; // инт 
			storage = new void* [maxSize = maxsize]; //двумерный динамический массив 
			compare = f; // значение функции сравнения 
		};

		Heap(int maxsize, CMP(*f)(void*, void*), void* x[]) // вторая куча, только тут уже есть массив 
		{
			size = 0;
			storage = x; // и вот мыприсваиваем этот массив 
			maxSize = maxsize; // размеры берем из макссайз 
			compare = f; // значение функции сравнения 
		};

		int left(int ix); //левый дочерний 
		int right(int ix); // правый дочерний 
		int parent(int ix); // родитель 

		bool isFull() const //булевая переменная конст 
		{
			return (size >= maxSize); // возвращает тру или фолс 
		};

		bool isEmpty() const // булевая переменная конст 
		{
			return (size <= 0); // возвращает тру или фолс 
		};

		bool isLess(void* x1, void* x2) const //булевая переменная конст, принимающая два значения указателя 
		{
			return compare(x1, x2) == LESS; // вызывает функцию сравнения и сравнивает с лесс, возвращает тру или фолс 
		};

		bool isGreat(void* x1, void* x2) const //булевая переменная конст, принимающая два значения указателя 
		{
			return compare(x1, x2) == GREAT; // вызывает функцию сравнения и сравнивает с грейт, возвращает тру или фолс 
		};

		bool isEqual(void* x1, void* x2) const //булевая переменная конст, принимающая два значения указателя 
		{
			return compare(x1, x2) == EQUAL; // вызывает функцию сравнения и сравнивает с икуал, возвращает тру или фолс 
		};

		void swap(int i, int j);
		void heapify(int ix);
		void insert(void* x);
		void* extractMax();
		void scan(int i) const;
		void deleteHeap();
		void swapParent(int ix);
		void* extractI(int ix); //Удаление i-го эл-та
		void* extractMin(); //Удаление минимального
		int findMin();
		int kratn();
		int NumOfEven(heap::Heap& h);
		int NumOfOdd(heap::Heap& h);
		int Sum(heap::Heap& h);
	};

	Heap create(int maxsize, CMP(*f)(void*, void*)); //из зипа создает структуру 
};