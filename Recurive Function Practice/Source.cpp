/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program is the test program for using sign function as a recursive function

Date: 11/14/2021
*/

#include<iostream>

using namespace std;

void sign(int n);

int main()
{
	int Number;

	cout << "Please enter a number: ";
	cin >> Number;

	if (cin.fail())
	{
		cout << "Sorry, the input is invalid" << endl;
		cout << "Terminating the program." << endl;
		exit(1);
	}

	cout << "You entered: " << Number << endl;

	sign(Number);

	return 0;
}

void sign(int n)
{
	if (n > 0)
	{
		cout << "No Parking\n";
		sign(n - 1);
	}
}