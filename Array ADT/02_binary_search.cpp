#include<bits/stdc++.h>
using namespace std;

/*
    Binary Search is an algorithm, for which the pre-requisite is that the array must be sorted either in ascending or descending order.

    Time Complexity -> O(log(n))
    Space Complexity -> O(1)

    ----------------------------------------------------------------
    Below are two algorithms based on the same technique to find the element in an sorted array.
    1. 1st one is for ascending order
    2. 2nd one is for descending order
*/

int binarySearchAscending(vector<int>& array, int keyElement) // binarySearh for an array sorted in ascending order.
{
    int start = 0; // intial starting point of searc
    int end = array.size() - 1; // final ending point of search
    int mid = start + (end - start) / 2; // each time dividing the array into two halves to reduce the length of traversal of the algorithm.
    while (start <= end) // loop goes untill start pointer reaches the end point.
    {
        if (array[mid] == keyElement) // return the mid index, if the element is found in that position.
            return mid;
        else if (array[mid] < keyElement) // if element is greater than current mid element, then move the start pointer beyond the current mid index and search in the right most part of array. 
            start = mid + 1;
        else // if element is smaller than current mid element, then bring back the end pointer the current mid index, and search element in in the left most part of array.
            end = mid - 1;
        mid = start + (end - start) / 2; // each time executing loop, update the mid index for the reduced length of the array.
    }
    return -1; // if element not found then return -1
}

int binarySearchDescending(vector<int>& array, int keyElement)
{
    int start = 0;
    int end = array.size() - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (array[mid] == keyElement) // Return the mid index, if element is found.
            return mid;
        else if (array[mid] > keyElement) // update the start pointer to beyond the current mid index to search in the rightmost part.
            start = mid + 1;
        else // update the end pointer to below the mid index to search in the left most part of the array.
            end = mid - 1;
        mid = start + (end - start) / 2; // update the mid index.
    }
    return -1; // if element not found
}

bool isDescending(vector<int>& array) // function to check the order of array is descending or not.
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] < array[i+1]) 
            return false;
    }
    return true;
}

int main()
{
    vector<int> array;
    int length, key;
    cout<<"Enter the size of the array : ";
    cin>>length;
    cout<<"Enter the elements of the array : "<<endl;
    for (int i = 0; i < length; i++)
    {
        int element;
        cin>>element;
        array.push_back(element);
    }
    cout<<"Enter the key element, you want to find in the array : ";
    cin>>key;
    if (isDescending(array))
    {
        int index = binarySearchDescending(array, key);
        if (index == -1)
            cout<<"Element not found in the given array!!"<<endl;
        else
            cout<<"Element "<<key<<" found at index "<<index<<endl;
    }
    else
    {
        int index = binarySearchAscending(array, key);
        if (index == -1)
            cout<<"Element not found in the given array"<<endl;
        else
            cout<<"Element "<<key<<" found at index "<<index<<endl;
    }
    return 0;
}