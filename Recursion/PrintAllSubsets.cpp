#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subsets/description/

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index + 1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}

// Solution 1
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        return;
    }

    string op1 = op;
    string op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    solve(ip, op1);
    solve(ip, op2);
}

int main()
{
    string ip;
    // cin >> ip;

    string op = "";
    // solve(ip, op);

    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = subsets(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}