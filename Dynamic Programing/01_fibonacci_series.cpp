#include<bits/stdc++.h>
using namespace std;

/*
    There are three ways of Dynamic Programming 
    - Top-Down Approach (Recursion + Memoization)
    - Bottom-Up Approach (Tabulation)
    - Space optimized
*/

int fibonacci_topDown(int n, vector<int> &dp1)
{
    // base case
    if (n <= 1)
        return n;

    // memoization concept
    if (dp1[n] != -1) 
        return dp1[n];

    dp1[n] = fibonacci_topDown(n-1, dp1) + fibonacci_topDown(n-2, dp1);
    return dp1[n];
}

int fibonacci_bottomUp(int n, vector<int> &dp2)
{
    dp2[0] = 0; // intializing the first term of fibonacci
    dp2[1] = 1; // intializing the second term of fiboancci

    for (int i = 2; i <= n; i++) // looping from the third term until the nth term
    {
        dp2[i] = dp2[i-1] + dp2[i-2]; // storing the sum of pervious two values at the current value
    }

    return dp2[n];
}

int fibonacci_spaceOptimized(int n)
{
    int prev1 = 1;
    int prev2 = 0;
    int curr;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;  // updating the current pointer
        prev2 = prev1; // updating the previous pointer to move through the fibonacci sequence
        prev1 = curr; // updating the previous pointer to move through the fibonacci sequence 
    }
    return prev1; // the nth term of fibonacci will be stored at the current pointer
}

int main()
{
    int n;
    cout << "Enter the nth number to find the nth Term of fibonacci sequence : ";
    cin >> n;

    vector<int> dp1(n + 1), dp2(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp1[i] = -1;
        dp2[i] = -1;
    }

    cout << "Output with Top Down Approach : "<<fibonacci_topDown(n, dp1)<<endl;

    cout << "Output with Bottom Up Approach : "<<fibonacci_bottomUp(n, dp2)<<endl;

    cout << "Output with Space Optimized Approach : "<<fibonacci_spaceOptimized(n)<<endl;

    return 0;
}