#include<bits/stdc++.h>
using namespace std;

/*
    Reversing an array can be done by two methods :

    Method 1 : Using extra space (auxiliary array with same length of original one)
    -> Store the elements of the original array in the reverse order in that of auxilaryArray.
    -> Copy back the elements from the auxilaryArray to the original array.

    Time Complexity -> O(N) | Space Complexity -> O(N)

    Method 2 : Using two pointer approach and swaping the elements.
    -> Traverse two pointers, one from the starting index and another from the ending index of the array.
    -> Swap the elements currently stored at the both pointers.

    Time Complexity -> O(N) Space Complexity -> O(1)
*/

void reverseFun01(vector<int>& array)
{
    int length = array.size(); 
    int* auxilaryArray = new int[length]; // dynamically creating an array in heap
    for (int i = length - 1, j = 0; i >= 0, j < length; i--, j++) // looping in reverse order to store the elements in reverse order
    {
        auxilaryArray[j] = array[i]; 
    }

    // copying back the elements of the stored auxiliary array to original one
    for (int i = 0; i < length; i++)
        array[i] = auxilaryArray[i];
    
    delete []auxilaryArray; // deleting the unwanted auxiliary array
}

void reverseFun02(vector<int>& array)
{
    int i = 0; // first pointer
    int j = array.size() - 1; // second pointer 
    while (i <= j) // loop until first pointer becomnes equal to the second pointer
    {
        swap(array[i++], array[j--]); //swaping the elements using STL
    }
}

int main()
{
    vector<int> array;s
    int length;
    cout<<"Enter the length of the array : ";
    cin>>length;

    cout<<"Enter the elements of the array : "<<endl;
    for (int i=0; i<length; i++)
    {
        int ele;
        cin>>ele;
        array.push_back(ele);
    }
    cout<<"Do you want to use extra space to reverse the array? (press y/n) : ";
    char choice;
    cin>>choice;

    cout<<"Before reversing the array : ";
    for (int i=0; i<array.size(); i++)
        cout<<array[i]<<" ";
    cout<<endl;

    if (choice == 'y' || choice == 'Y')
        reverseFun01(array);
    else
        reverseFun02(array);
    cout<<"After reversing the array : ";
    for (int i=0; i<array.size(); i++)
        cout<<array[i]<<" ";
    cout<<endl;

    return 0;
}