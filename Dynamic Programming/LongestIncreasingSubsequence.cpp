#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution
{
public:
    // Solution 1 -
    int lis(vector<int> &arr)
    {
        // code here
        vector<int> ans;
        ans.push_back(arr[0]);
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > ans.back())
                ans.push_back(arr[i]);
            else
            {
                int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[idx] = arr[i];
            }
        }

        return ans.size();
    }

    int dp[1005];
    int fn(vector<int> &a, int i)
    {
        if (i >= a.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 1;
        for (int j = i; j < a.size(); j++)
        {
            if (a[j] > a[i])
                ans = max(ans, fn(a, j) + 1);
        }
        return dp[i] = ans;
    }

    // Solution 2 - 
    int lis2(vector<int> &a)
    {
        // code here
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < a.size(); i++)
        {
            ans = max(ans, fn(a, i));
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {5, 8, 3, 7, 9, 1};
    Solution obj;

    cout << obj.lis(arr);

    return 0;
}