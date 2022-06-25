#include<bits/stdc++.h>
using namespace std;

/*
    You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is 
    sorted in non-decreasing order. You need to find the minimum length of a range such that 
    at least one element of each list must be included in that range.
*/

class node // custom class 
{
    public:
        int data;
        int row;
        int col;

        node(int data, int row, int col);
};

// Constructor
node :: node(int data, int row, int col)
{
    this->data = data;
    this->row = row;
    this->col = col;
}

class compare // custom class for min heap comparison
{
    public:
        bool operator()(node *a, node *b)
        {
            return a->data > b->data;
        }
};

// driver function
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    for (int i = 0; i < k; i++) // storing the 1st element of every sorted array
    {
        int element = a[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new node(element, i, 0));
    }
    
    int start = mini, end = maxi;
    
    while (!minHeap.empty()) // loop untill minheap or any one of the array is exhausted
    {
        node *tmp = minHeap.top();
        minHeap.pop();
        
        mini = tmp->data; // updating mini
        
        if (maxi - mini < end - start) // condition for new smallest range 
        {
            start = mini;
            end = maxi;
        }
        
        if (tmp->col + 1 < n) // checking for the possibility of next range, if present push into the heap
        {
            maxi = max(maxi, a[tmp->row][tmp->col + 1]); // updating maxi
            minHeap.push(new node(a[tmp->row][tmp->col + 1], tmp->row, tmp->col + 1));
        }
        else // no next element --- loop terminating condition
        {
            break;
        }
    }
    return (end - start + 1); // returning the desired smallest range 
}

int main()
{
    vector<vector<int>> kSortedArray{{1, 10, 11}, {2, 3, 20}, {5, 6, 12}};

    cout << "Smallest range of the given K Sorted Array/Lists is : " << kSorted(kSortedArray, 3, 3) << endl;

    return 0;
}