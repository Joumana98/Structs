// Exercise 1

#include <iostream>
#include <iomanip>

using namespace std;

const int N = 5;

struct studentType
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;

};

void readData(studentType array[]);
void assignGrade(studentType array[]);
int highestScore(studentType array[]);
void printHighest(studentType array[], int max);


int main()
{

	studentType students[N];
	readData(students);
	assignGrade(students);

	int highest = highestScore(students);
	printHighest(students, highest);

	return 0;
}

void readData(studentType array[])
{
	for (int i = 0; i < N; i++)
	{
		cout << "Enter the first name of student " << i + 1 << " :" << endl;
		cin >> array[i].studentFName;
		cout << "Enter the last name of student " << i + 1 << " :" << endl;
		cin >> array[i].studentLName;
		cout << "Enter the test score of student " << i + 1 << " :" << endl;
		cin >> array[i].testScore;
	}
}

void assignGrade(studentType array[])
{
	for (int i = 0; i < N; i++)
	{
		switch (array[i].testScore / 10)
		{
		case 9:
			array[i].grade = 'A';
		case 8:
			array[i].grade = 'B';
		case 7:
			array[i].grade = 'C';
		case 6:
			array[i].grade = 'D';
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			array[i].grade = 'F';
		}
	}
}

int highestScore(studentType array[])
{
	int max = array[0].testScore;
	for (int i = 1; i < N; i++)
	{
		if (array[i].testScore > max)
			max = array[i].testScore;
	}

	cout << "The highest test score is: " << max << endl;
	cout << endl;

	return max;
}

void printHighest(studentType array[], int max)
{
	cout << "The students with the highest test scores are: " << endl;
	for (int i = 0; i < N; i++)
	{
		if (array[i].testScore == max)
			cout << left << array[i].studentLName << ", " << array[i].studentFName << endl;
	}
}