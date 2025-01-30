#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/n-queens/

/* bool isSafe1(int row, int col, vector<string> board, int n)
{
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe1(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solve(0, board, ans, n);
    return ans;
} */

// GFG - https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe1(int row, int col, vector<string> board, int n)
{
    int duprow = row;
    int dupcol = col;

    // Check upper left diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;

    // Check the same row to the left
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;

    // Check lower left diagonal
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

// Backtracking function to solve the N-Queens problem
void solve(int col, vector<string> &board, vector<vector<int>> &ans, int n)
{
    // If all queens are placed
    if (col == n)
    {
        vector<int> solution;
        // Collecting the row numbers (1-based index) where queens are placed
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (board[i][j] == 'Q')
                {
                    solution.push_back(i + 1); // Row where queen is placed (1-based index)
                    break;
                }
            }
        }
        ans.push_back(solution);
        return;
    }

    // Try placing the queen in all rows for the current column
    for (int row = 0; row < n; row++)
    {
        if (isSafe1(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n); // Recur for the next column
            board[row][col] = '.';         // Backtrack
        }
    }
}

// Function to get all the solutions for N-Queens
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<string> board(n);
    string s(n, '.'); // Initialize each row of the board with '.'

    for (int i = 0; i < n; i++)
    {
        board[i] = s; // Fill the board with '.' initially
    }

    solve(0, board, ans, n); // Start solving from the first column
    return ans;
}

// Wrapper function for N-Queens problem
vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> ans = solveNQueens(n);
    return ans;
}

int main()
{
    /* int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }
    */

    int n = 4;
    vector<vector<int>> ans = nQueen(n);

    // Output the solutions with 1-based indexing
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " "; // Printing the row number (1-based index)
        }
        cout << endl;
    }

    return 0;
}