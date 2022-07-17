﻿ /*Составить хеш-таблицу, содержащую буквы и количество их вхождений во введенной строке. Вывести таблицу на экран. Осуществить поиск введенной 
 буквы в хеш-таблице.*/

#include <iostream>
#include <fstream>
using namespace std;

typedef char T;  // тип элементов
typedef int hashTableIndex; // индекс в хеш-таблице
#define compEQ(a,b) (a == b)
typedef struct Node_ {
    T data;// данные, хранящиеся в вершине
    struct Node_* next; // следующая вершина
} Node;

Node** hashTable;
int hashTableSize;
hashTableIndex myhash(T data);
Node* insertNode(T data);
void deleteNode(T data);
Node* findNode(T data);

int main() {
    setlocale(LC_CTYPE, "Russian");
    int i, maxnum=0;
    char* a=0;
   // char a[20];
    int choice=10;
    for (;;)
    {
        cout << "1.Создание хеш-таблицы" << endl;
        cout << "2.Вывод хеш-таблицы" << endl;
        cout << "3.Поиск информации по ключу" << endl;
        cout << "4.Поиск информации по букве" << endl;
        cout << "5.Удаление хеш-таблицы" << endl;
        cout << "0.Выход" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            cout << "Введите количество элементов: "; cin >> maxnum;
            cout << "Введите размер хеш-таблицы: ";
            cin >> hashTableSize;
            a = new char[maxnum];
            hashTable = new Node * [hashTableSize];
            for (i = 0; i < hashTableSize; i++)
                hashTable[i] = NULL;
            for (i = 0; i < maxnum; i++)
            {
                a[i] = 'a'+rand() % 26;
                a[maxnum] = '\0';
            }
            for (i = 0; i < maxnum; i++) {
                insertNode(a[i]);
            }
        }
        break;
        case 2:
        {
            int how = 0, other=0;
            cout << "Рандомно сгенерированные элементы, которые берутся за основу: " << endl;
            for (i = 0; i < maxnum; i++) {
                cout << a[i];
                for (int j = maxnum; j > 0; j--) {
                    if (a[j] == a[i]) {
                        how++;
                    }
                }
                if (i < maxnum - 1) cout;
                cout << " - " << how << endl;
                how = 0;
            }
            
            cout << endl;
            cout << "Хеш-таблица: " << endl;
            for (i = 0; i < hashTableSize; i++) {
                cout << i << "  :  ";
                Node* Temp = hashTable[i];
                while (Temp) {
                    cout << Temp->data << " -> ";
                    Temp = Temp->next;
                }
                cout << endl;
            }
        }
        break;
        case 3:
        {
            int sear = 0;
            cout << "Введите номер элемента хеш-таблица (см.массив): "; cin >> sear;
            cout << endl;
            // поиск элементов массива по хеш-таблице
            for (i = 0; i < maxnum; i++) {
                if (i == sear)
                {
                    cout << "Найденный элемент:" << a[i-1] << endl;
               }
            }
            break;
        }
        case 4: {
            char sear[5];
            cout << "Введите букву: "; cin >> sear[0];
            cout << endl;
            // поиск элементов массива по хеш-таблице
            for (i = 0; i < maxnum; i++) {
                if (a[i] == sear[0])
                {
                    cout << "Найденный элемент находится по ключом:" << i + 1 << endl;
                }
            }
            break;
        }
        case 5:
        {
            // очистка хеш-таблицы
            for (i = maxnum - 1; i >= 0; i--) {
                deleteNode(a[i]);
            }
        }
        case 0:
        {
            exit(0);
        }}
    }
    return 0;
}


// хеш-функция размещения вершины
//алгоритм на основе исключающего ИЛИ для поля строки данных
hashTableIndex myhash(T data) {
    return fmod(data^13,hashTableSize);
    //return (data % hashTableSize); то, что было изначально
}


// функция поиска местоположения и вставки вершины в таблицу
Node* insertNode(T data) {
    Node* p, * p0;
    hashTableIndex bucket;
    // вставка вершины в начало списка
    bucket = myhash(data);
    if ((p = new Node) == 0) {
        fprintf(stderr, "Нехватка памяти (insertNode)\n");
        exit(1);
    }
    p0 = hashTable[bucket];
    hashTable[bucket] = p;
    p->next = p0;
    p->data = data;
    return p;
}

//функция удаления вершины из таблицы
void deleteNode(T data) {
    Node* p0, * p;
    hashTableIndex bucket;
    p0 = 0;
    bucket = myhash(data);
    p = hashTable[bucket];
    while (p && !compEQ(p->data, data)) {
        p0 = p;
        p = p->next;
    }
    if (!p) return;
    if (p0)
        p0->next = p->next;
    else
        hashTable[bucket] = p->next;
    free(p);
}

// функция поиска вершины со значением data
Node* findNode(T data) {
    Node* p;
    p = hashTable[myhash(data)];
    while (p && !compEQ(p->data, data))
    p = p->next;
    cout << p << endl;
    return p;
}

