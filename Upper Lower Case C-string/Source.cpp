/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will recieve a string of character
             and convert to upper case, lower case, and flip between upper and lower case
			 by using C-string.

Date: 10/18/2021
*/

#include<iostream>

using namespace std;

//constant global variable
const int SIZE_STRING = 20;

//Function prototype
void PrintArr(char* CString);
void FlipFunction(char* CString);
void LowerFunction(char* CString);
void UpperFunction(char* CString);

int main()
{
	//creating a C-string
	char* CString;

	//Allocate the array
	CString = new char[SIZE_STRING];

	cout << "Please enter the list of characters: ";
	cin.getline(CString, SIZE_STRING);

	FlipFunction(CString);

	cout << "\nAfter calling Flip function: ";
	PrintArr(CString);

	LowerFunction(CString);
	cout << "\nAfter calling Lower function: ";
	PrintArr(CString);

	UpperFunction(CString);
	cout << "\nAfter calling Upper function: ";
	PrintArr(CString);

	//Delete the array and make it null so it will not point to any memory in the program
	//must use every time that using new (line 27)
	delete[]CString;
	CString = NULL;

	return 0;
}
//End main*****

//Print the Array
void PrintArr(char* CString)
{
	for (int i = 0; CString[i] != NULL; i++)
	{
		cout << CString[i];
	}

	cout << endl;
}

//Flipe the character from lower case to upper case
//and from upper case to lower case
void FlipFunction(char *CString)
{
	//ASCII CODE lower case are 97-122
	//ASCII CODE upper case are 65-90

	for (int i = 0; CString[i] != NULL; i++)
	{
		//Convert Lower case to Upper case
		if (CString[i] >= 97 && CString[i] <= 122)
		{
			CString[i] -= 32;
		}
		//Convert Upper case to Lower case
		else if (CString[i] >= 65 && CString[i] <= 90)
		{
			CString[i] += 32;
		}
	}
}

//Change eveey character to lower case
void LowerFunction(char* CString)
{
	//ASCII CODE upper case are 65-90

	for (int i = 0; CString[i] != NULL; i++)
	{
		if (CString[i] >= 65 && CString[i] <= 90)
		{
			CString[i] += 32;
		}
	}

}

//Change every character to upper case
void UpperFunction(char* CString)
{
	// ASCII CODE lower case are 97 - 122

	for (int i = 0; CString[i] != NULL; i++)
	{
		if (CString[i] >= 97 && CString[i] <= 122)
		{
			CString[i] -= 32;
		}
	}

	cout << endl;
}