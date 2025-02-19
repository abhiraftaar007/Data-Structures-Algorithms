#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19

class Solution
{
public:
    void solve(int n, string &curr, vector<string> &result)
    {
        if (curr.length() == n)
        {
            result.push_back(curr);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++)
        {
            if (!curr.empty() && curr.back() == ch)
            {
                continue;
            }

            // DO
            curr.push_back(ch);

            // EXPLORE
            solve(n, curr, result);

            // UNDO
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k)
    {
        // Backtracking
        string curr = "";

        vector<string> result;

        solve(n, curr, result);

        if (result.size() < k)
        {
            return "";
        }

        return result[k - 1];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 1, k = 3;

    Solution obj;

    cout << obj.getHappyString(n,k);

    return 0;
}