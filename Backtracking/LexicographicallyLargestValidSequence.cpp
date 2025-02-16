#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/?envType=daily-question&envId=2025-02-16

class Solution
{
public:
    bool solve(int i, int n, vector<int> &result, vector<bool> &used)
    {
        if (i >= result.size())
        {
            return true; // gauranteed answer - we were filling largest numbers first
        }

        if (result[i] != -1)
        {
            return solve(i + 1, n, result, used);
        }

        for (int num = n; num >= 1; num--)
        {
            if (used[num])
                continue;

            // try
            used[num] = true;
            result[i] = num;

            if (num == 1)
            {
                if (solve(i + 1, n, result, used) == true)
                    return true;
            }
            else
            {
                int j = result[i] + i;
                if (j < result.size() && result[j] == -1)
                {
                    result[j] = num;
                    if (solve(i + 1, n, result, used) == true)
                        return true;

                    result[j] = -1;
                }
            }

            // UNDO
            used[num] = false;
            result[i] = -1;
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n)
    {
        // To generate all sequences - Backtracking
        vector<int> result(2 * n - 1, -1);

        vector<bool> used(n + 1, false);

        solve(0, n, result, used);

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 3;

    Solution obj;

    vector<int> ans = obj.constructDistancedSequence(n);

    for(auto& i:ans){
        cout << i << " ";
    }

    
    return 0;
}