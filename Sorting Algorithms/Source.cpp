/*
Programmer Name: Jittapatana Prayoonpruk

Description: This program will demonstrate the two sorting algorithims
             consist of bubble sort and selection sort with a list of 8 integers

Date:09/30/2021
*/

#include<iostream>

using namespace std;

//Fuction prototype
void swap(int* xp, int* yp);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);

int main()
{
    const int NUM_ARRAY = 8;
    int ArrayOne[NUM_ARRAY], ArrayTwo[NUM_ARRAY];


    cout << "Please enter 8 integers separate by the space: ";

    for (int i = 0; i < NUM_ARRAY; i++)
    {
        cin >> ArrayOne[i];
    }

    for (int i = 0; i < NUM_ARRAY; i++)
    {
        ArrayTwo[i] = ArrayOne[i];
    }

    /*
    for (int i = 0; i < NUM_ARRAY; i++)
    {
        cout << ArrayOne[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < NUM_ARRAY; i++)
    {
        cout << ArrayTwo[i] << " ";
    }
    */

    bubbleSort(ArrayOne, NUM_ARRAY);
    selectionSort(ArrayTwo, NUM_ARRAY);

	return 0;
}
//End main

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Bubble sort algorithm
void bubbleSort(int arr[], int n)
{
    int i, j, count = 1;
    cout << "This is The process of bubble sort algorithm: " << endl;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            cout << count << ": ";
            count++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
            for (int k = 0; k < n; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
    cout << endl << endl;
}

//Selection sort algorithm
void selectionSort(int arr[], int n)
{
    int i, j, min_idx, count = 1;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        cout << count << ": ";
        count++;
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}