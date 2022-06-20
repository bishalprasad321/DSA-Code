#include<bits/stdc++.h>
using namespace std;

// printArray function to print the elements of the array
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<array[i]<<" ";
    }
}

// selectionSort function 
void selectionSort(int array[], int length)
{
    for (int i = 0; i < length-1; i++) // loop iterator 'i' upto length - 1 (assuming the last element to be sorted)
    {
        for (int j = i+1; j < length; j++) // loop iterator 'j' from i+1 to length
        {
            if (array[j] < array[i]) // if this happens then swap the elements in their selected positions
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

//  12 18 16 04 03 79 | 14
//  04 18 16 12 03 79 | 14
//  03 18 16 12 04 79 | 14 -> after 1st pass (i=0)

//  03 18 16 12 04 79 | 14
//  03 16 18 12 04 79 | 14
//  03 12 18 16 04 79 | 14
//  03 04 18 16 12 79 | 14 -> after 2nd pass (i=1)

//  03 04 18 16 12 79 | 14
//  03 04 16 18 12 79 | 14 
//  03 04 12 18 16 79 | 14 -> after 3rd pass (i=2)

// 03 04 12 18 16 79 | 14
// 03 04 12 16 18 79 | 14
// 03 04 12 14 18 79 | 16 -> after 4th pass (i=3)

// 03 04 12 14 18 79 | 16
// 03 04 12 14 16 79 | 18 -> after 5th pass (i=4)

// 03 04 12 14 16 79 | 18 
// 03 04 12 14 16 18 | 79 -> after 6th pass (i=5)

int main()
{
    int a[] = {12,18,16,4,3,79,14};
    int length = 7;
    cout<<"Array before sorting"<<endl;
    printArray(a, length);
    cout<<"\nArray after sorting"<<endl;
    selectionSort(a, length);
    // printArray(a, length);
    return 0;
}