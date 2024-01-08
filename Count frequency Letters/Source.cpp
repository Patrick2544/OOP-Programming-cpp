/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program is to count the frequency of the character in English including upper and lower cases.

Date:10/26/2021
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int SIZE_ASCII_CODE = 128;

int main()
{
	ifstream InData; //works like cin
	string Word;
	int DecCode[SIZE_ASCII_CODE] = { 0 }; //Shortcut to set all elements to be 0

	InData.open("TextFile.txt");
	if (!InData)
	{
		cout << "Cannot open the file, terminating program." << endl;
		exit(1); 
	}

	while ((!InData.eof()))
	{
		getline(InData, Word); //This one read only one line at a time
	

		for (int i = 0; i < Word.size(); i++)
		{
			DecCode[(int)Word[i]]++;
		
		}
	}

	cout << "Here is the frequency letter table: " << endl;

	for (int i = 0; i < SIZE_ASCII_CODE; i++)
	{
		if (i >= 65 && i <= 90)
		{
			cout << " " << char(i) << ":" << DecCode[i] << endl;
		}
		else if (i >= 97 && i <= 122)
		{
			cout << " " <<  char(i) << ":" << DecCode[i] << endl;
		}
	}

	InData.close();
	return 0;
}