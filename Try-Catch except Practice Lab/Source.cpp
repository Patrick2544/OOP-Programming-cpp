/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will recieve a number and return the perfect square root of the number.
             If the number is not a perfect square root, the program will show an error by using throwing exception.

Date:11/29/2021
*/

#include<iostream>

using namespace std;

//Function prototype
int SquareRoot(int Num);

int main()
{
	int Number, Result;

	cout << "Please enter a number you would like to make a square root: ";
	cin >> Number;

	try
	{
		Result = SquareRoot(Number);
		cout << "The square root of " << Number << " is: " << Result << endl;
	}
	catch (const char* TxtException)
	{
		cout << "Exception: " << TxtException << endl;
	}

	return 0;
}

int SquareRoot(int Num)
{
	if (sqrt(Num) != (int)sqrt(Num) || Num <= 0)
	{
		throw "The square root is not a perfect square root, terminating program.\n";
	}

	return sqrt(Num);
}
