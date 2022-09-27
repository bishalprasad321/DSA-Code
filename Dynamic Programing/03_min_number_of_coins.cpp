#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &num, int x, vector<int> &dp) // topDown approach
{
    // base case 
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;
    
    if (dp[x] != -1)
        return dp[x];
    
    int mini = INT_MAX;
    for (int i = 0; i < num.size(); ++i)
    {
        int ans = solveMem(num, x-num[i], dp);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    
    dp[x] = mini;
    
    return dp[x];
}

int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= x; ++i)
    {
        for (int j = 0; j < num.size(); ++j)
        {
            if (i - num[j] >= 0 and dp[i - num[j]] != INT_MAX)
                dp[i] = min(1 + dp[i - num[j]], dp[i]);
        }
    }
    
    if (dp[x] == INT_MAX)
        return -1;
    else
        return dp[x];
}

int main()
{
    int size, targetSum;
    cout << "Enter the size of the array : ";
    cin >> size;

    cout << "Enter the target sum : ";
    cin >> targetSum;

    vector<int> arr(size);

    cout << "Enter the elements of the array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(targetSum + 1, -1);

    int ans1 = solveMem(arr, targetSum, dp);
    int ans2 = solveTab(arr, targetSum);

    cout << "Output with Top Down Approach : "<<ans1 <<endl;
    cout << "Output with Bottom Up Approach : "<<ans2 <<endl;
    return 0;
}