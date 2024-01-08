/*
Prgrammer Name: Jittapatana Prayoonpruk

Description: This program will display the sum of all the single digit numbers
             and the maximum and minimum in the string by using C-string.

Date: 10/18/2021
*/

#include<iostream>

using namespace std;

int main()
{
	const int SIZE_ARR = 20;
	int Sum = 0;
	char Max, Min;
	//creating a C-string
	char* NumArray;

	//Allocate the array
	NumArray = new char[SIZE_ARR];

	cout << "Please enter the number of integer with nothing separating them (EX. 2514): ";
	cin.getline(NumArray, SIZE_ARR);

	for (int i = 0; NumArray[i] != NULL; i++)
	{
		if (NumArray[i] < 48 || NumArray[i] > 57)
		{
			cout << "Sorry, this program can only handle the single digit number with nothing separation them." << endl;
			cout << "the program will be terminated." << endl;
			exit(1);
		}
	}

	Max = NumArray[0];
	Min = NumArray[0];

	//ASCII code 48-57 are 0-9

	for (int i = 0; NumArray[i] != NULL; i++)
	{
		if (NumArray[i] > Max)
		{
			Max = NumArray[i];
		}
		if (NumArray[i] < Min)
		{
			Min = NumArray[i];
		}
		//change the value of ASCII by minus 48 bc the first number(0) begins with 48
		NumArray[i] -= 48;

		Sum += NumArray[i];
	}

	cout << "The sum of numbers is: " << Sum << endl;
	cout << "The Minimum number is: " << Min << endl;
	cout << "The Maximum number is: " << Max << endl;

	//Delete the array and make it null so it will not point to any memory in the program
	//must use every time that using new (line 22)
	delete[]NumArray;
	NumArray = NULL;
	return 0;
}