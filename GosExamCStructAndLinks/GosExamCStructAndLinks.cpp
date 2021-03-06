// GosExamCStructAndLinks.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h> // библиотека, необходимая для работы оператора getch();
#include <iterator> // заголовок итераторов
#include <list>     // подключаем заголовок списка

using namespace std;

struct StudentList
{
	int id;
	string name;
	int age;
	string group;
	StudentList *next;
};

StudentList *start = NULL;

void addList(int id , string name, int age, string group)
{
	if (start == NULL)
	{
		start = new StudentList(); // нужно создать элемент. Иначе ошибка.
		start->id = id;
		start->name = name;
		start->age = age;
		start->group = group;
		start->next = NULL;
	}
	else
	{
		StudentList *field = start;
		while (field->next != NULL)
		{
			field = field->next;
		};
		field->next = new StudentList();
		field = field->next;
		field->id = id;
		field->name = name;
		field->age = age;
		field->group = group;
		field->next = NULL;
	}
}

StudentList* getAt(int id) {
	StudentList *field = start;
	if (field->id == id) {
		return field;
	}
	else {
		while (field->id != id) {
			field = field->next;
		}
		return field;
	}
}

int main()
{
	addList(1, "masha", 12, "pibd");
	addList(2, "petia", 12, "pibd");
	addList(3, "vasia", 22, "pibd");
	addList(4, "pasha", 12, "pibd");
	StudentList* stud = getAt(3);
	cout << stud->id << "\n";
	cout << stud->name << "\n";
	cout << stud->age << "\n";
	
	list<int> myList; // объявляем пустой список
	for (int i = 0; i < 15; i++) {
		myList.push_back(rand() % 20); // добавляем в список новые элементы
	}
	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));

	_getch();
	return 0;
}
