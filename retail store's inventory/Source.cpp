/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program is designed to hold an information for an item in a retail store's inventory.
             (By using class inventory)

Date:09/25/2021
*/

#include<iostream>
#include<iomanip>

using namespace std;

class Inventory
{
	private:
		int itemNumber;
		int quantity;
		double cost;

	public:
		Inventory()
		{
			itemNumber = 0;
			quantity = 0;
			cost = 0;
		}
		Inventory(int itemNum, int q, double c) 
		{
			setItemNumber(itemNum);
			setQuantity(q);
			setCost(c);
		}

		//setters or mutators
		void setItemNumber(int i) { itemNumber = i; }
		void setQuantity(int q) { quantity = q; }
		void setCost(double c) { cost = c; }

		//getters or accessors
		int getItemNumber() { return itemNumber; }
		int getQuantity() { return quantity; }
		double getCost() { return cost; }

		double getTotalCost() { return quantity * cost; }

};


//function prototype
int ValidatingInt(int& Data);
double ValidatingDouble(double& Data);

int main()
{
	Inventory I1;
	int NumOfItem, Quan;
	double CostItem;

	/*
	cout << "Please enter the new number of item :";
	cin >> NumItem;
	cout << "Calling setItemNumber() with user input:" << NumItem << endl;
	I1.setItemNumber(NumItem);
	cout << "Calling getItemNumber():"<< I1.getItemNumber();
	*/

	cout << "Please enter the number of item :";
	cin >> NumOfItem;
	//called function to validating Int
	ValidatingInt(NumOfItem);
	//called the setter to set the value of ItemNumber
	I1.setItemNumber(NumOfItem);
	cout << "Your item number: " << I1.getItemNumber() << endl; ////use getter to check if the value have changed

	cout << "Please enter the number of quantity: ";
	cin >> Quan;
	//called function to validating Int
	ValidatingInt(Quan);
	//called the setter to set the value of Quantity
	I1.setQuantity(Quan);
	cout << "Your quantity for the item: " << I1.getQuantity() << endl; //use getter to check if the value have changed

	cout << fixed << showpoint << setprecision(2);

	cout << "Please enter the cost of the item: ";
	cin >> CostItem;
	//called function to validating Int
	ValidatingDouble(CostItem);
	//called the setter to set the value of cost
	I1.setCost(CostItem);
	cout << "Your cost for the item: $" << I1.getCost() << endl << endl; ////use getter to check if the value have changed

	//Output
	cout << "Item number:           " << I1.getItemNumber() << endl;
	cout << "Cost for one item:     $" << I1.getCost() << endl;
	cout << "Quanity for this item: " << I1.getQuantity() << endl;
	cout << "Total cost:            $" << I1.getTotalCost() << endl;

	return 0;
}
//End main

int ValidatingInt(int& Data)
{
	while (Data < 0 || cin.fail())
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is impossible for this data." << endl;
			cout << "Please enter again: ";
			cin >> Data;
		}
		else if (Data < 0)
		{
			cout << "Sorry, the number input cannot be nagative." << endl;
			cout << "Please enter again: ";
			cin >> Data;
		}
	}
	return Data;
}

double ValidatingDouble(double& Data)
{
	while (Data < 0 || cin.fail())
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Sorry, the input is impossible for this data." << endl;
			cout << "Please enter again: ";
			cin >> Data;
		}
		else if (Data < 0)
		{
			cout << "Sorry, the number input cannot be nagative." << endl;
			cout << "Please enter again: ";
			cin >> Data;
		}
	}
	return Data;
}