#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int N = 6;

struct salesPersonType
{
	string ID;
	double saleByQuarter[4];
	double totalSale;
};

void initialize(ifstream& inFile, salesPersonType p[]);
int findIndex(int m);
void calculateSales(salesPersonType p[]);
void readSalesData(ifstream& inFile, salesPersonType p[4]);
void totalByQuarter(double q[], salesPersonType p[]);
int findMaxPerson(salesPersonType p[]);
int findMaxQuarter(double p[]);
void printReport(ofstream& outFile, salesPersonType p[], double q[]);

int main()
{
	ifstream inFile;
	ofstream outFile;

	outFile.open("C:\\outData.txt");
	outFile << fixed << showpoint << setprecision(2);

	inFile.open("C:\\inData.txt");
	if (!inFile)
	{
		cout << "The file does not exist!" << endl;
		cout << "The program terminates!!" << endl;
		return 1;
	}


	salesPersonType salesPersonList[N];
	initialize(inFile, salesPersonList);
	inFile.close();
	inFile.clear();

	inFile.open("C:\\inData2.txt");
	if (!inFile)
	{
		cout << "The file does not exist!" << endl;
		cout << "The program terminates!!" << endl;
		return 1;
	}
	readSalesData(inFile, salesPersonList);

	double quarterSales[4] = { 0 };
	totalByQuarter(quarterSales, salesPersonList);

	printReport(outFile, salesPersonList, quarterSales);

	outFile << "Max sale by SalesPerson: ID = " << salesPersonList[findMaxPerson(salesPersonList)].ID
		<< " , Amount = " << salesPersonList[findMaxPerson(salesPersonList)].totalSale << endl;

	outFile << "Max sale by Quarter: Quarter = " << findMaxQuarter(quarterSales) + 1
		<< " , Amount = " << quarterSales[findMaxQuarter(quarterSales)] << endl;

	inFile.close();
	outFile.close();





	return 0;
}

void initialize(ifstream& inFile, salesPersonType p[])
{
	for (int i = 0; i < N; i++)
	{
		inFile >> p[i].ID;
		for (int j = 0; j < 4; j++)
			p[i].saleByQuarter[j] = 0;
		p[i].totalSale = 0;
	}
}

void readSalesData(ifstream& inFile, salesPersonType p[4])
{
	string ID;
	int month;
	double saleAmount;

	inFile >> ID;
	int i;
	while (inFile)
	{
		inFile >> month;
		inFile >> saleAmount;
		for (i = 0; i < N; i++)
			if (ID == p[i].ID)
			{
				p[i].saleByQuarter[findIndex(month)] = p[i].saleByQuarter[findIndex(month)] + saleAmount;
				break;
			}
		if (i == N)
			cout << "Invalid sales Person's ID!! " << endl;
		inFile >> ID;
	}
	calculateSales(p);

}

int findIndex(int m)
{
	switch (m)
	{
	case 1:
	case 2:
	case 3:
		return 0;
	case 4:
	case 5:
	case 6:
		return 1;
	case 7:
	case 8:
	case 9:
		return 2;
	case 10:
	case 11:
	case 12:
		return 3;
	}
}

void calculateSales(salesPersonType p[])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
			p[i].totalSale = p[i].totalSale + p[i].saleByQuarter[j];
}

void totalByQuarter(double q[], salesPersonType p[])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < N; i++)
			q[j] = q[j] + p[i].saleByQuarter[j];
	}

}

int findMaxPerson(salesPersonType p[])
{
	double maxSales = p[0].totalSale;
	int index = 0;
	for (int i = 1; i < N; i++)
	{
		if (p[i].totalSale > maxSales)
		{
			maxSales = p[i].totalSale;
			index = i;
		}
	}
	return index;
}

int findMaxQuarter(double p[])
{
	double max = p[0];
	int index = 0;

	for (int i = 1; i < 4; i++)
	{
		if (p[i] > max)
		{
			max = p[i];
			index = i;
		}
	}

	return index;

}

void printReport(ofstream& outFile, salesPersonType p[], double q[])
{
	outFile << setw(14) << setfill('-') << "   "
		<< "Anual Sales Report "
		<< setw(11) << setfill('-') << "-" << endl;
	outFile << endl;
	outFile << left << setfill(' ') << setw(9) << "ID             " << "QT1        "
		<< setw(11) << "QT2" << setw(11) << "QT3" << setw(11) << "QT4" << setw(11) << "Total" << endl;
	outFile << endl;
	outFile << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		outFile << left << setw(14) << p[i].ID;
		for (int j = 0; j < 4; j++)
			outFile << left << setw(11) << p[i].saleByQuarter[j];
		outFile << left << setw(11) << p[i].totalSale << endl;
	}

	outFile << left << setw(14) << "Total";
	for (int i = 0; i < 4; i++)
		outFile << left << setw(11) << q[i];
	outFile << endl << endl;

}