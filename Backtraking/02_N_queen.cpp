#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row; 
    int y = col;
    
    // for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }
    
    x = row;
    y = col;
    // for up diagonal
    while (x >= 0 and y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    
    x = row;
    y = col;
    // for down diagonal
    while (x < n and y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case
    if (col == n)
    {
        addSolution(ans, board, n);
        return ;
    }
    
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            
            // recursive call
            solve(col + 1, ans, board, n);
            
            // backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board (n, vector<int> (n, 0));
    vector<vector<int>> ans;
    
    solve (0, ans, board, n);
    
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of queens : ";
    cin >> n;

    vector<vector<int>> ans = nQueens(n);

    cout << "The following arrangement must be made to keep the queen : "<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}