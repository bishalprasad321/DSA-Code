#include<bits/stdc++.h>
using namespace std;

/*
    There are given N ropes of different lengths, we need to connect these ropes 
    into one rope. The cost to connect two ropes is equal to sum of their lengths. 
    The task is to connect the ropes with minimum cost.

    - [4, 3, 2, 6]  (meging two minimum rope length each time)
    - [4, 6, 5]  
    - [6, 9]
    - [15]
`   
    minimum cost = 5 + 9 + 15 = 29

    Approach --------

    step 1 : build min heap with given array
    step 2 : while the array size > 1 
            - a = arr.top()
            - arr.pop()
            - b = arr.pop()
            - sum = a + b
            - cost = cost + sum
    step 3 : return the cost
*/

long long minCostRopes(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long> > pq;

    // step 1 : build min heap with given array
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    long long cost = 0;
    
    // step 2 :
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a + b;

        cost += sum;

        pq.push(sum);
    }
    return cost;
}

int main()
{
    long long arr[] = {4, 3, 2, 6};
    cout << "Minimum cost as per the given length of the ropes will be : " << minCostRopes(arr, 4) << endl;
    return 0;
}