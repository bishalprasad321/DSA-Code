#include<bits/stdc++.h>
using namespace std;

int solveRec(int n, int x, int y, int z)
{
    // base case - 1
    if (n == 0)
        return 0;
    // base case - 2
    if (n < 0)
        return INT_MIN;
    
    int p1 = solveRec(n-x, x, y, z) + 1; // if segments with x is formed
    int p2 = solveRec(n-y, x, y, z) + 1; // if segments with y is formed
    int p3 = solveRec(n-z, x, y, z) + 1; // if segments with z is formed

    int ans = max(p1, max(p2, p3));
    
    if (ans < 0)
        return 0;

    else
        return ans;
}

int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;
    
    // Memoization step
    if (dp[n] != -1)
        return dp[n];
    
    int p1 = solveMem(n-x, x, y, z, dp) + 1;
    int p2 = solveMem(n-y, x, y, z, dp) + 1;
    int p3 = solveMem(n-z, x, y, z, dp) + 1;
    
    dp[n] = max(p1, max(p2, p3));
    
    if (dp[n] < 0)
        return 0;
    
    else
        return dp[n];
}

int solveTab(int n, int x, int y, int z)
{
    // step 1 : create dp array
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;
    
    // step 2 : solve the remaining elements
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    if (dp[n] < 0)
        return 0;
    else
        return dp[n];
}

int main()
{
    int n, x, y, z;

    cout << "Enter the length of the rod : ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << "Enter the length of segment x : ";
    cin >> x;

    cout << "Enter the length of segment y : ";
    cin >> y;

    cout << "Enter the length of segment z : ";
    cin >> z;

    cout << "Recursive solution : " << solveRec(n, x, y, z) << endl;
    cout << "Recursive + Memoization solution : " << solveMem(n, x, y, z, dp) << endl;
    cout << "Tabulation solution : " << solveTab(n, x, y, z) << endl;

    return 0;
}