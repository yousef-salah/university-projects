/**
* Median Calculator.
*
* @file DaynamicMemoryAllocation.cpp
* @author Yousef Salah Khodroj
* @version 1.1
*/


#include <iostream>

using namespace std;

double median(const int array[], int size);

int minimumValueIndex(int array[], int start, int finish);

bool isEven(int number);
void copyTwoArrays(const int array[], int copy[], int size);
void sort(int array[], int size);
void swap(int& first, int& second);
void insertData(int array[], int size);



int main()
{
    unsigned size = 0;
    cout << "Enter the size of array: ", cin >> size;
    
    int* const array = new int[size];

    insertData(array, size);

    cout << median(array, size) << endl;

    return 0;
}

/**
* find the median value in spacified Array.
* 
* @param const int * | const int[]
* @param int array size.
* 
* @return double (median value)
*/
double median(const int array[], int size)
{
    int* const copy = new int[size];
    double value = 0;

    copyTwoArrays(array, copy ,size);

    sort(copy, size);               // sort Array using selection sort Algorithm
    
    if (isEven(size)) {            // Check if number of elements is even or odd.
        int index = size / 2;
        value = (double)copy[index] + (double)copy[index - 1];
        value /= 2;
    }
    else if(size == 1) {            // check if Array has just one element.
        value = copy[0];
    }
    else {
        int index = size / 2;
        value = copy[index];
    }
    
    delete[]copy;                 // Delete Daynamic memory.

    return value;
}
/**
* copy first array values to the second array.
* 
* @param const int * | const int[]  The original Array.
* @param const int * | const int[]  The Copied Array.
* @param int size.
* 
* @return void.
*/
void copyTwoArrays(const int array[], int copy[], int size)
{
    for (int row = 0; row < size; row++)
    {
        copy[row] = array[row];
    }
}


/**
* sort array of integer Ascending.
* 
* @param const int * | const int[].
* @param int size.
* 
* @return void.
*/
void sort(int array[], int size)
{
    int minIndex = 0;
    for (int counter = 0; counter < size; counter++)
    {
        minIndex = minimumValueIndex(array, counter, size);

        if (minIndex != counter) {
            swap(array[minIndex], array[counter]);
        }
    }
}

/**
* find the index of minimum value in spacified Array.
* 
* @param int * | int[].
* @param int start index.
* @param int finish index.
* 
* @return int the minimum value index.
*/
int minimumValueIndex(int array[], int start, int finish)
{
    int minIndex = start;
    
    start++;

    for (; start < finish; start++)
    {
        if (array[minIndex] > array[start])
        {
            minIndex = start;
        }
    }

    return minIndex;
}

/**
* swap two values.
* 
* @param int & first value.
* @param int & second value.
* 
* @return void.
*/
void swap(int& first, int& second)
{
    int temp = second;
    second = first;
    first = temp;
}

/**
* @param int * | int[].
* @param int size.
* 
* @return void.
*/
void insertData(int array[], int size)
{
    for (int counter = 0; counter < size; counter++)
    {
        cout << "Enter Number No. " << counter + 1 << " : ", cin >> array[counter];
    }
}

/**
* Check if the number is even or not.
* 
* @param int number.
* 
* @return bool.
*/
bool isEven(int number)
{
    if (number % 2 == 0) return true;

    return false;
}