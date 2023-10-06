#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct occurenceType
{
	char letter;
	int occurence;
};

int openFile(ifstream& inFile, ofstream& outFile);
void initialize(occurenceType letters[]);
void count(ifstream& inFile, occurenceType letters[]);
void printResult(ofstream& outFile, occurenceType letters[]);

int main()
{
	ifstream inFile;
	ofstream outFile;
	bool isOpen = openFile(inFile, outFile);
	if (isOpen == 1)
		return 1;

	occurenceType letters[52];
	initialize(letters);
	count(inFile, letters);
	printResult(outFile, letters);
	return 0;
}

int openFile(ifstream& inFile, ofstream& outFile)
{
	string inName;
	cout << "Enter the name of the input file. " << endl;
	cin >> inName;
	inFile.open(inName.c_str());

	string outName;
	cout << "Enter the name of the output file. " << endl;
	cin >> outName;
	outFile.open(outName.c_str());

	if (!inFile)
	{
		cout << "The input file does not exist!!" << endl;
		cout << "The program terminates!!" << endl;
		return 1;
	}
	else
		return 0;

}

void initialize(occurenceType letters[])
{
	for (int i = 0; i < 26; i++)
	{
		letters[i].letter = static_cast<char>('A' + i);
		letters[i].occurence = 0;
	}

	for (int i = 0; i < 26; i++)
	{
		letters[i + 26].letter = static_cast<char>('a' + i);
		letters[i + 26].occurence = 0;
	}
}

void count(ifstream& inFile, occurenceType letters[])
{
	char letter;
	int index;

	inFile.get(letter);
	while (inFile)
	{
		if (letter >= 'A' && letter <= 'Z')
		{
			index = static_cast<int>(letter) - static_cast<int>('A');
			letters[index].occurence++;

		}
		else if (letter >= 'a' && letter <= 'z')
		{
			index = static_cast<int>(letter) - static_cast<int>('a');
			letters[26 + index].occurence++;

		}

		inFile.get(letter);

	}

}

void printResult(ofstream& outFile, occurenceType letters[])
{
	double totalLetters = 0;
	double totalCapital = 0;
	double totalSmall = 0;
	for (int i = 0; i < 52; i++)
	{
		outFile << letters[i].letter << "        " << letters[i].occurence << endl;
		totalLetters = totalLetters + letters[i].occurence;

		if (i < 26)
			totalCapital = totalCapital + letters[i].occurence;
		else
			totalSmall = totalSmall + letters[i].occurence;

	}
	outFile << endl << endl;
	outFile << "The percentage of Capital letters is: " << (totalCapital / totalLetters) * 100 << endl;
	outFile << "The percentage of Small letters is: " << (totalSmall / totalLetters) * 100 << endl;
}
