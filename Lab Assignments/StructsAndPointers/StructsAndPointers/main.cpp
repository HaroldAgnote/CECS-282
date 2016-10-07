#include "myDate.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;


struct Student
{
	string name;
	int id;
	char grade;
	myDate birthday;
	string homeTown;
};

void initializeStudents(Student * student);
int randomID();
char randomGrade();
myDate randomDate();
void idSort(Student ** array);
void displayMenu();
void displayStudents(Student * student);

int main()
{
	srand(time(NULL));
	Student CECS282[10];
	Student * idPtrs[10];
	Student * agePtrs[10];
	Student * namePtrs[10];
	Student * gradePtrs[10];
	Student * homeTownPtrs[10];
	bool done = false;

	initializeStudents(CECS282);
	for (int i = 0; i < 10; i++)
	{
		idPtrs[i] = &CECS282[i];
	}
	idSort(idPtrs);
	

	do
	{
		displayMenu();
		int choice;
		cin >> choice;
		
		switch (choice)
		{
		case 1: displayStudents(CECS282);
			break; 
		case 2: displayStudents(*idPtrs);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7: done = true;
			break;
		default: cout << "Invalid Input\n";
			break;
		}
	}
	while (!done);


	system("pause");
	return 0;
}

void initializeStudents(Student * student)
{
	string defaultName = "Name";
	string defaultHome = "Home";

	for (int i = 0; i < 10; i++)
	{
		(*student).name = defaultName;
		(*student).id = randomID();
		(*student).grade = randomGrade();
		(*student).birthday = randomDate();
		(*student).homeTown = defaultHome;

		student = (student + 1);
	}
}

int randomID()
{
	return (1000 + (rand() % 8999));
}

char randomGrade()
{
	int randomNum = rand() % 5;
	char randomGrade;

	switch (randomNum)
	{
	case 0: randomGrade = 'A';
		break;
	case 1: randomGrade = 'B';
		break;
	case 2: randomGrade = 'C';
		break;
	case 3: randomGrade = 'D';
		break;
	case 4: randomGrade = 'F';
		break;
	}
	return randomGrade;
}

myDate randomDate()
{
	int rYear = 1994 + (rand() % 5);
	int rMonth = (rand() % 12) + 1;
	int rDay;

	if (rMonth == 1 || rMonth == 3 || rMonth == 5 || rMonth == 7 || rMonth == 8 || rMonth == 10 || rMonth == 12)
	{
		rDay = 1 + (rand() % 31);
	}
	else if (rMonth == 4 || rMonth == 6 || rMonth == 9 || rMonth == 11)
	{
		rDay = 1 + (rand() % 30);
	}
	else if (rMonth == 2)
	{
		if (rYear % 4 == 0)
		{
			rDay = 1 + (rand() % 29);
		}
		else
		{
			rDay = 1 + (rand() % 28);
		}
	}

	myDate randomDate(rMonth, rDay, rYear);

	return randomDate;
}

void idSort(Student ** array)
{
	bool swapped = false;

	do
	{
		swapped = false;
		for (int i = 0; i < 9; i++)
		{
			if ((*array[i]).id > (*array[i + 1]).id)
			{
				swap(array[i], array[i + 1]);
			}
		}
	}
	while (swapped);

	/*
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 9; j++)
		{
			if ((*array[j]).id > (*array[j + 1]).id)
			{
				swap(array[j], array[j + 1]);
			}
		}
	}*/
}

void swap(Student * ptr1, Student * ptr2)
{
	Student * swap = ptr1;
	ptr1 = ptr2;
	ptr2 = swap;
}


void displayMenu()
{
	cout << "What would you like to do?\n\n";
	cout << "1. Display Original List\n";
	cout << "2. Display List sorted by Student ID\n";
	cout << "3. Display List sorted by Student Age\n";
	cout << "4. Display List sorted by Name\n";
	cout << "5. Display List sorted by Grade\n";
	cout << "6. Display List sorted by Home Town\n\n";
	cout << "7. Exit\n\n";
}

void displayStudents(Student * student)
{
	for (int i = 0; i < 10; i++)
	{
		cout << (*student).name << " " << (*student).id << " " << (*student).grade << " " << (*student).homeTown << endl;
		(*student).birthday.display();
		cout << endl;
		student = (student + 1);
	}
}
