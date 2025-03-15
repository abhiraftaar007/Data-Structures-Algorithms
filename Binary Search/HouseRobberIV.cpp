#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber-iv/?envType=daily-question&envId=2025-03-15

bool canRob(vector<int> &nums, int mid, int k)
{
    int count = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= mid)
        {
            count++;
            i++;
        }
    }
    return count >= k;
}
int minCapability(vector<int> &nums, int k)
{
    int left = 1, right = *max_element(nums.begin(), nums.end()), ans = right;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (canRob(nums, mid, k))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {2,3,5,9};
    int k = 2;

    cout << minCapability(nums, k);
    
    return 0;
}