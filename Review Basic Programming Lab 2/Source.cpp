/*
Programmer name: Jittapatana Prayoonpruk

Description: This is the box office program.
             It will calulate the gross and net profit 
			 for the box office and etc.

Date: 09/09/2021
*/

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//Function prototype
void CalculationPart(int& Adult_Sold, int& Child_Sold, float& Gross_Profit, float& Paid_Distributor, float& Net_Profit, int Adult_Ticket, int Child_Ticket);

int main()
{
	string MovieName;
	int AdultTicket, ChildTicket;
	int AdultSold = 0, ChildSold = 0;
	float PaidDistributor = 0, NetProfit = 0, GrossProfit = 0;

	//Input
	cout << "Please enter the name of the movie: ";
	getline(cin, MovieName);
	cout << "Your movie: " << "\"" << MovieName << "\"" << endl << endl;

	do
	{
		cout << "Please enter number of adult ticket that was sold: ";
		cin >> AdultTicket;
		//Checking validation of Adult ticket
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is impossible for adult ticket" << endl;
			cout << "Please enter number of adult ticket that was sold again: ";
			cin >> AdultTicket;
		}
		if (AdultTicket < 0)
		{
			cout << "The number of adult ticket cannot be negative" << endl;
		}
	} while (AdultTicket < 0);

	cout << "\nThe number of adult ticket that was sold: " << AdultTicket << endl << endl;

	do
	{
		cout << "Please enter number of child ticket that was sold: ";
		cin >> ChildTicket;
		//Checking Validation of Children ticket
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is impossible for child ticket" << endl;
			cout << "Please enter number of child ticket that was sold again: ";
			cin >> ChildTicket;
		}
		if (ChildTicket < 0)
		{
			cout << "The number of child ticket cannot be negative" << endl;
		}
	} while (ChildTicket < 0);

	cout << "\nThe number of child ticket that was sold: " << ChildTicket << endl << endl;
	//end input

	if (AdultTicket != 0 || ChildTicket != 0)
	{
		CalculationPart(AdultSold, ChildSold, GrossProfit, PaidDistributor, NetProfit, AdultTicket, ChildTicket);
		//output
		cout << "Movie Name:                   " << "\"" << MovieName << "\"" << endl;
		cout << "Adult Ticket Sold:            " << AdultTicket << endl;
		cout << "Child Ticket Sold:            " << ChildTicket << endl;
		cout << fixed << showpoint << setprecision(2);
		cout << "Gross Box Office Profit:      $" << GrossProfit << endl;
		cout << "Amount Paid to Distributor:   $" << PaidDistributor << endl;
		cout << "Net Box Office Profit:        $" << NetProfit << endl;
		//end output
	}
	else
	{
		//output case 0 ticket.
		cout << "The movie theater did not sell any tickets." << endl;
		cout << "There are no profit and none of paid amount." << endl;
		cout << "Thank you." << endl;
	}


	return 0;
}
//End main*****************

void CalculationPart(int& Adult_Sold, int& Child_Sold, float& Gross_Profit, float& Paid_Distributor, float& Net_Profit, int Adult_Ticket, int Child_Ticket)
{
	const int PriceAdult = 6, PriceChild = 3;
	const float ThearterKeep = 0.20, AmountDistributor = 0.80;

	Adult_Sold = Adult_Ticket * PriceAdult;
	Child_Sold = Child_Ticket * PriceChild;
	Gross_Profit = Adult_Sold + Child_Sold;
	Paid_Distributor = Gross_Profit * AmountDistributor;
	Net_Profit = Gross_Profit * ThearterKeep;

}