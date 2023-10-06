#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int N = 8;

struct menuItemtype
{
	string menuItem;
	double menuPrice;
};

void getData(ifstream& inFile, menuItemtype  list[]);
void showMenu(const menuItemtype list[]);
void printCheck(const menuItemtype list[], string choice);

int main()
{
	ifstream inFile;

	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "the file does not exist!!" << endl;
		cout << "The program termintes!!" << endl;
		return 1;
	}

	menuItemtype list[N];
	getData(inFile, list);
	showMenu(list);

	string choice;
	cout << endl;
	cout << "Please choose an item: " << endl;
	getline(cin, choice);
	cout << endl;
	printCheck(list, choice);



}

void getData(ifstream& inFile, menuItemtype  list[])
{
	for (int i = 0; i < N; i++)
	{
		getline(inFile, list[i].menuItem);
		inFile.ignore();
		inFile >> list[i].menuPrice;
		inFile.ignore();

	}
}

void showMenu(const menuItemtype list[])
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Welcome to Johnny's Restaurant! " << endl;
	cout << "Please find our menu below: " << endl;
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << left << setw(20) << list[i].menuItem;
		cout << right << setw(10) << "$" << list[i].menuPrice;
		cout << endl;
	}
}

void printCheck(const menuItemtype list[], string choice)
{
	for (int i = 0; i < N; i++)
	{
		if (list[i].menuItem == choice)
		{
			cout << left << setw(20) << list[i].menuItem;
			cout << right << setw(10) << "$" << list[i].menuPrice << endl;
			cout << left << setw(20) << "Tax";
			cout << right << setw(10) << "$" << list[i].menuPrice * 0.05;
			cout << endl;
			cout << left << setw(20) << "Amount Due";
			cout << right << setw(10) << "$" << list[i].menuPrice * (1 + 0.05);
			cout << endl;
			break;
		}
	}
}