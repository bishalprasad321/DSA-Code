#include <bits/stdc++.h>
using namespace std;

// printArray function to print the elements of the array
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[low]; // assume the pivot to be the first element of the array
    int temp; // temporary varaible to store the value of element while swapping

    int i = low + 1; // iterator with index one after the pivot
    int j = high; // iterator with index = high

    do // do this loop at least once 
    {
        // loop the iterator i until element array[i] >= pivot
        while (array[i] <= pivot)
        {
            i++;
        }

        // loop the iterator j until element array[j] <= pivot
        while (array[j] >= pivot)
        {
            j--;
        }

        // if the iterator i is still less than iterator j, then swap the elements at those index
        if (i < j)
        {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    } while (i < j); // loop until the value of i remains less than j

    // after the loop, j <= i (j will become less than or equal to i)
    // swap the elements at the pivot and the index j.
    temp = array[low];
    array[low] = array[j];
    array[j] = temp;

    // return the new pivot index (which is currently swapped with j)
    return j;
}

void quickSort(int array[], int low, int high)
{
    if (low < high) // set the terminating condition of recursion
    {
        // 
        int partitionIndex = partition(array, low, high);
        // Quick Sort in Left Sub Array
        quickSort(array, low, partitionIndex - 1);
        // Quick Sort in right Sub Array
        quickSort(array, partitionIndex + 1, high);
    }
}

int main()
{
    int a[] = {12, 18, 16, 4, 3, 79, 14};
    int length = 7;
    cout << "Array before sorting" << endl;
    printArray(a, length);
    cout << "\nArray after sorting" << endl;
    quickSort(a, 0, length - 1);
    printArray(a, length);
    return 0;
}