#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct Queue
{
	char size;
	Queue* next;
};

struct qmanager {
	Queue* head;
	Queue* tail;
};

bool empty(qmanager*);
void insertToQueue(qmanager*);
void showQueue(qmanager*);
void deletion(qmanager*);
void task(qmanager*);