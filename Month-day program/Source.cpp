/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will convert a number within a year to be month-day format.

Date: 10/13/2021
*/

#include<iostream>
#include<string>

using namespace std;

class DayOfYear
{
	private:
		int DayInYear;
		int DayInMonth;
		static string Month[12];
		int IndexMonth;

	public:
		DayOfYear(int YearDay)
		{
			setDayInYear(YearDay);
			ConvertNumToMonth();
		}

		void ConvertNumToMonth();
		void Print();

		//setter or mutator
		void setDayInYear(int DinY);
		void setDayInMonth(int DinM) { DayInMonth = DinM; }
		void setIndexMonth(int Index) { IndexMonth = Index; }

		//getter or accessor
		const int getDayInYear() { return DayInYear; }
		const int getDayInMonth() { return DayInMonth; }
		const int getIndexMonth() { return IndexMonth; }
};

//static string declaration
string DayOfYear::Month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

//convert the number year 1-365 to month
//store the value of IndexMonth
void DayOfYear::ConvertNumToMonth()
{
	//set the index instead
	int DayMonthCalc = DayInYear; //temporary store for DayInYear so that it doesn't lose thr original value.

	if (DayInYear <= 31) //January
	{
		setIndexMonth(0);
		DayMonthCalc = DayInYear;
	}
	else if (DayInYear > 31 && DayInYear <= 59) //February
	{
		setIndexMonth(1);
		DayMonthCalc -= 31;
	}
	else if (DayInYear > 59 && DayInYear <= 90) //March
	{
		setIndexMonth(2);
		DayMonthCalc -= 59;
	}
	else if (DayInYear > 90 && DayInYear <= 120) //April
	{
		setIndexMonth(3);
		DayMonthCalc -= 90;
	}
	else if (DayInYear > 120 && DayInYear <= 151) //May
	{
		setIndexMonth(4);
		DayMonthCalc -= 120;
	}
	else if (DayInYear > 151 && DayInYear <= 181) //June
	{
		setIndexMonth(5);
		DayMonthCalc -= 151;
	}
	else if (DayInYear > 181 && DayInYear <= 212) //July
	{
		setIndexMonth(6);
		DayMonthCalc -= 181;
	}
	else if (DayInYear > 212 && DayInYear <= 243) //August
	{
		setIndexMonth(7);
		DayMonthCalc -= 212;
	}
	else if (DayInYear > 243 && DayInYear <= 273) //September
	{
		setIndexMonth(8);
		DayMonthCalc -= 243;
	}
	else if (DayInYear > 273 && DayInYear <= 304) //October
	{
		setIndexMonth(9);
		DayMonthCalc -= 273;
	}
	else if (DayInYear > 304 && DayInYear <= 334) //November
	{
		setIndexMonth(10);
		DayMonthCalc -= 304;
	}
	else //December
	{
		setIndexMonth(11);
		DayMonthCalc -= 334;
	}
	setDayInMonth(DayMonthCalc);
}

void DayOfYear::Print()
{
	cout << Month[IndexMonth] << " " << DayInMonth << endl;
}

void DayOfYear::setDayInYear(int DinY)
{
	if (DinY < 1 || DinY > 365)
	{
		cout << "Sorry, the day within a year must be between 1 and 365." << endl;
		cout << "The program will be terminated." << endl;
		exit(1);
	}
	else
	{
		DayInYear = DinY;
	}
}

//main start here*****
int main()
{
	int NumYear;

	cout << "This program will convert number within a year into a month-day format." << endl;
	cout << "Please enter the number within a year (1-365): ";
	cin >> NumYear;

	DayOfYear D1(NumYear);
	
	
	D1.Print();

	return 0;
}