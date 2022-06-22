#include <bits/stdc++.h>
using namespace std;

/*
    *Algorithm* -------
    step 1 : create a max heap for only k elements
    step 2 : use the following operation for all n - k elements
            - if (element < arr.top())
            - arr.pop(), then arr.push(element)
    step 3 : return the arr.top() -----
*/

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;

    // step 1:
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step 2:
    for (int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step 3:
    return pq.top();
}

int main()
{
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int l = 0;
    int r = 5;

    int k;

    cout << "Enter the value of k : ";

    cin >> k;

    cout << "Kth smallest element of the given array is : "<< kthSmallest(arr, l, r, k) <<endl;

    return 0;
}