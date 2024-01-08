/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will calculuate the cost of renting rooms in the hotel.
             It will show the cost of room, the discount, the bill, and etc.

Date: 9/14/2021
*/

#include<iostream>
#include<iomanip>

using namespace std;

//Function prototype
void Calculation(float Cost_Room, int Num_Room, int Num_Day, float Sales_Tax, float& Total_Cost_Room, float& Total_Bill, float& Show_Discount, float& Total_Bill_BeforeTax);

int main()
{
	float CostOneRoom, SalesTax, TotalCostRooms = 0, TotalBill = 0, NumberRoom, NumberDay, TotalBillBeforeTax = 0, ShowDiscount = 0;

	//user's Input
	do
	{
		cout << "Please enter the cost of renting one room: ";
		cin >> CostOneRoom;
		//Validation checking for Cost one room.
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is impossible for the cost renting." << endl;
			cout << "Please enter the cost of renting one room again: ";
			cin >> CostOneRoom;
		}
		if (CostOneRoom <= 0)
		{
			cout << "Sorry, the cost of renting must be positive number." << endl;
		}
	} while (CostOneRoom <= 0);

	cout << endl << "Cost of renting one room: $" << fixed << setprecision(2) << CostOneRoom << endl << endl;

	do
	{
		cout << "Please enter the number of rooms booked: ";
		cin >> NumberRoom;
		//validation checking for Number of Rooms
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is impossible for the number of roooms." << endl;
			cout << "Please enter the number of rooms booked again: ";
			cin >> NumberRoom;
		}
		if (NumberRoom <= 0)
		{
			cout << "Sorry, the number of rooms must be positive number." << endl;
		}
		if ( NumberRoom!=(int)NumberRoom) //checking for integer only
		{
			cout << "Sorry, the number of rooms must be an integer." << endl;
		}
	} while (NumberRoom <= 0 || NumberRoom != (int)NumberRoom);

	cout << endl << "The number of rooms booked: " << fixed << setprecision(0) <<  NumberRoom << " room(s)." << endl << endl;

	do
	{
		cout << "Please enter the number of days the rooms are booked: ";
		cin >> NumberDay;
		//Validation checking for Number of days
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is impossible for the number of days." << endl;
			cout << "Please enter the number of days the rooms are booked again: ";
			cin >> NumberDay;
		}
		if (NumberDay <= 0)
		{
			cout << "Sorry, the number of days must be positive number." << endl;
		}
		if (NumberDay != (int)NumberDay) //checking for integer only
		{
			cout << "Sorry, the number of days must be an integer." << endl;
		}
	} while (NumberDay <= 0 || NumberDay != (int)NumberDay);

	cout << endl << "The number of days the rooms are booked: " << NumberDay << " day(s)."<< endl << endl;

	do
	{
		cout << "Please enter the sales tax (as a percentage): ";
		cin >> SalesTax;
		//Validation checking for SalesTax
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is impossible for the sales tax." << endl;
			cout << "Please enter the sales tax again (as a percentage): ";
			cin >> SalesTax;
		}
		if (SalesTax <= 0)
		{
			cout << "Sorry, the sales tax must be positive number." << endl;
		}
	} while (SalesTax <= 0);

	cout << endl << "The sales tax: " << fixed << setprecision(2) << SalesTax << "% " << endl << endl;
	//End input

	Calculation(CostOneRoom, NumberRoom, NumberDay, SalesTax, TotalCostRooms, TotalBill, ShowDiscount, TotalBillBeforeTax);

	//Output
	cout << "Cost of renting one room:                $" << fixed << setprecision(2) << CostOneRoom << endl;
	cout << "The number of rooms booked:              " << fixed << setprecision(0) << NumberRoom << endl;
	cout << "The number of days the rooms are booked: " << NumberDay << endl;
	cout << "Discount on each room:                   " << fixed << showpoint << setprecision(2) << ShowDiscount << "% " << endl;
	cout << "The total cost of the rooms:             $" << TotalCostRooms << endl;  // Cost one room * number rooms * discount
	if (NumberDay >= 3)
	{
		cout << "Additional discount for at least 3 days: 5.00%" << endl;
	}
	cout << "The total billing before tax:            $" << TotalBillBeforeTax << endl; // total cost room * days * adddiscount
	cout << "The sales tax:                           " << SalesTax << "%" << endl;
	cout << "The total billing:                       $" << TotalBill << endl; // total * sales tax
	//End output
	return 0;
}
//End main

void Calculation(float Cost_Room, int Num_Room, int Num_Day, float Sales_Tax, float& Total_Cost_Room, float& Total_Bill, float& Show_Discount, float& Total_Bill_BeforeTax)
{
	const float LeastTen    = 0.90; //10%
	const float LeastTwenty = 0.80; //20%
	const float LeastThirty = 0.70; //30%
	const float AddDiscount = 0.95; //5%

	if (Num_Room < 10)
	{
		Total_Cost_Room = Cost_Room * Num_Room;
	}
	else if (Num_Room >= 10 && Num_Room < 20) //At least 10
	{
		Total_Cost_Room = (Cost_Room * LeastTen) * Num_Room;
		Show_Discount += 10;
	}
	else if (Num_Room <= 20 && Num_Room < 30) //At least 20
	{
		Total_Cost_Room = (Cost_Room * LeastTwenty) * Num_Room;
		Show_Discount += 20;
	}
	else // more than 30 (At least 30) 
	{
		Total_Cost_Room = (Cost_Room * LeastThirty) * Num_Room;
		Show_Discount += 30;
	}

	if (Num_Day >= 3)
	{
		Total_Bill_BeforeTax = (Total_Cost_Room * Num_Day) * AddDiscount;
	}
	else
	{
		Total_Bill_BeforeTax = (Total_Cost_Room * Num_Day);
	}

	Total_Bill = Total_Bill_BeforeTax * (1 + (Sales_Tax/100.0));
}