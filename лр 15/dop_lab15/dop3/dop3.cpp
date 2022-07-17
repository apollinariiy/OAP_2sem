// Построить хеш - таблицу из слов произвольного текстового файла, задав ее размерность с экрана.Вывести построенную таблицу
//слов на экран.Осуществить поиск введенного слова.Выполнить программу для различных размерностей таблицы и сравните количество 
//сравнений.Удалить все слова, начинающиеся на указанную букву, выведите таблицу.

#include <iostream>
#include <fstream>

using namespace std;
typedef char T; // тип элементов
typedef int hashTableIndex; // индекс в хеш-таблице
#define compEQ(a, b) (a == b)

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
    setlocale(LC_CTYPE, "RU");
    int i, maxnum = 0;
    char* a = 0;
    int choice = 10;
    for (;;)
    {
        cout << "1.Генерация рандомных чисел и запись их в файл" << endl;
        cout << "2.Создание хеш-таблицы на основе данных из файла" << endl;
        cout << "3.Поиск информации" << endl;
        cout << "4.Удаление всех слов, начинающихся на указанную букву" << endl;
        cout << "0.Выход" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            cout << "Введите количество элементов maxnum : ";
            cin >> maxnum;
            cout << "Введите размер хеш-таблицы HashTableSize : ";
            cin >> hashTableSize;
            a = new char[maxnum];
            hashTable = new Node * [hashTableSize];
            for (i = 0; i < hashTableSize; i++)
                hashTable[i] = NULL;
            // генерация массива
            for (i = 0; i < maxnum; i++)
            {
                a[i] = 'a' + rand() % 26;
                a[maxnum] = '\0';
            }
            // заполнение хеш-таблицы элементами массив
            for (i = 0; i < maxnum; i++) {
                insertNode(a[i]);
            }
            // вывод элементов массива в файл List. txt
            ofstream out("List.txt");
            for (i = 0; i < maxnum; i++) {
                out << a[i];
                if (i < maxnum - 1) out << "\t";
            }

            out.close();
            // сохранение хеш-таблицы в файл HashTable. txt
            out.open("HashTable.txt");
            for (i = 0; i < hashTableSize; i++) {
                out << i;
                Node* Temp = hashTable[i];
                while (Temp) {
                    out << Temp->data;
                    Temp = Temp->next;
                }
            }
            out.close();
        }
        break;
        case 2:
        {
            // вывод элементов массива в файл List. txt
            ofstream out("List.txt");
            for (i = 0; i < maxnum; i++) {
                cout << a[i];
                if (i < maxnum - 1) cout << "\t";
            }
            out.close();
            cout << endl;
            // сохранение хеш-таблицы в файл HashTable. txt
            out.open("HashTable.txt");
            for (i = 0; i < hashTableSize; i++) {
                cout << i << " : ";
                Node* Temp = hashTable[i];
                while (Temp) {
                    cout << Temp->data << " -> ";
                    Temp = Temp->next;
                }
                cout << endl;
            }out.close();
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
                    cout << "Найденный элемент:" << a[i - 1] << endl;
                }
            }
            break;
        }
        case 4:
        {
            char what;
            cout << "Введите 1ую букву слова, которое хотите удалить." << endl;
            cout << "Если слово состоит из 1 буквы - оно удаляется полностью: "; cin >> what;
            char* b;
            b = new char[maxnum];
            hashTable = new Node * [hashTableSize];
            for (i = 0; i < hashTableSize; i++)
                hashTable[i] = NULL;
            // генерация массива
            for (i = 0; i < maxnum; i++)
            {
                if (a[i] != what) {
                    b[i] = a[i];
                }
            }
            // заполнение хеш-таблицы элементами массив
            for (i = 0; i < maxnum; i++) {
                insertNode(b[i]);
            }
            // вывод элементов массива в файл List. txt
            ofstream out("List.txt");
            for (i = 0; i < maxnum; i++) {
                out << b[i];
                if (i < maxnum - 1) out << "\t";
            }

            out.close();
            // сохранение хеш-таблицы в файл HashTable. txt
            out.open("HashTable.txt");
            for (i = 0; i < hashTableSize; i++) {
                out << i;
                Node* Temp = hashTable[i];
                while (Temp) {
                    out << Temp->data;
                    Temp = Temp->next;
                }
            }
            out.close();

            cout << "Слово удалено." << endl;
        }
        break;
        case 0:
        {
            exit(0);
        }
        }
    }
    return 0;


    // поиск элементов массива по хеш-таблице
    for (i = maxnum - 1; i >= 0; i--) {
        findNode(a[i]);
    }


    // очистка хеш-таблицы
    for (i = maxnum - 1; i >= 0; i--) {
        deleteNode(a[i]);
    }

    system("pause");
    return 0;
}

// хеш-функция размещения вершины
hashTableIndex myhash(T data) {
    return (data % hashTableSize);
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

// функция удаления вершины из таблицы

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
    return p;
}