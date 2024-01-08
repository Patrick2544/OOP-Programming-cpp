/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will convert a month and a day-month into a day within a year 1-365
             And will display the day before and after the target day.

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
	string month;

public:
	DayOfYear(int YearDay)
	{
		setDayInYear(YearDay);
		ConvertNumToMonth();
	}
	DayOfYear(string month, int NumMonth)
	{
		setStringMonth(month);
		setDayInMonth(NumMonth);
		ConvertMonthtoNum();
	}

	void ConvertNumToMonth();
	void ConvertMonthtoNum();
	void CheckEdgeDayAndUpdatedVal();
	void Print();

	//setter or mutator
	void setDayInYear(int DinY);
	void setDayInMonth(int DinM);
	void setIndexMonth(int Index); //{ IndexMonth = Index; }
	void setStringMonth(string m); //User input only

	//getter or accessor
	const int getDayInYear() { return DayInYear; }
	const int getDayInMonth() { return DayInMonth; }
	const int getIndexMonth() { return IndexMonth; }
	const string getStringMonth() { return month; }

	//overloaded operator
	DayOfYear operator++();
	DayOfYear operator++(int);
	DayOfYear operator--();
	DayOfYear operator--(int);
};

//static string declaration
string DayOfYear::Month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

//convert the number year 1-365 to month
//store the value of IndexMonth
//This Funct set Index and DayInMonth
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

//Convert string month back to number 1-365
void DayOfYear::ConvertMonthtoNum()
{
	if (month == Month[0])
	{
		DayInYear = 0;
		setIndexMonth(0);
	}
	else if (month == Month[1])
	{
		DayInYear = 31;
		setIndexMonth(1);
	}
	else if (month == Month[2])
	{
		DayInYear = 59;
		setIndexMonth(2);
	}
	else if (month == Month[3])
	{
		DayInYear = 90;
		setIndexMonth(3);
	}
	else if (month == Month[4])
	{
		DayInYear = 120;
		setIndexMonth(4);
	}
	else if (month == Month[5])
	{
		DayInYear = 151;
		setIndexMonth(5);
	}
	else if (month == Month[6])
	{
		DayInYear = 181;
		setIndexMonth(6);
	}
	else if (month == Month[7])
	{
		DayInYear = 212;
		setIndexMonth(7);
	}
	else if (month == Month[8])
	{
		DayInYear = 243;
		setIndexMonth(8);
	}
	else if (month == Month[9])
	{
		DayInYear = 273;
		setIndexMonth(9);
	}
	else if (month == Month[10])
	{
		DayInYear = 304;
		setIndexMonth(10);
	}
	else 
	{
		DayInYear = 334;
		setIndexMonth(11);
	}
	DayInYear += DayInMonth;
}

void DayOfYear::Print()
{
	cout << month << " " << DayInMonth << endl;
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

//This works only for user input
void DayOfYear::setDayInMonth(int DinM) 
{
	bool Cont = true;

	if (month == Month[0] && (DinM < 1 || DinM > 31))
	{
		Cont = false;
	}
	else if (month == Month[1] && (DinM < 1 || DinM > 28))
	{
		Cont = false;
	}
	else if (month == Month[2] && (DinM < 1 || DinM > 31))
	{
		Cont = false;
	}
	else if (month == Month[3] && (DinM < 1 || DinM > 30))
	{
		Cont = false;
	}
	else if (month == Month[4] && (DinM < 1 || DinM > 31))
	{
		Cont = false;
	}
	else if (month == Month[5] && (DinM < 1 || DinM > 30))
	{
		Cont = false;
	}
	else if (month == Month[6] && (DinM < 1 || DinM > 31))
	{
		Cont = false;
	}
	else if (month == Month[7] && (DinM < 1 || DinM > 31))
	{
		Cont = false;
	}
	else if (month == Month[8] && (DinM < 1 || DinM > 30))
	{
		Cont = false;
	}
	else if (month == Month[9] && (DinM < 1 || DinM > 31))
	{
		Cont = false;
	}
	else if (month == Month[10] && (DinM < 1 || DinM > 30))
	{
		Cont = false;
	}
	else if (month == Month[11] && (DinM < 1 || DinM > 31))
	{
		Cont = false;
	}

	if (!Cont)
	{
		cout << "Sorry, the input for day following by month is not appropriate" << endl;
		cout << "The program will be terminated." << endl;
		exit(1);
	}
	else
	{
		DayInMonth = DinM;
	}
}

void DayOfYear::setIndexMonth(int Index)
{
	for (int i = 0; i < 12; i++)
	{
		month = Month[Index];
	}
}

void DayOfYear::setStringMonth(string m)
{
	int count = 0;

	m[0] = toupper(m[0]);

	for (int i = 0; i < 12; i++)
	{
		if (m == Month[i])
		{
			month = m;
			count++;
		}
	}

	if (count != 1)
	{
		cout << "Sorry, the input for month is not appropriate" << endl;
		cout << "The program will be terminated." << endl;
		exit(1);
	}
		
}

void DayOfYear::CheckEdgeDayAndUpdatedVal()
{
	if (DayInYear == 366)
	{
		DayInYear = 1;
	}
	else if (DayInYear == 0)
	{
		DayInYear = 365;
	}

	//update value
	ConvertNumToMonth();
	
}


//overloaded operator prefix ++
DayOfYear DayOfYear::operator++()
{
	DayInYear++;
	CheckEdgeDayAndUpdatedVal();
	return *this;
	//derefence it and return the object whatever it is.
}

//overloaded operator postfix ++
//This one is special
//Because it return the old value and after than do the operation.
DayOfYear DayOfYear::operator++(int)
{
	DayOfYear temp(DayInYear);
	DayInYear++;
	CheckEdgeDayAndUpdatedVal();
	return temp;
}


//overloaded operator prefix --
DayOfYear DayOfYear::operator--()
{
	DayInYear--;
	CheckEdgeDayAndUpdatedVal();
	return *this;
	//derefence it and return the object whatever it is.
}


//overloaded operator postfix --
//This one is special
//Because it return the old value and after than do the operation.
DayOfYear DayOfYear::operator--(int)
{
	DayOfYear temp(DayInYear);
	DayInYear--;
	CheckEdgeDayAndUpdatedVal();
	return temp;
}


//main start here*****
int main()
{
	//int NumYear;
	string month;
	int NumDay;

	cout << "This program will convert a month and a day into the number within a year\nand print the day after and before the target day." << endl;
	cout << "Please enter the month follow by the day (Ex. January 3): ";
	cin >> month >> NumDay;

	DayOfYear D1(month, NumDay);
	D1.Print();

	--D1;
	cout << "The Day before this: ";
	D1.Print();
	
	++D1;
	D1++;
	cout << "The Day after this: ";
	D1.Print();
	
	return 0;
}