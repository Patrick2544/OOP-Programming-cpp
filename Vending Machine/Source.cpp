/*
Programmer Name: Jittapatana Prayoonpruk

Description: This is a vending machine program with a five different type of  drinks

Date:09/30/2021
*/

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//Global constant variable
const int NUM_DRINKS = 5;

struct DrinkType
{
	string DrinkName;
	double Cost;
	int Quantity;
};
//End Struct

class VendingMachine
{
	private:
		DrinkType DrinkList[NUM_DRINKS];
		double MoneyEarned;
		int choice;

		double InputMoney(int Option);
		void DailyReport();
	public:
		//constructor
		VendingMachine()
		{
			MoneyEarned = 0;
			InitDrinks();
		}
		//destructor
		~VendingMachine()
		{
			DailyReport();
		}

		//member functions
		 void Displaychoice();  
		 void InitDrinks();
		 double BuyDrink(int Option);
		 
};

//Private member functions
//must be called by buyDrink
//to accept, validate, and return (to buyDrink) the amount of money input
//passing it the patron’s drink choice
double VendingMachine::InputMoney(int Option)
{
	double Credit;

	cout << "choosing: " << DrinkList[Option - 1].DrinkName << endl;
	cout << "Please insert: $" << DrinkList[Option - 1].Cost << endl;
	cin >> Credit;

	while (Credit <= 0)
	{
		cout << "Sorry the amount of money must be positive number." << endl;
		cout << "Please enter the amount of money again: ";
		cin >> Credit;
	}

	cout << "Money inserted: $" << Credit << endl;
	

	return Credit;
}

void VendingMachine::DailyReport()
{
	cout << endl << "This is the daily report" << endl;
	cout << " Drinks" << setw(21) << "Cost" << setw(18) << "Quantity" << endl;
	cout << " 1: " << DrinkList[0].DrinkName << setw(20) << DrinkList[0].Cost << setw(15) << DrinkList[0].Quantity << endl;
	cout << " 2: " << DrinkList[1].DrinkName << setw(15) << DrinkList[1].Cost << setw(15) << DrinkList[1].Quantity << endl;
	cout << " 3: " << DrinkList[2].DrinkName << setw(13) << DrinkList[2].Cost << setw(15) << DrinkList[2].Quantity << endl;
	cout << " 4: " << DrinkList[3].DrinkName << setw(14) << DrinkList[3].Cost << setw(15) << DrinkList[3].Quantity << endl;
	cout << " 5: " << DrinkList[4].DrinkName << setw(11) << DrinkList[4].Cost << setw(15) << DrinkList[4].Quantity << endl;
	
	cout << "The collected money: $" << MoneyEarned << endl;
}

//Public member functions

//Display menu of drink names and prices
//tell the present qunatity we have left
void VendingMachine::Displaychoice()
{
	cout << fixed << showpoint << setprecision(2) << endl;
	
	/*cout << "Drinks             Price       Quantity" << endl;
	for (int i = 1; i <= NUM_DRINKS; i++)
	{
		cout << " " << i << ": " << DrinkList[i-1].DrinkName << DrinkList[i-1].Cost << "          " << DrinkList[i-1].Quantity << endl;
	}
	cout << " " << NUM_DRINKS+1 << ": Quit" << endl;*/
	cout << " Drinks" << setw(21) << "Cost" << setw(18) << "Quantity" << endl;
	cout << " 1: " << DrinkList[0].DrinkName << setw(20) << DrinkList[0].Cost << setw(15) << DrinkList[0].Quantity << endl;
	cout << " 2: " << DrinkList[1].DrinkName << setw(15) << DrinkList[1].Cost << setw(15) << DrinkList[1].Quantity << endl;
	cout << " 3: " << DrinkList[2].DrinkName << setw(13) << DrinkList[2].Cost << setw(15) << DrinkList[2].Quantity << endl;
	cout << " 4: " << DrinkList[3].DrinkName << setw(14) << DrinkList[3].Cost << setw(15) << DrinkList[3].Quantity << endl;
	cout << " 5: " << DrinkList[4].DrinkName << setw(11) << DrinkList[4].Cost << setw(15) << DrinkList[4].Quantity << endl;
	cout << " 6: " << "Exit the purchase." << endl;

}

//handles a sale
//Must call InputMoney
//return Credit
double VendingMachine::BuyDrink(int Option)
{
	double Credit;
	char Purchase;

	Credit = InputMoney(Option);
	//If the patron no longer wishes to make the purchase, return all input money.
	//body
	cout << "Do you still want to purchase your drink: " << DrinkList[Option - 1].DrinkName << "  Cost $" << DrinkList[Option - 1].Cost << endl;
	cout << "If Yes please enter 'Y', otherwise enter any character: ";
	cin >> Purchase;
	Purchase = toupper(Purchase);
	if (Purchase == 'Y')
	{

		//If the machine is out of the requested soda, display an appropriate “sold out” message and return all input money.
		//If it's not enough drink -> Refund -> Go to Menu
		if (DrinkList[Option - 1].Quantity == 0)
		{
			cout << "Sorry, " << DrinkList[Option - 1].DrinkName << " is sold out." << endl;
			cout << "Here is your refund: $" << Credit << endl;
		}
		else if (Credit < DrinkList[Option - 1].Cost)
		{
			cout << "Sorry, the Credit is not enough to purchase the drink." << endl;
			cout << "Here is your refund: $" << Credit << endl;
		}
		//If the machine has the soda and enough money was entered, complete the sale.
		else
		{
			DrinkList[Option - 1].Quantity -= 1;
			Credit -= DrinkList[Option - 1].Cost;
			//***
			MoneyEarned += DrinkList[Option - 1].Cost;
			//***
			cout << "Here this is your " << DrinkList[Option - 1].DrinkName << endl;
			cout << "Your change is: $" << Credit << endl;
	
		}
	}
	else
	{
		//refund
		cout << "Here is your refund: $" << Credit << endl;
	}

	
	return Credit;
}

//Initialize the price, cost, and quantity of drinks
void VendingMachine::InitDrinks() 
{
	DrinkList[0].DrinkName = "Cola";
	DrinkList[0].Cost = 1.00;
	DrinkList[0].Quantity = 20;
	DrinkList[1].DrinkName = "Root beer";
	DrinkList[1].Cost = 1.00;
	DrinkList[1].Quantity = 20;
	DrinkList[2].DrinkName = "Orange soda";
	DrinkList[2].Cost = 1.00;
	DrinkList[2].Quantity = 20;
	DrinkList[3].DrinkName = "Grape soda";
	DrinkList[3].Cost = 1.00;
	DrinkList[3].Quantity = 20;
	DrinkList[4].DrinkName = "Bottled water";
	DrinkList[4].Cost = 1.50;
	DrinkList[4].Quantity = 20;
}
//End VendingMachine class

//Main Started****************
int main()
{
	VendingMachine V1;
	int Choices = 0;
	double Credit;

	do{

		V1.Displaychoice();
		cout << "Please enter choice of drinks: " << endl;
		cin >> Choices;

		if (Choices >= 1 && Choices <= NUM_DRINKS) 
		{
			Credit = V1.BuyDrink(Choices);
		}
		else if(Choices != NUM_DRINKS + 1)
		{
			cout << "Sorry, there is no option for drinks" << endl;
		}

	} while (Choices != NUM_DRINKS + 1);
	
	cout << "Thank you for using our vending machine." << endl;

	return 0;
}
//End main

