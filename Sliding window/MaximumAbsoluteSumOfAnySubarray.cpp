#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/?envType=daily-question&envId=2025-02-26

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        // Solution 1 - kadane's algorithm i.e maximum subarray sum
        int n = nums.size();

        int currSubSum = nums[0];
        int maxSubSum = nums[0];

        // kadane's Algo for finding max subarray sum
        for (int i = 1; i < n; i++)
        {
            currSubSum = max(nums[i], currSubSum + nums[i]);
            maxSubSum = max(maxSubSum, currSubSum);
        }

        // kadane's Algo for finding min subarray sum
        int minSubSum = nums[0];
        currSubSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            currSubSum = min(nums[i], currSubSum + nums[i]);
            minSubSum = min(minSubSum, currSubSum);
        }

        return max(maxSubSum, abs(minSubSum));
    }

    // Solution 2 - more optimised way to write code
    int maxAbsoluteSum2(vector<int> &nums)
    {
        // Used Kadane's algorithm
        int sum = 0, minSum = 0, maxSum = 0;
        for (int num : nums)
        { // O(n)
            sum += num;
            if (sum > maxSum)
                maxSum = sum;
            if (sum < minSum)
                minSum = sum;
        }
        return (maxSum - minSum); // flipping the sign of a negative subarray maximizes the absolute sum.
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {1,-3,2,3,-4};
    
    Solution obj;
    cout << obj.maxAbsoluteSum2(nums);

    return 0;
}