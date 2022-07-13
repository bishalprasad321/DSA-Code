#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{
    if ((x >= 0 and x < n) and (y >= 0 and y < n) and visited[x][y] != 1 and arr[x][y] == 1)
    {
        return true;
    }
    else
        return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    // base case
    if (x == n - 1 and y == n - 1)
    {
        ans.push_back(path);
        return ;
    }
    
    // 4 movements
    // D, L, R, U
    
    visited[x][y] = 1;
    // D
    if (isSafe(x + 1, y, visited, arr, n))
    {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }
    
    // L
    if (isSafe(x, y - 1, visited, arr, n))
    {
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }
    
    // R
    if (isSafe(x, y + 1, visited, arr, n))
    {
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }
    
    // U
    if (isSafe(x - 1, y, visited, arr, n))
    {
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }
    
    visited[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited (n, vector<bool> (n,0));
    
    string path = "";
    
    if (arr[0][0] == 0)
        return ans;
    
    solve (0, 0, arr, n, ans, visited, path);
    
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> arr {{1,1,1,0},{1,1,1,0},{1,0,1,1},{0,0,0,1}};
    vector<string> ans = searchMaze(arr, n);

    cout << "Following are the correct paths of the maze : "<<endl;

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}