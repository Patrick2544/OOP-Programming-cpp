/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will take the text file and transform in 3 different files
             including Unchanged Copy File, Uppercase Letter File, and Encryption File.
			 For the Encryption file, user can determine it own key regarding to this encryption algorithm.

Date:11/17/2021
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class AbsFilter
{
	public:
		AbsFilter()
		{
			//cout << "Calling default AbsFilter constructor\n";
		}
		
		virtual char transform(char ch) = 0;
		void doFilter(ifstream& in, ofstream& out);
};

class Encrypt :public AbsFilter
{
	private:
		int key;
	public:
		Encrypt()
		{
			key = 1;
		}
		Encrypt(int k) 
		{
			key = k;
		}
		virtual char transform(char ch);
};

class UpperCase :public AbsFilter
{
	public:
		virtual char transform(char ch);
};

class UnchangedCopy :public AbsFilter
{
	public:
		virtual char transform(char ch);
};

void AbsFilter::doFilter(ifstream& in, ofstream& out)
{
	char ch;

	in.get(ch);

	while (!(in.eof()))
	{
		out << transform(ch);
		in.get(ch);
	}
}

char Encrypt::transform(char ch)
{
	ch = ((ch * key * key) - 15) * 3 + (108/key) % 128;
	return ch;
}

char UpperCase::transform(char ch)
{
	return toupper(ch);
}

char UnchangedCopy::transform(char ch)
{
	return ch;
}

int main()
{
	ifstream InputFile;				//cin  write
	ofstream OutputFile;			//cout read
	string InputName, OutputName;
	char DetermineKey;
	int Key;

	cout << "Please enter the name of the file you would like to do a filter: ";
	cin >> InputName;

	InputFile.open(InputName);

	if (!InputFile)
	{
		cout << "Sorry the file " << InputName << " cannot open, terminating program." << endl;
		exit(1);
	}

	cout << "Please enter the name of the file for the unchanged copy file: ";
	cin >> OutputName;

	OutputFile.open(OutputName);

	if (!OutputFile)
	{
		cout << "Sorry the file" << OutputName << " cannot open, terminating program. " << endl;
		exit(1);
	}

	AbsFilter* AS1 = new UnchangedCopy();

	AS1->doFilter(InputFile, OutputFile);

	OutputFile.close();
	InputFile.close();

	InputFile.open(InputName);

	if (!InputFile)
	{
		cout << "Sorry the file " << InputName << " cannot open, terminating program." << endl;
		exit(1);
	}

	cout << "Please enter the name of the file for the UpperCase file: ";
	cin >> OutputName;

	OutputFile.open(OutputName);

	if (!OutputFile)
	{
		cout << "Sorry the file" << OutputName << " cannot open, terminating program. " << endl;
		exit(1);
	}

	AbsFilter* AS2 = new UpperCase();

	AS2->doFilter(InputFile, OutputFile);

	OutputFile.close();
	InputFile.close();

	InputFile.open(InputName);

	if (!InputFile)
	{
		cout << "Sorry the file " << InputName << " cannot open, terminating program." << endl;
		exit(1);
	}

	cout << "Next step is creating an encryption file. Do you want to determine your own key for this encryption algorithm." << endl;
	cout << "If yes, please enter 'Y'. Otherwise please enter any character." << endl;
	cin >> DetermineKey;

	DetermineKey = toupper(DetermineKey);

	if (DetermineKey == 'Y')
	{
		cout << "Please enter a number you would like to be your key: ";
		cin >> Key;

		cout << "Please enter the name of the file for the encryption file: ";
		cin >> OutputName;

		OutputFile.open(OutputName);

		if (!OutputFile)
		{
			cout << "Sorry the file" << OutputName << " cannot open, terminating program. " << endl;
			exit(1);
		}

		AbsFilter* AS3 = new Encrypt(Key);

		AS3->doFilter(InputFile, OutputFile);

		OutputFile.close();
	}
	else
	{
		cout << "Please enter the name of the file for the encryption file: ";
		cin >> OutputName;

		OutputFile.open(OutputName);

		if (!OutputFile)
		{
			cout << "Sorry the file" << OutputName << " cannot open, terminating program. " << endl;
			exit(1);
		}

		AbsFilter* AS3 = new Encrypt();

		AS3->doFilter(InputFile, OutputFile);

		OutputFile.close();
	}
	

	
	InputFile.close();
	

	return 0;
}