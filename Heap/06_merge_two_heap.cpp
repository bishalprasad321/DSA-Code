#include<bits/stdc++.h>
using namespace std;

/*
    Merge two max heap ---------

    Algo - it is same as the working of merging two BST's

    step 1 : Store both the max heap into two vectors
    step 2 : Merge both the vectors into an another vector, using heapify method

    T.C -> O(m+n)
    S.C -> O(m+n)
*/

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n and arr[largest] < arr[left])
        largest = left;

    if (right < n and arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeap(vector<int> &a, vector<int> &b, int m, int n)
{
    vector<int> merged;
    // step 1 : 
    for (auto i : a)
        merged.push_back(i);
    for (auto i : b)
        merged.push_back(i);

    // step 2 : 
    int size = merged.size();
    for (int i = size/2 - 1; i >= 0; i--)
        heapify(merged, size, i);

    return merged;

}

int main()
{
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> ans = mergeHeap(a, b, a.size(), b.size());

    cout <<"After merging the given max heaps...."<<endl;

    for (auto i : ans)
        cout << i << " ";

    cout << endl;
    
    return 0;
}