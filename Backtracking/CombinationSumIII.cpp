#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    void helper(int ind, int sum, int n, vector<vector<int>> &ans, vector<int> &ans2, int k)
    {
        if (sum == n && k == 0)
        {
            ans.push_back(ans2);
            return;
        }
        if (sum > n)
        {
            return;
        }
        for (int i = ind; i <= 9; i++)
        {
            if (i > n)
                break;
            ans2.push_back(i);
            helper(i + 1, sum + i, n, ans, ans2, k - 1);
            ans2.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> ans2;
        vector<vector<int>> ans;
        helper(1, 0, n, ans, ans2, k);

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k = 3, n = 7;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum3(k,n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout <<  '\n';
    }
    
    return 0;
}