#include<bits/stdc++.h>
using namespace std;

/*
    linear search is advised to be implemented when the array is not in the sorted manner.

    Time Complexity -> O(n) 
    Space Complexity -> O(1)
*/

int linearSearch(vector<int> &array, int key)
{
    for (int i = 0; i < array.size(); i++) // traversing the whole array to check whether the current element at this particular index = key.
    {
        if (array[i] == key)
            return i; // if element at this index is found, then return the index.
    }
    return -1; // if element not found, then return -1.
}

int main()
{
    vector<int> search;
    int size, key_element;
    cout<<"Enter the length of the array : ";
    cin>>size;
    cout<<"Enter the elements of the array : "<<endl;
    for (int i = 0; i < size; i++)
    {
        int ele;
        cin>>ele;
        search.push_back(ele);
    }
    cout<<"Enter the element, you want to search : ";
    cin>>key_element;
    int index = linearSearch(search, key_element);
    if (index == -1)
        cout<<"Element not found in the provided array!!"<<endl;
    else
    {
        cout<<"Element "<<key_element<<" found at index "<<index<<endl;
    }
    return 0;
}