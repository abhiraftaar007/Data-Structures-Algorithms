#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> productMap;
        int result = 0;

        // Generate all pairs (a, b) and store their product counts in the map
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int product = nums[i] * nums[j];
                productMap[product]++;
            }
        }

        // For each pair (c, d), check if there's a pair (a, b) that satisfies a * b = c * d
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int product = nums[i] * nums[j];
                // Decrease the count for the product of (c, d) because we don't want a == c or b == d
                productMap[product]--;
                // Add the count of valid pairs (a, b) where a * b = c * d
                result += productMap[product];
                // Restore the count for the current product after processing
                productMap[product]++;
            }
        }

        return result * 4;
    }
};

int main()
{
    vector<int> nums = {2,3,4,6};
    
    Solution obj;

    cout << obj.tupleSameProduct(nums);
    
    return 0;
}