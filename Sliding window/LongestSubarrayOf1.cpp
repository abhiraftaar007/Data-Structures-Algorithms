#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75

// Brute Force - self solution
int longestSubarray(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0, one = 0, zero = 0;

    for (int i = 0; i < n; i++)
    {
        zero = 0;
        one = 0;
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            if (zero > 1)
            {
                break;
            }
            else if (nums[j] == 1)
            {
                one++;
                sum++;
            }
            else
                zero++;
        }

        if (sum == n && nums[0] == nums[n - 1])
            return n - 1;

        ans = max(ans, one);
    }

    return ans;
}

// Using sliding window - self solution
int longestSubarray2(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0;
    int zeroCount = 0, ans = 0, one = 0, sum = 0;

    while (j < n)
    {
        if (nums[j] == 0)
        {
            zeroCount++;
        }

        while (zeroCount > 1 && i < j)
        {
            if (nums[i] == 1)
                one--;
            else
                zeroCount--;
            i++;
        }

        if (nums[j] == 1)
        {
            one++;
            sum++;
        };

        ans = max(one, ans);

        if (sum == n && j == n - 1 && zeroCount == 0)
            return n - 1;

        j++;
    }

    return ans;
}

int main()
{
    vector<int> arr = {0,1,1,1,0,1,1,0,1};
    cout << longestSubarray2(arr);

    return 0;
}