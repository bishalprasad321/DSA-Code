#include<bits/stdc++.h>
using namespace std;

// Memoization + Recursion - Top Down
int minCost_topDown(int n, vector<int> &cost, vector<int> &dp)
{
    if (n == 0)
        return cost[0];

    if (n == 1)
        return cost[1];

    if (dp[n] != -1)
        return dp[n];

    dp[n] = cost[n] + min(minCost_topDown(n-1, cost, dp), minCost_topDown(n-2, cost, dp));
    return dp[n];
}

// Tabulation - Bottom Up
int minCost_bottomUp(int n, vector<int> &cost)
{
    // vector creation
    vector<int> dp(n+1, -1);
        
    dp[0] = cost[0];
    dp[1] = cost[1];
        
    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
        
    return min(dp[n-1], dp[n-2]);
}

// Space Optimized 
int minCost_spaceOptimized(int n, vector<int> &cost)
{
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}


int main()
{
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    int n = cost.size();
    
    vector<int> dp(n+1, -1);

    cout << "Min Cost by Top Down approach : "<< minCost_topDown(n, cost, dp) << endl;
    cout << "Min Cost by Bottom Up approach : "<< minCost_bottomUp(n, cost) << endl;
    cout << "Min Cost by Space Optimized method : "<<minCost_spaceOptimized(n, cost) << endl;

    return 0;
}