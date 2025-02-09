#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        long long goodPairs = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int key = nums[i] - i;
            goodPairs += freq[key];
            freq[key]++;
        }

        return (n * (n - 1)) / 2 - goodPairs;
    }
};

int main()
{
    vector<int> arr = {4,1,3,3};

    Solution obj;
    cout << obj.countBadPairs(arr);

    return 0;
}