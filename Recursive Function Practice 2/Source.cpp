/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will calculate the multiplication of two numbers
             by using recursive function.

Date: 11/14/2021
*/

#include<iostream>

using namespace std;

int RecursiveMult(int x, int y);

int main()
{
	int FirstNum, SecondNum, Result;

	do
	{
		cout << "Please enter the first positive number: ";
		cin >> FirstNum;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is invalid." << endl;
			cout << "Please enter the first positive number: ";
			cin >> FirstNum;
		}

		if (FirstNum < 0 )
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input must be positive number." << endl;
		}

	} while (FirstNum < 0);

	do
	{
		cout << "\nPlease enter the second positive number: ";
		cin >> SecondNum;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is invalid." << endl;
			cout << "Please enter the second positive number: ";
			cin >> SecondNum;
		}

		if (SecondNum < 0)
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input must be positive number." << endl;
		}
	} while (SecondNum < 0);

	cout << "The program will calculate the following: " << FirstNum << " * " << SecondNum << endl << endl;

	//cout << "The process behind the recursive function: ";

	Result = RecursiveMult(FirstNum, SecondNum);


	cout << "The result is: " << Result << endl;

	return 0;
}

int RecursiveMult(int x, int y)
{
	if (x == 0 || y == 0)
	{
		//cout << y;
		return 0;
	}

	//cout << y << " + ";
	return y + RecursiveMult(x - 1, y);
}