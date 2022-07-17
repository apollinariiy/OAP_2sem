#include "heap.h" 
#include <iostream> 
#include <iomanip> 
namespace heap
{

	int Heap::left(int ix) // ëåâûé äî÷åðíèé ýëåìåíò 
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);

	}

	int Heap::right(int ix) // ïðàâûé äî÷åðíèé ýëåìåíò 
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);

	}

	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty()) // åñëè íå ïóñòàÿ 
		{
			rc = storage[0]; // òî ðê ðàâíî ïåðâîìó ýëåìåíòó ìàññèâà 
			storage[0] = storage[size - 1]; // óäàëÿåì åãî 
			size--; // óìåíüøàåì ñàéç íà 1 
			heapify(0); //áàëàíñèðóåì äåðåâî ñ íóëÿ 
		} return rc; // âîçâðàùàåì ðê 
	}

	int Heap::parent(int ix) //ðîäèòåëüñêèé ýëåìåíò 
	{
		return (ix + 1) / 2 - 1; //ðîäèòåëüñêèé ýëåìåíò 
	}

	void Heap::swap(int i, int j) //ôóíêöè ñâàï, êîòîðàÿ ïðèíèìàåò äâà èíòîâûõ çíà÷åíèÿ 
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf; // ìåíÿåò èõ ìåñòàìè 
	}

	void Heap::heapify(int ix) // áàëàíñèðîâêà êó÷è 
	{
		int l = left(ix); // ëåâ ïåðåäàåòñÿ â ôóíêöèþ 
		int r = right(ix); //ïðàâ ïåðåäàåòñÿ â ôóíêöèþ 
		int irl = ix; // íàäî äàëüøå 
		if (l > 0) // åñëè ëåâàÿ áîëüøå íóëÿ 
		{
			if (isGreat(storage[l], storage[ix])) // åñëè ëåâàÿ áîëüøå 
				irl = l; // ïðèñâàèâàåì äîïó ëåâîå 
			if (r > 0 && isGreat(storage[r], storage[irl])) // åñëè ïðàâàÿ áîëüøå è áîëüøå èíäåêñà, òî 
				irl = r; // ïðèñâàèâàåì ïðàâîå 
			if (irl != ix) // åñëè íå ñîøëîñü ( òî åñòü ìû ÷òî òî ïîìåíÿëè è êó÷à íåïðàâèëüíàÿ) 
			{
				swap(ix, irl); //ñâàïàåì ìåñòàìè 
				heapify(irl); // ïîâòîðÿåì ïðîöåäóðó, ïîêà íå ñòàíåò íîðì 
			}
		}
	}

	void Heap::deleteHeap() // óäàëÿåì êó÷ó 
	{
		if (!isEmpty()) // åñëè íå ïóñòàÿ 
		{
			size = 0; // ñàéç íîëü 
			this->~Heap();
		}
	}

	Heap create(int maxsize, CMP(*f)(void*, void*)) //ôóíêèöÿ ñîçäàíèÿ êó÷è 
	{
		return *(new Heap(maxsize, f)); // âîçâðàùàåò êó÷ó ïî àäðåñó 
	}

	void Heap::scan(int i) const     //Âûâîä çíà÷åíèé ýëåìåíòîâ íà ýêðàí
	{
		int probel = 20;
		int z = 3;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Êó÷à ïóñòà";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
				{

					y = y + z;
					z++;
				}

			}
			probel /= 2;
		}
		std::cout << '\n';
	}

	int Heap::findMin()
	{
		int min = 0;
		for (int i = 1; i < size; i++)
		{
			if (((AAA*)storage[i])->getPriority() < ((AAA*)storage[min])->getPriority())
				min = i;
		}
		return min;
	}



	void* Heap::extractI(int ix)
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[ix]; // ðê ðàâíî ïåðâîìó ýëåìåíòó ìàññèâà 
			storage[ix] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}

	void* Heap::extractMin() // óäàëÿåò ìèíèìàëüíûé 
	{
		int min = findMin();
		return extractI(min);
	}

	void Heap::insert(void* x) // ôóíêöèÿ âñòàâêè 
	{
		int i; // èíò õ 
		if (!isFull()) // åñëè íå ïîëíîå 
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i])) // ïîêà è áîëüøå íóëÿ è ðîäèòåëüñêèé ýëåìåíò ìåíüøå òåêóùåãî 
			{
				swap(parent(i), i); // ñâàïàåì ðîäèòåëüñêèé ýëåìåíò 
				i = parent(i); // è ïðèñâàèâàåì ðîäèòåëüñêèé ýëåìåíò 
			}
		}
	}
}

void AAA::print() // âûâîäèò âñå äàííûå 
{
	std::cout << x;
}

int AAA::getPriority() const
{
	return x;
}