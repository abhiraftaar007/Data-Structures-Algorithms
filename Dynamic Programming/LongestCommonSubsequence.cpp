#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// https://leetcode.com/problems/longest-common-subsequence/description/

// Recursive - TLE
/*
class Solution {
public:
    int m,n;
    int solve(string& s1, string& s2, int i, int j){
        if(i>=m || j>=n){
            return 0;
        }

        if(s1[i]==s2[j]) return 1+solve(s1,s2,i+1,j+1);

        return max(solve(s1,s2,i+1,j), solve(s1,s2,i,j+1));
    }
    int longestCommonSubsequence(string s1, string s2) {
        m = s1.length();
        n = s2.length();

        return solve(s1,s2,0,0);
    }
};
*/

class Solution
{
public:
    int m, n;
    // int t[1001][1001];
    vector<vector<int>> t;
    int solve(string &s1, string &s2, int i, int j)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }

        if (t[i][j] != -1)
            return t[i][j];

        if (s1[i] == s2[j])
        {
            return t[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }

        return t[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }

    // Solution 1 - Recursion + Memoization
    int lcs(string &s1, string &s2)
    {
        // code here
        // Recursion
        m = s1.length();
        n = s2.length();
        // memset(t, -1, sizeof(t));
        t.resize(m, vector<int>(n, -1));
        return solve(s1, s2, 0, 0);
    }

    // Solution 2 - Bottom Up
    int longestCommonSubsequence(string s1, string s2)
    {
        // Bottom Up
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> t(m + 1, vector<int>(n + 1));

        // first row and first column will be 0
        for (int row = 0; row < m + 1; row++)
        {
            t[row][0] = 0;
        }

        for (int col = 0; col < n + 1; col++)
        {
            t[0][col] = 0;
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        return t[m][n];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1 = "abcde", s2 = "ace";
    Solution obj;

    cout << obj.lcs(s1,s2) << "\n";
    cout << obj.longestCommonSubsequence(s1,s2) << "\n";
    
    return 0;
}