/*
Prgrammer Name: Jittapatana Prayoonpruk

Description: This program will read the text in the input file
             and make the text to be upper letter for the first letter of each sentence
			 and other than that make them to be a lower case. Then, output it in the output file.

Date: 10/26/2021
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream InData;  //works like cin
	ofstream OutData; //works like cout
	string Text;
	int CountSpace = 1;

	InData.open("InputFile.txt");
	if (!InData)
	{
		cout << "Cannot open the file, terminating program." << endl;
		exit(1);
	}

	OutData.open("OutputFile.txt");

	while (!(InData.eof()))
	{
		getline(InData, Text);

		for (int i = 0; i < Text.size(); i++)
		{
			//The First letter is always upper case.
			if (i == 0 && Text[i] >= 97 && Text[i] <= 122)
			{
				Text[i] -= 32;
			}
			//The process of making the first letter after the period to be an upper case.
			else if (Text[i] == 46 && Text[i + 1] != NULL) //ASCII CODE 46 is a period
			{
				//count the space after the period if any
				while (Text[i + CountSpace] == 32)
				{
					CountSpace++;
				}
				//The first letter after the period is the target, and now change it ot upper case.
				if (Text[i + CountSpace] >= 97 && Text[i + CountSpace] <= 122)
				{
					Text[i + CountSpace] -= 32;
					i += CountSpace;
				}
			}
			else if (i != 0 && Text[i] >= 65 && Text[i] <= 90) //other letter should be lower case
			{
				Text[i] += 32;
			}
		}

		OutData << Text << endl;
	}

	InData.close();
	OutData.close();
	return 0;
}