#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/description/

// Brute Force -
int maxProductSubArray(vector<int> &nums)
{
    // T.C - O(n^3), S.C - O(1)
    int result = INT_MIN;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int prod = 1;
            for (int k = i; k <= j; k++)
                prod *= nums[k];
            result = max(result, prod);
        }
    }
    return result;
}

// Better Approach -
int maxProductSubArray2(vector<int> &nums)
{
    // T.C - O(n^2), S.C - O(1)
    int result = nums[0];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int p = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            result = max(result, p);
            p *= nums[j];
        }
        result = max(result, p); // manages (n-1)th term
    }
    return result;
}

// Optimal approach 1 -
int maxProductSubArray3(vector<int> &arr)
{
    // T.C - O(n), S.C - O(1)
    int n = arr.size(); // size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

// Optimal approach 2 - Kadane's algorithm
int maxProductSubArray4(vector<int> &nums)
{
    // T.C - O(n), S.C - O(1)
    int prod1 = nums[0], prod2 = nums[0], result = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]});
        prod2 = min({nums[i], prod1 * nums[i], prod2 * nums[i]});
        prod1 = temp;

        result = max(result, prod1);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {2, 3, -2, 4};
    cout << "The maximum product subarray: " << maxProductSubArray4(nums);
    return 0;
}