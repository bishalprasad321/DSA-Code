#include<bits/stdc++.h>
using namespace std;

/*
    sample sudoku problem input ->

    3 0 6 5 0 8 4 0 0
    5 2 0 0 0 0 0 0 0
    0 8 7 0 0 0 0 3 1
    0 0 3 0 1 0 0 8 0
    9 0 0 8 6 3 0 0 5
    0 5 0 0 9 0 6 0 0
    1 3 0 0 0 0 2 5 0
    0 0 0 0 0 0 0 7 4
    0 0 5 2 0 6 3 0 0

    output ->

    3 1 6 5 7 8 4 9 2
    5 2 9 1 3 4 7 6 8
    4 8 7 6 2 9 5 3 1
    2 6 3 4 1 5 9 8 7
    9 7 4 8 6 3 1 2 5
    8 5 1 7 9 2 6 4 3
    1 3 8 9 4 7 2 5 6
    6 9 2 3 5 1 8 7 4
    7 4 5 2 8 6 3 1 9
*/

bool isSafe(int row, int col, int val, vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        // check for the row and column
        if ((board[row][i] == val) or (board[i][col] == val))
            return false;

        // check for the 3x3 matrix
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int size = board.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            // check for the empty space
            if (board[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    // place is safe to fill val
                    if (isSafe(i, j, val, board))
                    {
                        board[i][j] = val;

                        bool nextPossible = solve(board);

                        // if next is possible
                        if (nextPossible)
                            return true;

                        // else backtrack
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{
    vector<vector<int>> board (9, vector<int> (9));

    cout << "Enter the sudoku from the code's sample input : "<<endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    cout << "After solving the sudoku ------"<<endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}