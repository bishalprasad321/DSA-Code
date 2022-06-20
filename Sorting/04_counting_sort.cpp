#include<bits/stdc++.h>
using namespace std;

// printArray function to print the elements of the array.
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<array[i]<<" ";
    }
    
}

// maxElement function -> to find the maximum element in the given array.
int maxElement(int array[], int length)
{
    // intializing maxELe with the minimum integer value in c++.
    int maxEle = INT_MIN;

    for (int i = 0; i < length; i++)
    {
        if (array[i] > maxEle)
        {
            maxEle = array[i];
        }
    }
    return maxEle;
}

// count sort algorithm function
void countingSort(int array[], int length)
{
    int maxEle = maxElement(array, length);

    // creating an array in the HEAP of size = maxEle
    int *indexArray = new int[maxEle];

    // intializing the indexArray with 0
    for (int i = 0; i < maxEle; i++)
    {
        indexArray[i] = 0;
    }

    // incrementing the value at array[i] of the indexArray by 1 each time
    for (int i = 0; i < length; i++)
    {
        indexArray[array[i]] = indexArray[array[i]] + 1;
    }
    
    // i = iterator for indexArray 
    // j = iterator for given array
    int i = 0,j = 0;
    while (i <= maxEle && j < length)
    {
        if (indexArray[i] > 0)
        {
            array[j] = i;
            // now decrement the value at ith index of indexArray by 1 (this is for repeated elements)
            indexArray[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    // deleting the indexArray to free up the allocated space in the memory for it
    delete[] indexArray;
}

int main()
{
    int a[] = {12,18,16,4,3,79,14};
    int length = 7;
    cout<<"Array before sorting"<<endl;
    printArray(a, length);
    cout<<"\nArray after sorting"<<endl;
    countingSort(a, length);
    printArray(a, length);
    return 0;
}