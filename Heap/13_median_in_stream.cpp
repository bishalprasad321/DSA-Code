#include<bits/stdc++.h>
using namespace std;

/*
    Given that integers are read from a data stream. Your task is to find the median of the elements read so far.
    
    Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. 
    So the median is the floor of the average of the two middle values.


    input values ---------
    3
    1 2 3
    2 
    9 9
    1
    4

    Desired Output -------
    1 1 2
    9
    4
*/

int signum(int a, int b)
{
    // case 0
    if (a == b) 
        return 0;

    // case 1
    else if (a > b)
        return 1;

    // case -1
    else
        return -1;
}

void findMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    switch(signum(maxi.size(), mini.size()))
    {
        case 0: 
            if (element > median)
            {
                // n-1(maxHeap) |median| n(minHeap)
                mini.push(element); // n | median | n
                median = mini.top(); // minHeap.top() is the median
            }
            else
            {
                // n(maxHeap) |median| n-1(minHeap)
                maxi.push(element); // n |median| n
                median = maxi.top(); // maxHeap.top() is the median
            }
            break;
        case 1:
            if (element > median)
            {
                // n(maXheap) | median | n(minHeap)
                mini.push(element); // n+1 | median | n
                median = (mini.top() + maxi.top()) / 2; // median is the average of minHeap.top() and maxHeap.top()
            }
            else
            {
                // n | median | n-1
                mini.push(maxi.top()); //  n | median | n
                maxi.pop(); // n-1 | median | n
                maxi.push(element); // n | median | n
                median = (mini.top() + maxi.top()) / 2; // median is the average 
            }
            break;
        case -1:
            if (element > median)
            {
                // n-1 | median | n
                maxi.push(mini.top()); // n | median | n
                mini.pop(); // n | median | n-1
                mini.push(element); // n | median | n
                median = (mini.top() + maxi.top()) / 2; // median is the average
            }
            else
            {
                // n | median | n
                maxi.push(element); // n+1 | median | n
                median = (mini.top() + maxi.top()) / 2; // median is the average
            }
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    
	priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    
    int median = 0; // intialiszing median with 0
    
    for (int i = 0; i < n; i++)
    {
        findMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    
    return ans;
}

int main()
{
    int testCase = 3;
    vector<int> ans;
    for (int i = 0; i < testCase; i++)
    {
        int n;
        cout << "Enter the number of elements of the data stream : ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the data stream"<<endl;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        ans = findMedian(arr, n);
        cout << "Following are the medians of the given data streams"<<endl;

        for (int i : ans)
            cout << i << " ";
        
        cout << endl;
    }

    return 0;
}