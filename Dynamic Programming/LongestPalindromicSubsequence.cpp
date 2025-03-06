#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

class Solution
{
public:
    int longestPalinSubseq(string &A)
    {
        // code here
        string rev = A;
        reverse(rev.begin(), rev.end());
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (A[i - 1] == rev[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "bbabcbcab";
    Solution obj;
    cout << obj.longestPalinSubseq(s);
    
    return 0;
}