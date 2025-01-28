#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> result;
unordered_set<int> st;

void solve(vector<int> &temp, vector<int> &nums)
{
    // BackTracking
    if (temp.size() == n)
    {
        result.push_back(temp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (st.find(nums[i]) == st.end())
        {
            temp.push_back(nums[i]);
            st.insert(nums[i]);

            solve(temp, nums);

            temp.pop_back();
            st.erase(nums[i]);
        }
    }
}

// Solution 1
vector<vector<int>> permute(vector<int> &nums)
{
    n = nums.size();
    vector<int> temp;
    solve(temp, nums);

    return result;
}

void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

// Solution 2
vector<vector<int>> permute2(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;

    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    recurPermute(ds, nums, ans, freq);
    return ans;
}

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);
        // backtrack
        swap(nums[index], nums[j]);
    }
}

// Solution 3
vector<vector<int>> permute3(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    
    vector<vector<int>> ans = permute3(nums);

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