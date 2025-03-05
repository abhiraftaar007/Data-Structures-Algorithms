#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/pascals-triangle/description/

int nCr(int n, int r)
{
    // T.C - O(c), S.C - O(1)
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) // O(c)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// Variation 1 -
int pascalTriangle(int r, int c)
{
    int element = nCr(r - 1, c - 1);
    return element;
}

int nCr2(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// Variation 2 - 
void pascalTriangle2(int n)
{
    // T.C - O(n*r), S.C - O(1)
    // printing the entire row n:
    for (int c = 1; c <= n; c++) // O(n*r)
    {
        cout << nCr2(n - 1, c - 1) << " ";
    }
    cout << "\n";
}

int nCr3(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

// Variation 3 -
vector<vector<int>> pascalTriangle3(int n)
{
    // T.C - O(n*n*r) or O(n^3), S.C - O(1)
    vector<vector<int>> ans;

    // Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++)
        {
            tempLst.push_back(nCr3(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

// Optimal -
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // inserting the 1st element

    // calculate the rest of the elements:
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle4(int n)
{
    // T.C - O(n^2), S.C - O(1)
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r = 5; // row number
    int c = 3; // col number

    // int element = pascalTriangle(r, c);
    // cout << "The element at position (r,c) is: "
    //      << element << "n";

    int n = 5;
    // pascalTriangle2(n);

    // vector<vector<int>> ans = pascalTriangle3(n);
    // for (auto it : ans)
    // {
    //     for (auto ele : it)
    //     {
    //         cout << ele << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<int>> ans = pascalTriangle4(n);
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}