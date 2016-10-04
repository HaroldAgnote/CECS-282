#include "myDate.h"
#include <iostream>
#include <random>

using namespace std;


struct Student
{
	string name;
	int id;
	char grade;
	myDate birthday;
	string homeTown;
};

void initializeStudent(Student & student);
int randomID();
char randomGrade();
myDate randomDate();


int main()
{
	Student CECS282[10];
	for (int i = 0; i < 10; i++)
	{
		initializeStudent(CECS282[i]);

		cout << CECS282[i].name << " " << CECS282[i].id << " " << CECS282[i].grade << " " << CECS282[i].homeTown << endl;
		CECS282[i].birthday.display();
		cout << endl;
	}

	system("pause");
	return 0;
}

void initializeStudent(Student & student)
{
	student.name = "Name";
	student.id = randomID();
	student.grade = randomGrade();
	student.birthday = randomDate();
	student.homeTown = "Hometown";
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
