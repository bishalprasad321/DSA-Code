#include<bits/stdc++.h>
using namespace std;

// printArray function to print the elements of array
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

// bubbleSort function
void bubbleSort(int array[], int length)
{
    for (int i = 1; i < length; i++) // Bubble sort will push the sorted elements to the end of the array, just like a bubble in water pops out
    {
        for (int j = 0; j < length-i; j++)
        {
            if (array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {12,18,16,4,3,79,14};
    int length = 7;
    cout<<"Array before sorting"<<endl;
    printArray(a, length);
    cout<<"\nArray after sorting"<<endl;
    bubbleSort(a, length);
    printArray(a, length);
    return 0;
}