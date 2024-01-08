/*
Programmer Name: Jittapatana Prayoonpruk

Description: This is a simple linked list program, and it will show how to insert the number into 
             the linked list in a specific position.

Date:12/10/2021
*/

#include<iostream>

using namespace std;

class LinkedList
{
	protected:
		struct ListNode
		{
			double Value;
			ListNode* Next;
			ListNode(double ValueOne, ListNode* NextOne = NULL)
			{
				Value = ValueOne;
				Next = NextOne;
			}
		};

		ListNode* Head;

	public:
		int length;
		LinkedList() { Head = NULL; length = 0; }
		void PrintList();
		void add(double x);
		
		bool isMember(double x);
		void insert(double x, int pos);
		void remove(int pos);
};

void LinkedList::add(double x)
{
	if (Head == NULL)
	{
		Head = new ListNode(x);
	}
	else
	{
		ListNode* Nodeptr = Head;
		while (Nodeptr->Next != NULL)
		{
			Nodeptr = Nodeptr->Next;
		}

		//Create a new node and put it after the last node
		Nodeptr->Next = new ListNode(x);
		
	}
	length++;
}

void LinkedList::PrintList()
{
	ListNode* N = Head;
	while (N != NULL)
	{
		cout << N->Value << endl;
		N = N->Next;
	}
}

bool LinkedList::isMember(double x)
{
	ListNode* Nodeptr = Head;
	while (Nodeptr != NULL)
	{
		if (Nodeptr->Value == x)
		{
			return true;
		}
		else
		{
			Nodeptr->Next;
		}
	}

	return false;
}

void LinkedList::insert(double x, int pos)
{
	if (pos < 0)
	{
		cout << "Sorry, the position is invalid." << endl;
	}
	else
	{
		ListNode* Nodeptr = new ListNode(x);
		ListNode* ptr = Head;

		//insert for the empty linked list
		if (Head == NULL)
		{
			Head = new ListNode(x);
		}
		//insert at the beginning
		else if (pos == 0)
		{
			Nodeptr->Next = Head;
			Head = Nodeptr;
		}
		//insert at pos
		else
		{
			for (int i = 0; i < pos - 1 && ptr->Next != NULL; i++) 
			{
				ptr = ptr->Next;
			}
			Nodeptr->Next = ptr->Next;
			ptr->Next = Nodeptr;
		}
		length++;
	}
}


void LinkedList::remove(int pos)
{
	if (Head == NULL)
	{
		cout << "The list is empty." << endl;
	}
	// remove the first one
	else if (pos == 0)
	{
		ListNode* Temp = Head;
		Head = Head->Next;

		delete(Temp);
		length--;
	}
	//remove at pos
	else if (pos < length)
	{
		ListNode* ptr = Head;

		for (int i = 0; i < pos - 1; i++)
		{
			ptr = ptr->Next;
		}
		ListNode* Temp = ptr->Next;
		ptr->Next = Temp->Next;
		delete(Temp);
		length--;
	}
	else
	{
		cout << "Invalid position for removal\n";
	}

}

int main()
{
	LinkedList LL1;
	int Size, SizeInsert, Pos;
	double Num;

	cout << "This program demonstrates a simple linked list." << endl;

	cout << "First, please input the size of your original number: ";
	cin >> Size;

	cout << "Please input your number to create an original linked list (seperate them by using a space): ";

	while (Size > 0)
	{
		cin >> Num;
		LL1.add(Num);
		Size--;
	}
	
	cout << "This is the original linked list: " << endl;
	LL1.PrintList();

	cout << "Next step is to demonstrate inserting a linked list at the specific position." << endl;
	
	cout << "Please input how many number you would like to insert: " << endl;
	cin >> SizeInsert;

	while (SizeInsert > 0)
	{
		cout << "Please input the number and the position (seperate them by using space, **the first position strat with position 0**): ";
		cin >> Num >> Pos;
		LL1.insert(Num, Pos);
		cout << "This is the linked list after insert " << Num << " at the position " << Pos << " (**The first position start with position 0**):" << endl;
		LL1.PrintList();
		SizeInsert--;
	}


	return 0;
}

