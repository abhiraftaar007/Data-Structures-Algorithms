#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1

class Solution
{
public:
    // Solution 1 - 2 pointer solution
    int countPS(string &s)
    {
        // code here
        int n = s.length();
        int res = 0;

        // odd palindrome strings
        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 >= 2)
                    res++;

                l--;
                r++;
            }

            // even length palindromes
            l = i, r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 >= 2)
                    res++;

                l--;
                r++;
            }
        }

        return res;
    }

    // solution 2 - Bottom approach
    int countPS2(string &s)
    {
        // code here
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            dp[i][i] = 1;
        }
        int ct = 0;
        for (int L = 2; L <= N; L++)
        {
            for (int i = 0; i < N - L + 1; i++)
            {
                int j = i + L - 1;
                if (s[i] == s[j])
                {
                    if (L == 2)
                        dp[i][j] = 2;
                    else if (dp[i + 1][j - 1] > 0)
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    else
                        dp[i][j] = 0;
                }
                ct += (dp[i][j] >= 2);
            }
        }
        return ct;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "abaab";
    Solution obj;

    // cout << obj.countPS(s) << "\n";
    cout << obj.countPS2(s);

    return 0;
}