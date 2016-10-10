/*
* Name: Harold Agnote
* Student ID: 012264497
* Class: CECS 282 - Sec. 07
* Project Name: (Program 3 - Structures and Pointers)
* Due Date: (October 10, 2016)
*/
#include "myDate.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <ctime>

using namespace std;


struct Student
{
	char name[20];
	int id;
	char grade;
	myDate birthday;
	string homeTown;
};

void initializeStudents(Student * student, int size);
void checkID(Student * student, int size);
char* randomName();
int randomID();
char randomGrade();
myDate randomDate();
string randomHome();
void idSort(Student ** array, int size);
void ageSort(Student ** array, int size);
void nameSort(Student ** array, int size);
void gradeSort(Student ** array, int size);
void homeSort(Student ** array, int size);
void swap(Student ** pointer1, Student ** pointer2);
void displayHeader();
void displayMenu();
void displayStudents(Student * student, int size);
void displayPointers(Student ** student, int size);

int main()
{
	srand(time(NULL));
	Student CECS282[10];
	Student * idPtrs[10];
	Student * agePtrs[10];
	Student * namePtrs[10];
	Student * gradePtrs[10];
	Student * homePtrs[10];
	bool done = false;

	initializeStudents(CECS282, sizeof(CECS282)/sizeof(CECS282[0]));
	checkID(CECS282, sizeof(CECS282) / sizeof(CECS282[0]));
	for (int i = 0; i < 10; i++)
	{
		idPtrs[i] = &CECS282[i];
		agePtrs[i] = &CECS282[i];
		namePtrs[i] = &CECS282[i];
		gradePtrs[i] = &CECS282[i];
		homePtrs[i] = &CECS282[i];
	}

	idSort(idPtrs, sizeof(idPtrs)/sizeof(idPtrs[0]));
	ageSort(agePtrs, sizeof(agePtrs)/sizeof(agePtrs[0]));
	nameSort(namePtrs, sizeof(namePtrs) / sizeof(namePtrs[0]));
	gradeSort(gradePtrs, sizeof(gradePtrs) / sizeof(gradePtrs[0]));
	homeSort(homePtrs, sizeof(homePtrs) / sizeof(homePtrs[0]));

	do
	{
		displayMenu();
		int choice;
		cin >> choice;
		
		if (choice > 0 && choice < 7)
		{
			displayHeader();
		}

		switch (choice)
		{
		case 1: displayStudents(CECS282, sizeof(CECS282) / sizeof(CECS282[0]));
			break; 
		case 2: displayPointers(idPtrs, sizeof(idPtrs) / sizeof(idPtrs[0]));
			break;
		case 3: displayPointers(agePtrs, sizeof(agePtrs) / sizeof(agePtrs[0]));
			break;
		case 4: displayPointers(namePtrs, sizeof(namePtrs) / sizeof(namePtrs[0]));
			break;
		case 5: displayPointers(gradePtrs, sizeof(gradePtrs) / sizeof(gradePtrs[0]));
			break;
		case 6: displayPointers(homePtrs, sizeof(homePtrs) / sizeof(homePtrs[0]));
			break;
		case 7: done = true;
			break;
		default: cout << "Invalid Input\n";
			break;
		}
	}
	while (!done);

	return 0;
}

void initializeStudents(Student * student, int size)
{
	for (int i = 0; i < size; i++)
	{
		strcpy_s((*student).name, randomName());
		(*student).id = randomID();
		(*student).grade = randomGrade();
		(*student).birthday = randomDate();
		(*student).homeTown = randomHome();

		student = (student + 1);
	}
}

void checkID(Student * student, int size)
{
	for (int i = 0; i < size; i++)
	{
		Student * innerPointer = (student + 1);
		for (int j = 0; j < size - 1; j++)
		{
			if ((*student).id == ((innerPointer)->id))
			{
				(*student).id = randomID();
			}
			innerPointer = (innerPointer + 1);
		}
		student = (student + 1);
	}
}

char* randomName()
{
	char* randomName;
	int randomNumber = 1 + (rand() % 20);
	
	switch (randomNumber)
	{
	case 1: randomName = "Jim";
		break;
	case 2: randomName = "Bruce";
		break;
	case 3: randomName = "Clark";
		break;
	case 4: randomName = "Natasha";
		break;
	case 5: randomName = "Connie";
		break;
	case 6: randomName = "Steven";
		break;
	case 7: randomName = "Tony";
		break;
	case 8: randomName = "Spongebob";
		break;
	case 9: randomName = "Tom";
		break;
	case 10: randomName = "Fred";
		break;
	case 11: randomName = "Peter";
		break;
	case 12: randomName = "Oprah";
		break;
	case 13: randomName = "Emma";
		break;
	case 14: randomName = "Tom";
		break;
	case 15: randomName = "Carrie";
		break;
	case 16: randomName = "Kiera";
		break;
	case 17: randomName = "Sandy";
		break;
	case 18: randomName = "Lena";
		break;
	case 19: randomName = "Hana";
		break;
	case 20: randomName = "Angela";
		break;
	default: randomName = "Steven Gold";
		break;
	}
	return randomName;
}

int randomID()
{
	return (1000 + (rand() % 9000));
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

string randomHome()
{
	string home;
	int randomNumber = 1 + (rand() % 10);

	switch (randomNumber)
	{
	case 1: home = "Pomona";
		break;
	case 2: home = "Los Angeles";
		break;
	case 3: home = "San Francisco";
		break;
	case 4: home = "Bellflower";
		break;
	case 5: home = "Las Vegas";
		break;
	case 6: home = "Chino";
		break;
	case 7: home = "Cerritos";
		break;
	case 8: home = "Long Beach";
		break;
	case 9: home = "San Diego";
		break;
	case 10: home = "Norwalk";
		break;
	default: home = "Lakewood";
		break;

	}
	return home;
}

void idSort(Student ** array, int size)
{
	bool swapped = false;

	do
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (((*array[i]).id) > ((*array[i+1]).id))
			{
				swap(array[i], array[i + 1]);
				swapped = true;
			}
		}
	}
	while (swapped);
}

void ageSort(Student ** array, int size)
{
	bool swapped = false;

	do
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if ((*array[i]).birthday.daysBetween((*array[i + 1]).birthday) < 0)
			{
				swap(array[i], array[i + 1]);
				swapped = true;
			}
		}
	}
	while (swapped);
}

void nameSort(Student ** array, int size)
{
	bool swapped = false;

	do
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (strcmp((*array[i]).name, (*array[i + 1]).name) > 0)
			{
				swap(array[i], array[i + 1]);
				swapped = true;
			}
		}
	}
	while (swapped);
}

void gradeSort(Student ** array, int size)
{
	bool swapped = false;

	do
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (((*array[i]).grade) > ((*array[i + 1]).grade))
			{
				swap(array[i], array[i + 1]);
				swapped = true;
			}
		}
	}
	while (swapped);
}

void homeSort(Student ** array, int size)
{
	bool swapped = false;

	do
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (((*array[i]).homeTown).compare((*array[i + 1]).homeTown) > 0)
			{
				swap(array[i], array[i + 1]);
				swapped = true;
			}
		}
	}
	while (swapped);
}

void swap(Student ** pointer1, Student ** pointer2)
{
	Student * swap = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = swap;
}

void displayMenu()
{
	cout << "What would you like to do?\n\n";
	cout << "1. Display Original List\n";
	cout << "2. Display List sorted by Student ID\n";
	cout << "3. Display List sorted by Student Age\n";
	cout << "4. Display List sorted by Name\n";
	cout << "5. Display List sorted by Grade\n";
	cout << "6. Display List sorted by Hometown\n\n";
	cout << "7. Exit\n\n";
}

void displayHeader()
{
	cout << endl;
	cout << setw(17) << left << "Student ID" << setw(30) << left << "Name" << setw(26) << left << "Birthday" << setw(12) << left << "Grade" << setw(30) << left << "Hometown\n";
	cout << "\n";
}

void displayStudents(Student * student, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(17) << left << (*student).id << setw(30) << left << (*student).name;
		cout << setw(10) << left << ((*student).birthday.numToMonth()) << setw(3) << right << to_string((*student).birthday.getDay()) << ", ";
		cout << setw(11) << left << to_string((*student).birthday.getYear());
		cout << setw(12) << left << (*student).grade << setw(30) << left << (*student).homeTown;
		cout << endl;
		student = student + 1;
	}
	cout << endl;
}

void displayPointers(Student ** student, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(17) << left << (*student[i]).id << setw(30) << left << (*student[i]).name;
		cout << setw(10) << left << ((*student[i]).birthday.numToMonth()) << setw(3) << right << to_string((*student[i]).birthday.getDay()) << ", ";
		cout << setw(11) << left << to_string((*student[i]).birthday.getYear());
		cout << setw(12) << left << (*student[i]).grade << setw(30) << left << (*student[i]).homeTown;
		cout << endl;

	}
	cout << endl;
}
