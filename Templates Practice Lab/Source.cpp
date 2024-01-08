/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will test 3 data types including int, float, and string by returning the Min and Max of each of them
             by using templates.

Date:11/29/2021
*/

#include<iostream>
#include<string>

using namespace std;

template <class T>
T Min(T FirstNum, T SecondNum)
{
	if (FirstNum < SecondNum)
	{
		return FirstNum;
	}
	else
	{
		return SecondNum;
	}
}

template <class T>
T Max(T FirstNum, T SecondNum)
{
	if (FirstNum > SecondNum)
	{
		return FirstNum;
	}
	else
	{
		return SecondNum;
	}
}

int main()
{
	float IntNum1, IntNum2;
	float FloatNum1, FloatNum2;
	string FirstStr, SecondStr;

	cout << "The first step is to testing the data type of integer" << endl << endl;

	do
	{
		cout << "Please enter two integer numbers separate them by using a space (EX. 2 4): ";
		cin >> IntNum1 >> IntNum2;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is not integer numbers" << endl;
			cout << "Please enter two integer numbers again seperate by space (Ex. 2 4): ";
			cin >> IntNum1 >> IntNum2;
		}
		if (IntNum1 != (int)IntNum1 || IntNum2 != (int)IntNum2)
		{ 
			cout << "Sorry, both of numbers must be integer numbers" << endl;
		}

	} while (IntNum1 != (int)IntNum1 || IntNum2 != (int)IntNum2);

	cout << "The minimum is: " << Min(IntNum1, IntNum2) << endl;
	cout << "The maximum is: " << Max(IntNum1, IntNum2) << endl << endl;

	cout << "The second step is to testing the data type of float" << endl << endl;

	cout << "Please enter two float numbers separate them by using a space (EX. 2.5 4.2): ";
	cin >> FloatNum1 >> FloatNum2;

	cout << "The minimum is: " << Min(FloatNum1, FloatNum2) << endl;
	cout << "The maximum is: " << Max(FloatNum1, FloatNum2) << endl << endl;

	cout << "The last step is to testing the data type of string" << endl << endl;

	cout << "Please enter two string separate them by using a space (EX. abc efgh): ";
	cin >> FirstStr >> SecondStr;

	cout << "The minimum length is: " << Min(FirstStr, SecondStr) << endl;
	cout << "The maximum length is: " << Max(FirstStr, SecondStr) << endl << endl;
	

	return 0;
}

