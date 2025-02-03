#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03

int strictlyInc(vector<int> &nums)
{
    int n = nums.size();
    int temp_inc = 0;
    int ans = 0;

    int i = 0, j = 0;
    while (i < n - 1)
    {
        temp_inc = 1;
        j = i + 1;
        if (nums[i] < nums[j])
        {
            temp_inc++;
            int k = j + 1;
            while (k < n)
            {
                if (nums[k] > nums[j])
                {
                    temp_inc++;
                    j = k;
                    k++;
                }
                else
                    break;
            }
        }
        ans = max(ans, temp_inc);
        i++;
    }

    return ans;
}

int strictlyDec(vector<int> &nums)
{
    int n = nums.size();
    int temp_inc = 0;
    int ans = 0;

    int i = 0, j = 0;
    while (i < n - 1)
    {
        temp_inc = 1;
        j = i + 1;
        if (nums[i] > nums[j])
        {
            temp_inc++;
            int k = j + 1;
            while (k < n)
            {
                if (nums[k] < nums[j])
                {
                    temp_inc++;
                    j = k;
                    k++;
                }
                else
                    break;
            }
        }
        ans = max(ans, temp_inc);
        i++;
    }

    return ans;
}

// Brute Force - self solution
int longestMonotonicSubarray(vector<int> &nums)
{
    if (nums.size() == 1)
        return 1;
    // Brute Force
    int inc = strictlyInc(nums);
    int dec = strictlyDec(nums);
    return max(dec, inc);
}

int strictlyI(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0, temp_inc = 1, ans = 0;
    while (j + 1 < n)
    {
        if (nums[j + 1] > nums[j])
            temp_inc++;
        else
        {
            temp_inc = 1;
            i = j + 1;
        }

        ans = max(temp_inc, ans);
        j++;
    }

    return ans;
}

int strictlyD(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0, temp_inc = 1, ans = 0;
    while (j + 1 < n)
    {
        if (nums[j + 1] < nums[j])
            temp_inc++;
        else
        {
            temp_inc = 1;
            i = j + 1;
        }

        ans = max(temp_inc, ans);
        j++;
    }

    return ans;
}

// Optimal - Sliding Window - self solution
int longestMonotonicSubarray2(vector<int> &nums)
{
    if (nums.size() == 1)
        return 1;

    int inc = strictlyI(nums);
    int dec = strictlyD(nums);

    return max(inc, dec);
}

int main()
{
    vector<int> nums = {1,4,3,3,2};

    cout << longestMonotonicSubarray(nums) << '\n';

    cout << longestMonotonicSubarray2(nums);
    
    return 0;
}