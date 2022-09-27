#include<bits/stdc++.h>
using namespace std;

int solveRecursion(vector<int> &nums, int n)
{
    // base case
    if (n < 0)
        return 0;
    
    if (n == 0)
        return nums[0];
    
    int inclusive = solveRecursion(nums, n - 2)+ nums[n];
    int exclusive = solveRecursion(nums, n - 1) + 0;
    
    return max(inclusive, exclusive);
}

int solveMemoization(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];
    
    if (dp[n] != -1)
        return dp[n];
    
    int inclusive = solveMemoization(nums, n - 2, dp) + nums[n];
    int exclusive = solveMemoization(nums, n - 1, dp) + 0;
    
    dp[n] = max(inclusive, exclusive);
    return dp[n];
}

int solveTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    dp[0] = nums[0];
    
    for (int i = 1; i < n; i++)
    {
        int inclusive = dp[i-2] + nums[i];
        int exclusive = dp[i-1] + 0;
        
        dp[i] = max(inclusive, exclusive);
    }
    return dp[n - 1];
}

int solveOptimized(vector<int> &nums)
{
    int prev2 = 0;
    int prev1 = nums[0];
    
    for (int i = 1; i < nums.size(); i++)
    {
        int inclusive = prev2 + nums[i];
        int exclusive = prev1 + 0;
        
        int ans = max(inclusive, exclusive);
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(n + 1, -1);

    cout << "Solution with recursion : "<<solveRecursion(nums, n)<<endl;
    cout << "Solution with recursiobn + meoization : "<<solveMemoization(nums, n, dp) <<endl;
    cout << "Solution with Tabulation : "<<solveTabulation(nums)<<endl;
    cout << "Solution with Space Optimization : "<<solveOptimized(nums);
    return 0;
}