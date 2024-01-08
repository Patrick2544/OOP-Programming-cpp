/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will compute and display the charges for a patient's hospital stay.
             (By the options of in-patient or out-patient)

Date: 09/21/2021
*/

#include<iostream>
#include<iomanip>

using namespace std;

//Function prototype
double ValidatingData(double Data, bool integer);
double CalcTotal(double Num_Days, double Daily_Rate, double Hospital_Services, double Med_Charges);
double CalcTotal(double Hosp_Services, double Medication_Charges);

int main()
{
	double DailyRate, ServiceCharge, MedCharge, TotalCharge, NumberDay;
	char PatientType;

	cout << "Thank you for trusting our hospital, here is the calculating program for your bill." << endl << endl;
	cout << "What is your type of patient: \nA: in-patient\nB: out-patient\nif you are an in-patient please enter 'A', out-patient please enter 'B'";
	cin >> PatientType;
	PatientType = toupper(PatientType);

	switch (PatientType)
	{
		case 'A':	// in-patient case
			
			//Input
			cout << endl <<"Please enter the number of days spent in the hospital: ";
			cin >> NumberDay;
			//calling function and storing it in NumberDay
			NumberDay = ValidatingData(NumberDay, true);
			cout << endl << "You have spent: " << NumberDay << " day(s) in the hospital." << endl << endl;

			cout << fixed << showpoint << setprecision(2);

			cout << "Please enter the daily rate: ";
			cin >> DailyRate;
			//calling function and storing it in DailyRate
			DailyRate = ValidatingData(DailyRate, false);
			cout << "Your daily rate: $" << DailyRate << endl << endl;

			cout << "Please enter the charges for hospital services: ";
			cin >> ServiceCharge;
			//calling function and storing it in ServiceCharge
			ServiceCharge = ValidatingData(ServiceCharge, false);
			cout << "Your hospital service charges: $" << ServiceCharge << endl << endl;

			cout << "Please enter the hospital medication charges: ";
			cin >> MedCharge;
			//calling function and storing it in MedCharge
			MedCharge = ValidatingData(MedCharge, false);
			cout << "Your hospital medication charges: $" << MedCharge << endl << endl;
			//end input

			TotalCharge = CalcTotal(NumberDay, DailyRate, ServiceCharge, MedCharge);
			//output
			cout << "Patient type:                     in-patient" << endl;
			cout << "Daily rate:                       $" << DailyRate << endl;
			cout << "Day Spent in the hospital:        "  << (int)NumberDay << " day(s) in the hospital." << endl;
			cout << "Hospital service charges:         $" << ServiceCharge << endl;
			cout << "Hospital medication charges:      $" << MedCharge << endl;
			cout << "Total charges:                    $" << TotalCharge << endl;
			break;

		case 'B':  // out-patient case
			cout << fixed << showpoint << setprecision(2);
			//input
			cout << "Please enter the charges for hospital services: ";
			cin >> ServiceCharge;
			//calling function and storing it in ServiceCharge
			ServiceCharge = ValidatingData(ServiceCharge, false);
			cout << "Your hospital service charges: $" << ServiceCharge << endl << endl;

			cout << "Please enter the hospital medication charges: ";
			cin >> MedCharge;
			//calling function and storing it in MedCharge
			MedCharge = ValidatingData(MedCharge, false);
			cout << "Your hospital medication charges: $" << MedCharge << endl << endl;
			//end input

			TotalCharge = CalcTotal(ServiceCharge, MedCharge);

			//output
			cout << "Patient type:                     out-patient" << endl;
			cout << "Hospital service charges:         $" << ServiceCharge << endl;
			cout << "Hospital medication charges:      $" << MedCharge << endl;
			cout << "Total charges:                    $" << TotalCharge << endl;
			break;

		default:   // doesn't match any cases
			cout << "Sorry, we cannot match the type of patient." << endl;
	}
	return 0;
}
//End main


//precondition:takes in a double or int Data and a bool isInt that determines whether or not Data was originally an int (Input)
//postcondition:returns a validated double or int that is greater than 0 (Output)
//description:validates Data to ensure that it is both greater than 0 and it is either an int or double depending on IsInt (Inside the box)
double ValidatingData(double Data, bool isInt)
{
	if (isInt) // this condition only accepts positive integers 1,15,100,9999
	{
		while (Data != int(Data) || Data < 0 || cin.fail()) //checking if it is not an integer or it is less than 0, or it doesn't match data type
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
				cout << "Sorry, the data is impossible." << endl;
				cout << "Please enter the data again: ";
				cin >> Data;
			}
			else if (Data < 0)
			{
				cout << "Sorry, the data cannot be less than zero." << endl;
				cout << "Please enter the data again: ";
				cin >> Data;
			}
			else if (Data != int(Data))
			{
				cout << "Sorry, the data should be integer." << endl;
				cout << "Please enter the data again: ";
				cin >> Data;
			}
		}
	}
	else  // this condition only accepts positive doubles 1,15,19.99,14.95
	{
		while (Data < 0 || cin.fail()) //checking for less than zero and doesn't match the data type
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
				cout << "Sorry, the data is impossible." << endl;
				cout << "Please enter the data again: ";
				cin >> Data;
			}
			else if (Data < 0)
			{
				cout << "Sorry, the data cannot be less than zero." << endl;
				cout << "Please enter the data again: ";
				cin >> Data;
			}
		}
	}
	//return value back
	return Data;
}

double CalcTotal (double Num_Days, double Daily_Rate, double Hospital_Services, double Med_Charges) 
{
	double Totalbill;
	Totalbill = (Num_Days * Daily_Rate) + Hospital_Services + Med_Charges;

	return Totalbill;
}

double CalcTotal (double Hosp_Services, double Medication_Charges)
{
	double Total_bill;
	Total_bill = Hosp_Services + Medication_Charges;

	return Total_bill;
}