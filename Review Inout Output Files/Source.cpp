/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will calculate the payment increase
             and output to the employee's file.

Date: 09/18/2021
*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
    ifstream InData;
    ofstream OutData;
    string LastName, FirstName;
    double CurrentSalary, NewSalary, PayIncrease, TotalSalary;
    bool Firsttime = true;

    InData.open("employeeSalary.txt");
    if (!InData)
    {
        cout << "Cannot open file, terminating program" << endl;
        exit(1);
    }

    OutData.open("employeeOutput.txt");

    OutData << fixed << showpoint << setprecision(2);

    InData >> LastName; //prime reading

    while (!InData.eof())
    {
        if (Firsttime)
        {
            InData >> FirstName;
            InData >> CurrentSalary;
            InData >> PayIncrease;
            Firsttime = false;

            NewSalary = CurrentSalary * (1 + (PayIncrease / 100));
            TotalSalary = NewSalary + CurrentSalary;

            OutData << FirstName << " " << LastName << " Updated salary: " << NewSalary << " Total updated salary: " << TotalSalary << endl;
        }
        else
        {
            InData >> LastName;
            InData >> FirstName;
            InData >> CurrentSalary;
            InData >> PayIncrease;

            NewSalary = CurrentSalary * (1 + (PayIncrease / 100));
            TotalSalary = NewSalary + CurrentSalary;

            OutData << FirstName << " " << LastName << " Updated salary: " << NewSalary << " Total updated salary: " << TotalSalary << endl;
        }

    }

    InData.close();
    OutData.close();

    return 0;
}