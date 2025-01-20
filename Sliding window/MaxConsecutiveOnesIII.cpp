#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75


// Brute Force - TLE
int longestOnes(vector<int> &nums, int k)
{
    int maxLen = 0, len = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int zero = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                zero++;
            if (zero <= k)
            {
                len = j - i + 1;
                maxLen = max(maxLen, len);
            }
            else
            {
                break;
            }
        }
    }

    return maxLen;
}

// Optimal Solution - using sliding window
int longestOnes2(vector<int> &nums, int k)
{
    int l = 0, r = 0, zero = 0, maxLen = 0, len = 0;
    while (r < nums.size())
    {
        if (nums[r] == 0)
            zero++;
        if (zero > k)
        {
            if (nums[l] == 0)
                zero--;
            l++;
        }
        if (zero <= k)
        {
            len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    cout << longestOnes2(arr,k);
    return 0;
}