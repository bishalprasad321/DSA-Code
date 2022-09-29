#include<bits/stdc++.h>
using namespace std;

long long int solveRecursion(vector<int> &nums, int n)
{
    // base case
    if (n < 0)
        return 0;
    
    if (n == 0)
        return nums[0];
    
    long long int inclusive = solveRecursion(nums, n - 2)+ nums[n];
    long long int exclusive = solveRecursion(nums, n - 1) + 0;
    
    return max(inclusive, exclusive);
}

long long int solveMemoization(vector<int> &nums, int n, vector<long long int> &dp)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];
    
    if (dp[n] != -1)
        return dp[n];
    
    long long int inclusive = solveMemoization(nums, n - 2, dp) + nums[n];
    long long int exclusive = solveMemoization(nums, n - 1, dp) + 0;
    
    dp[n] = max(inclusive, exclusive);
    return dp[n];
}

long long int solveTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<long long int> dp(n + 1, -1);
    dp[0] = nums[0];
    
    for (int i = 1; i < n; i++)
    {
        long long int inclusive = dp[i-2] + nums[i];
        long long int exclusive = dp[i-1] + 0;
        
        dp[i] = max(inclusive, exclusive);
    }
    return dp[n - 1];
}

long long int solveOptimized(vector<int> &nums)
{
    long long int prev2 = 0;
    long long int prev1 = nums[0];
    
    for (int i = 1; i < nums.size(); i++)
    {
        long long int inclusive = prev2 + nums[i];
        long long int exclusive = prev1 + 0;
        
        long long int ans = max(inclusive, exclusive);
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}

// long long int houseRobber(vector<int>& valueInHouse)
// {  
//     if (valueInHouse.size() == 1)
//         return valueInHouse[0];

//     vector<int> first, second;

//     for (int i = 0; i < valueInHouse.size(); i++)
//     {
//         if (i != valueInHouse.size() - 1) 
//             first.push_back(valueInHouse[i]); // exclude the last house value
//         if (i != 0)
//             second.push_back(valueInHouse[i]); // exclude the first house value
//     }
    
//     return max(solveOptimized(first), solveOptimized(second));
// }


int main()
{
    int n;
    cout << "Enter the size of the house array : ";
    cin >> n;
    vector<int> houseValue(n), first(n), second(n);

    vector<long long int> dp(n + 1, -1);

    cout << "Enter the House Values : ";

    for (int i = 0; i < n; i++)
    {
        cin >> houseValue[i];
    }

    if (n == 0)
        cout << "Solution : " << houseValue[0] << endl;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            second.push_back(houseValue[i]);

        if (i != n - 1)
            first.push_back(houseValue[i]);
    }
    cout << "Recursive Solution : " << max(solveRecursion(first, n), solveRecursion(second, n)) << endl;

    cout << "Recursion + Memoization : " << max(solveMemoization(first, n, dp), solveMemoization(second, n, dp)) << endl;

    cout << "Tabulation approach : " << max(solveTabulation(first), solveTabulation(second)) << endl;

    cout << "Space Optmized approach : " << max(solveOptimized(first), solveOptimized(second)) << endl;

    return 0;
}