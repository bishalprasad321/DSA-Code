#include <bits/stdc++.h>
using namespace std;

/*
    You have been given an array/list of ‘N’ integers. Now you are supposed to
    find the K-th largest sum of the subarray.

    Please note that a subarray is the sequence of consecutive elements of the array.
*/

int getKthLargest(vector<int> &arr, int k)
{
    // create min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    int n = arr.size();

    // algo
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (mini.size() < k)
                mini.push(sum);
            else
            {
                if (mini.top() < sum)
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }

    return mini.top();
}

int main()
{
    vector<int> arr{3, -2, 5};
    int k = 3;

    cout << "The Kth largest subarray sum is : "<<getKthLargest(arr, k) << endl;
    return 0;
}