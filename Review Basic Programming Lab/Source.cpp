/*
Programmer Name: Jittapatana Prayoonpruk

Description: This is a salary calulation program.
             It will calculate the salary you get for each week with maximum of 5 weeks, and etc.
			 The calculation respect with the rate per hours you get paid.

Date: 09/06/2021
*/

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int NumHr, Week = 1, SumHr = 0;
	float PayRate, BeforeTaxIn, AfterTaxIn, SpendClothes, SpendSupplies, SpendBond, SpendParent;
	const float Tax = 0.86; //Taxes is 14 %
	const float ClothesAccessoies = 0.10, SchoolSuppies = 0.01, SaveBond = 0.25, AddParents = 0.50;
	bool Again = true;

	//Input
	do
	{
		cout << "Please enter the pay rate for an hour: ";
		cin >> PayRate;
		//PayRate Input Validation************
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "\nSorry, the input for the pay rate is impossible.\nPlease enter the pay rate for an hour again: ";
			cin >> PayRate;
		}
		if (PayRate <= 0)
		{
			cout << "\nThe pay rate must be greater than zero." << endl;
		}
		//*****************************
	} while (PayRate <= 0);

	cout << "Your pay rate is: $" << fixed << showpoint << setprecision(2) << PayRate << " per hour." << endl << endl;

	//Loop for week 1 through week 5.
	while (Again)
	{
		do
		{
			cout << "Please enter the number of hours worked for week " << Week << ": ";
			cin >> NumHr;
			// NumHr Input Validation************
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(200, '\n');
				cout << "\nSorry, the number of hours is impossible.\nPlease enter the number of hours worked for week " << Week << " again: ";
				cin >> NumHr;
			}
			if (NumHr <= 0)
			{
				cout << "\nThe number of hours worked must be greater than zero." << endl;
			}
			//********************************
		} while (NumHr <= 0);

		cout << "\nFor week " << Week << ", You have worked " << NumHr << " hours." << endl << endl;

		//condition loop
		if (Week < 5)
		{
			Week++;
		}
		else
		{
			Again = false;
		}
		SumHr += NumHr;
	}
		//End Input

		//Calculation part****************************************
		BeforeTaxIn = SumHr * PayRate;									//Total Income Before Taxes (a1)
		AfterTaxIn = BeforeTaxIn * Tax;									//Total Income After Taxed  (a2)
		SpendClothes = AfterTaxIn * ClothesAccessoies;					//Total Spend on Clothes    (b)
		SpendSupplies = AfterTaxIn * SchoolSuppies;						//Total Spend on Supplies   (c)
		SpendBond = AfterTaxIn - (SpendClothes + SpendSupplies);
		SpendBond *= SaveBond;											//Total Save on Bond        (d)
		SpendParent = static_cast<int>(SpendBond) * AddParents;			//Total Parent Added        (e)
		//**********************************************************

		//Output
		cout << "For the total of 5 weeks you have worked:   " << SumHr << " hours" << endl;
		cout << fixed << showpoint << setprecision(2);
		cout << "Income before taxes:                        $" << BeforeTaxIn << endl;
		cout << "Income After taxes:                         $" << AfterTaxIn << endl;
		cout << "Money spending on clothes and accessories:  $" << SpendClothes << endl;
		cout << "Money spending on school and supplies:      $" << SpendSupplies << endl;
		cout << "Money spending on saving bond:              $" << SpendBond << endl;
		cout << "Parent additional money:                    $" << SpendParent << endl << endl;
		//End Output

		return 0;
	
}
//End main*******************************************
