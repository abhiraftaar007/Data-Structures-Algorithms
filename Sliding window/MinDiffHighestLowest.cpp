#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/

class Solution
{
public:
    // Sorting + sliding window - self solution
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int i = 0, j = 0, diff = 0, ans = INT_MAX;

        while (j < n)
        {
            while (j < k - 1)
            {
                j++;
            }

            diff = nums[j] - nums[i];

            ans = min(diff, ans);

            i++;
            j++;
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {9,4,1,7};
    int k = 2;

    Solution obj;

    cout << obj.minimumDifference(nums,k);

    return 0;
}