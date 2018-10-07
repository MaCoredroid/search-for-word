// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string search;
	ifstream inFile;
	string line;
	int a = 0;

	inFile.open("G:/Download/shakespeare.txt", ios::in);

	if (!inFile) {
		cout << "Unable to open file" << endl;
		exit(1);
	}
	cout << "Enter word to search for: ";
	cin >> search;
	int linenum = 0;

	size_t pos;
	while (inFile.good())
	{
		getline(inFile, line); // get line from file
		linenum++;
		pos = 0;
		do
		{


			pos = line.find(search, pos); // search
			if (pos < line.length() && (pos != string::npos) && (line[pos - 1] < 65 || (line[pos - 1]>90 &&line[pos-1]<97)|| line[pos - 1] >122)&& (line[pos+search.length()] < 65 || (line[pos + search.length()] > 90 && line[pos + search.length()] < 97) || line[pos + search.length()] >122) )// string::npos is returned if string is not found
			{
					a++;
					size_t temp = pos;
					cout << "line:" << linenum << "     ";
					cout << "pos:" << pos << "      ";
					cout << "previous word:";

					while (pos < line.length() && line[pos] != *" ")
					{
						pos--;
					}
					while (pos < line.length() && line[pos] == *" ")
					{
						pos--;
					}
					while (pos < line.length() && line[pos] != *" ")
					{
						pos--;
					}
					pos++;
					while (pos < line.length() && line[pos] != *" ")
					{
						cout << line[pos];
						pos++;
					}
					cout << "      ";
					cout << "next word:";
					while (pos < line.length() && line[pos] == *" ")
					{
						pos++;
					}
					while (pos < line.length() && line[pos] != *" ")
					{
						pos++;
					}
					while (pos < line.length() && line[pos] == *" ")
					{
						pos++;
					}
					while (pos < line.length() && line[pos] != *" ")
					{
						cout << line[pos];
						pos++;
					}
					cout << endl;
					pos = temp;
					pos++;
		     }
			else
			{
				break;
			}
		} while (pos < line.length());

		


	}
	cout << "occurrence:"<<a;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
