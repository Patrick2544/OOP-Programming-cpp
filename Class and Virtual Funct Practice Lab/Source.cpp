/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will output the list of sequences between two numbers
             including odd sequence and even sequence.

Date: 11/15/2021
*/

#include<iostream>

using namespace std;

//Abstract class
class AbstractSeq 
{
	protected:
		int k;
		int m;
		
	public:
		//the default constructor set the default value
		AbstractSeq()
		{
			//cout << "calling abstractseq\n";
			setk(1);
			setm(1);
		}

		//Pure virtual function
		virtual int fun(int k) = 0;

		//member functions
		void printSeq(int k, int m);
		int sumSeq(int k, int m);

		//setter or mutator
		void setk(int K) { k = K; }
		void setm(int M) { m = M; }

		//getter or accessor
		const int getk() { return k; }
		const int getm() { return m; }

};

class OddSeq :public AbstractSeq
{
	public:
		virtual int fun(int k) { return (2 * k) + 1; }
};


class EvenSeq :public AbstractSeq
{
	public:
		virtual int fun(int k) { return 2 * k; }
};

void AbstractSeq::printSeq(int k, int m)
{
	cout << "Listing all the sequence between " << k << " and " << m << endl;

	if (k < m)
	{ 
		for (int i = k-1; i < m; i ++)
		{
			cout << fun(i) << endl;
		}
		cout << endl;
	}
}

int AbstractSeq::sumSeq(int k, int m)
{
	int Sum = 0;

	if (k < m)
	{
		for (int i = k-1; i < m; i++)
		{
			Sum += fun(i);
		}
	}

	return Sum;
}

//Starting main****
int main()
{
	int FirstNum, SecondNum;
	int SumOdd = 0, SumEven = 0;

	do 
	{
		cout << "Please enter the first positive number (k): ";
		cin >> FirstNum;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Sorry, the input is invalid." << endl;
			cout << "Please enter the first positive number (k): ";
			cin >> FirstNum;
		}
		if (FirstNum <= 0)
		{
			cout << "Sorry, the number must be positive." << endl;
		}

	} while (FirstNum <= 0);


	AbstractSeq* AS1 = new OddSeq();

	AS1->setk(FirstNum);
	
	do
	{
		cout << "Please enter the second positive number (m): ";
		cin >> SecondNum;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Sorry, the input is invalid." << endl;
			cout << "Please enter the second positive number (k): ";
			cin >> SecondNum;
		}
		if (SecondNum <= 0)
		{
			cout << "Sorry, the number must be positive." << endl;
		}
	} while (SecondNum <= 0);

	AS1->setm(SecondNum);

	if (FirstNum < SecondNum)
	{
		cout << "\n\nOdd Sequence: " << endl;

		AS1->printSeq(FirstNum, SecondNum);

		SumOdd = AS1->sumSeq(FirstNum, SecondNum);

		cout << "The sum of the odd sequence is: " << SumOdd << endl;

		AbstractSeq* AS2 = new EvenSeq();

		AS2->setk(FirstNum);
		AS2->setm(SecondNum);

		cout << "\n\nEven Sequence: " << endl;

		AS2->printSeq(FirstNum, SecondNum);

		SumEven = AS2->sumSeq(FirstNum, SecondNum);

		cout << "The sum of the even sequence is: " << SumEven << endl;
	}
	else
	{
		cout << "\nSorry, k must be less then m in order to continue this program, terminating the program." << endl;
	}
	return 0;
}