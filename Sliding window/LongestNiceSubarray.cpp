#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Solution 1 - 
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            int mask = 0;

            for (int j = i; j < n; j++)
            {
                if ((mask & nums[j]) != 0)
                    break;

                result = max(result, j - i + 1);
                mask = (mask | nums[j]);
            }
        }

        return result;
    }

    // Solution 2 -
    int longestNiceSubarray2(vector<int> &nums)
    {
        int result = 0;
        int n = nums.size();
        int currentOr = 0;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            // Add the current number to the OR for the window
            while (currentOr & nums[right])
            {
                // If there's overlap (bitwise AND != 0), slide the window
                currentOr ^= nums[left];
                left++;
            }

            // Add the current number to the OR of the window
            currentOr |= nums[right];

            // Update the result with the size of the current nice subarray
            result = max(result, right - left + 1);
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {1,3,8,48,10};
    Solution obj;
    cout << obj.longestNiceSubarray(nums);

    return 0;
}