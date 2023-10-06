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

struct choiceType
{
	string name;
	int count;
	double price;
};

void getData(ifstream& inFile, menuItemtype  list[]);
void showMenu(const menuItemtype list[]);
void getChoices(menuItemtype list[], choiceType choices[]);
void printCheck(const choiceType choice[]);

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

	choiceType choices[N];
	getChoices(list, choices);
	printCheck(choices);



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

void getChoices(menuItemtype list[], choiceType choices[])
{
	for (int i = 0; i < N; i++)
	{
		choices[i].name = list[i].menuItem;
		choices[i].price = list[i].menuPrice;
		cout << "Enter how many " << list[i].menuItem << " you want." << endl;
		cin >> choices[i].count;

	}
}

void printCheck(const choiceType choice[])
{
	double amount = 0;
	for (int i = 0; i < N; i++)
	{
		amount = amount + choice[i].price * choice[i].count;
		if (choice[i].count != 0)
		{
			cout << left << setw(2) << choice[i].count;
			cout << left << setw(18) << choice[i].name;
			cout << right << setw(10) << "$" << choice[i].price << endl;
		}
	}

	cout << endl;
	cout << left << setw(20) << "Tax";
	cout << right << setw(10) << "$" << amount * 0.05;
	cout << endl;
	cout << left << setw(20) << "Amount Due";
	cout << right << setw(10) << "$" << amount * (1 + 0.05);
	cout << endl;
}