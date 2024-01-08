/*
Programmer Name: Jittapatana Prayoonrpruk

Description: This program will receive the set of imformation determine by user, 
			 then it will rotate to the left according to its size by using template. 
			 This program will demonstrate that the template can handle 
			 the following data types: int, char, double, and string.

Date:11/30/2021
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

template <class T>
void RotateLeft(vector <T>& v)
{
	int RotateL = 1;
	rotate(v.begin(), v.begin() + RotateL, v.end());
}

template <class T>
void Output(vector <T> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	int VectorSize;
	vector<int> IntVector;
	vector<char> CharVector;
	vector<double> DoubleVector;
	vector<string> StrVector;
	int TempInt;
	char TempChar;
	double TempDouble;
	string TempStr;

	cout << "The first step is to verify the integer data type" << endl;
	cout << "Please determine the size of your information: ";
	cin >> VectorSize;

	int i = 1;
	while (VectorSize > 0)
	{
		cout << "Please enter your integer "<< i << " element: ";
		cin >> TempInt;
		IntVector.push_back(TempInt);
		i++;
		VectorSize--;
	}
	VectorSize = IntVector.size();

	while (VectorSize > 0)
	{
		Output(IntVector);
		RotateLeft(IntVector);
		VectorSize--;
	}

	cout << "The second step is to verify the char data type" << endl;
	cout << "Please determine the size of your information: ";
	cin >> VectorSize;

	i = 1;
	while (VectorSize > 0)
	{
		cout << "Please enter your character " << i << " element: ";
		cin >> TempChar;
		CharVector.push_back(TempChar);
		i++;
		VectorSize--;
	}

	VectorSize = CharVector.size();
	while (VectorSize > 0)
	{
		Output(CharVector);
		RotateLeft(CharVector);
		VectorSize--;
	}

	cout << "The third step is to verify the double data type" << endl;
	cout << "Please determine the size of your information: ";
	cin >> VectorSize;

	i = 1;
	while (VectorSize > 0)
	{
		cout << "Please enter your decimal number " << i << " element: ";
		cin >> TempDouble;
		DoubleVector.push_back(TempDouble);
		i++;
		VectorSize--;
	}

	VectorSize = DoubleVector.size();
	while (VectorSize > 0)
	{
		Output(DoubleVector);
		RotateLeft(DoubleVector);
		VectorSize--;
	}

	cout << "The last step is to verify the string data type" << endl;
	cout << "Please determine the size of your information: ";
	cin >> VectorSize;

	i = 1;
	while (VectorSize > 0)
	{
		cout << "Please enter your string " << i << " element: ";
		cin >> TempStr;
		StrVector.push_back(TempStr);
		i++;
		VectorSize--;
	}

	VectorSize = StrVector.size();
	while (VectorSize > 0)
	{
		Output(StrVector);
		RotateLeft(StrVector);
		VectorSize--;
	}


	return 0;
}