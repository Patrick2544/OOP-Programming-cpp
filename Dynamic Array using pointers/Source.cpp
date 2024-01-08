/*
Prgrammer Name: Jittapatana Prayoonpruk

Description: This program demonstrates a dynamic array of test scores using pointer
             and will display the sorted list of scores with an average test score.

Date: 10/11/2021
*/

#include<iostream>
#include<iomanip>

using namespace std;

//Function prototype
double CheckNegative(double TestScore, int OrderStudent);
void insertionSort(double arr[], int n);
double CalcAverage(double TestScore[], int size);

int main()
{
    int Size;
    double Avg;

    cout << "Please enter the size of test scores: ";
    cin >> Size;
    while (Size <= 0)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Sorry, the Size must be greater than 0." << endl;
        cout << "Please enter the size again: ";
        cin >> Size;
    }

    //creating a dynamic array
    double* TScoreArray = new double[Size];

    for (int i = 0; i < Size; i++)
    {
        cout << "Please enter the test score of student number " << i + 1 << " : ";
        cin >> *(TScoreArray + i);
        *(TScoreArray + i) = CheckNegative(*(TScoreArray + i), i);
    }
    
    cout << fixed << showpoint << setprecision(2) << endl;

    Avg = CalcAverage(TScoreArray, Size);
    insertionSort(TScoreArray, Size);

    cout << "This is the sorted list of scores: " << endl;

    for (int i = 0; i < Size; i++)
    {
        cout << *(TScoreArray + i) << " ";
    }

    cout << endl << "The average scores: " << Avg << endl;

    //Delete the array and make it null so it will not point to any memory in the program
    //must use every time that using new (line 22)
    delete[]TScoreArray;
    TScoreArray = NULL;

    return 0;
}

//problem when cout it displays a negative number
double CheckNegative(double TestScore, int OrderStudent)
{
    while (TestScore < 0)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Sorry, the test score cannot be nagative number." << endl;
        cout << "Please enter the test score of student number " << OrderStudent + 1 << " again: ";
        cin >> TestScore;
    }
    return TestScore;
}

void insertionSort(double arr[], int n)
{
    int i, j;
    double key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

double CalcAverage(double TestScore[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(TestScore + i);
    }
    return sum / size;
}