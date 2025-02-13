#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        // self-solution
        priority_queue<int, vector<int>, greater<int>> g;
        for (int i = 0; i < nums.size(); i++)
        {
            g.push(nums[i]);
        }

        int operation = 0;
        while (!g.empty())
        {
            if (g.top() >= k)
                return operation;
            int a = g.top();
            g.pop();
            int b = g.top();
            g.pop();
            // int op = min(a,b)*2 + max(a,b);

            int op;
            int min_val = min(a, b);
            int max_val = max(a, b);

            // Check for overflow before performing the operation
            if (min_val > INT_MAX / 2 || max_val > INT_MAX - (min_val * 2))
            {
                // Handle overflow (e.g., return an error, use a sentinel value, etc.)
                op = INT_MAX; // Example overflow handling
            }
            else
            {
                op = min_val * 2 + max_val;
            }

            g.push(op);
            operation++;
        }

        return operation;
    }
};

int main()
{
    vector<int> nums = {2,11,10,1,3};
    int k = 10;

    Solution obj;
    cout << obj.minOperations(nums,k);

    return 0;
}