#include<bits/stdc++.h>
using namespace std;

// printArray function to print the elements of array
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<array[i]<<" ";
    }
}

// merge function for merging the two sorted arrays into one
void merge(int array[], int low, int high, int mid)
{
    int *auxilaryArray = new int[high + 1]; // creating auxilaryArray of same size to hold the values of arrays while merging

    // dividing the given arrays into two arrays
    // i -> iterator of the first half of the array upto mid
    // j -> iterator of the second half of the array from mid + 1 to high
    // k -> iterator for the auxilaryArray
    int i = low, j = mid + 1, k = low;

    // loop untill the iterators reach their destination
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j]) // if this happens then copy the elements of 1st half of the array to auxilaryArray
        {
            auxilaryArray[k] = array[i];
            i++, k++;
        }
        else // otherwise copy the elements of the 2nd half of the array to auxilaryArray
        {
            auxilaryArray[k] = array[j];
            j++, k++;
        }
    }
    while (i <= mid) // if the elements of 1st half of the array remains then copy them to auxilaryArray
    {
        auxilaryArray[k] = array[i];
        i++, k++;
    }
    while (j <= high) // if the elements of the 2nf half of the array remains then copy them to auxilaryArray
    {
        auxilaryArray[k] = array[j];
        j++, k++;
    }

    // now revert back the sorted elements from the auxilaryArray to the original array
    for (i = low; i <= high; i++) 
    {
        array[i] = auxilaryArray[i];
    }

    // delete the auxilaryArray to free up the allocated memory
    delete[] auxilaryArray;
}

// mergeSort function -> this function helps in creating two separate sorted arrays and merge them back together using merge() function
void mergeSort(int array[], int low, int high)
{
    if (low < high) // Base condition for this recursive function
    {
        int mid = (low + high) / 2; // finding mid of the given array
        mergeSort(array, low, mid); // generating the 1st half of the sorted array 
        mergeSort(array, mid + 1, high); // generating the 2nd half of the sorted array
        merge(array, low, high, mid); // merging the above created two sorted arrays back to the original one
    }
}

int main()
{
    int a[] = {12, 18, 16, 4, 3, 79, 14};
    int length = 7;
    cout << "Array before sorting" << endl;
    printArray(a, length);
    cout << "\nArray after sorting" << endl;
    mergeSort(a, 0, length - 1);
    printArray(a, length);
    return 0;
}