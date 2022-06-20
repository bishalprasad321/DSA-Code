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

// insertionSort function
void insertionSort(int array[], int length)
{
    for (int i = 1; i < length; i++) // assuming the first element of the array to be sorted
    {
        int key = array[i]; // defining 'key' to be inserted into it's right position 
        int j = i-1; // iterator 'j' will check the element at that index to be in their desired position
        while (array[j]>key && j >= 0) // loop until the element at jth index is greater than key
        {
            array[j+1] = array[j]; // assign the (j+1)th index with jth index value
            j--; // decrement the value of 'j' to check the previous element
        }
        array[j+1] = key; // assign the value of key to the element at (j+1)th index
    }
}

int main()
{
    int a[] = {12,18,16,4,3,79,14};
    int length = 7;
    cout<<"Array before sorting"<<endl;
    printArray(a, length);
    cout<<"\nArray after sorting"<<endl;
    insertionSort(a, length);
    printArray(a, length);
    return 0;
}