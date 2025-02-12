#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12
class Solution
{
public:
    int getDigitSum(int num)
    {
        int sum = 0;

        while (num > 0)
        {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }
    int maximumSum(vector<int> &nums)
    {
        // Solution 1
        int n = nums.size();
        int result = -1;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int digitSum = getDigitSum(nums[i]);

            if (mp.count(digitSum))
            {
                result = max(result, nums[i] + mp[digitSum]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }
        return result;
    }

    int maximumSum2(vector<int> &nums)
    {
        // Solution 2
        int n = nums.size();
        int result = -1;

        int mp[82] = {0};

        for (int i = 0; i < n; i++)
        {
            int digitSum = getDigitSum(nums[i]);

            if (mp[digitSum] > 0)
            {
                result = max(result, nums[i] + mp[digitSum]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }
        return result;
    }

    int maximumSum3(vector<int> &nums)
    {
        // Solution 3
        vector<pair<int, int>> v;

        for (auto &n : nums)
        {
            int digitSum = getDigitSum(n);
            v.push_back({digitSum, n});
        }
        sort(begin(v), end(v));

        int result = -1;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].first == v[i - 1].first)
            {
                result = max(result, v[i].second + v[i - 1].second);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> arr = {18,43,36,13,7};
    Solution obj;

    cout << obj.maximumSum(arr) << '\n';
    cout << obj.maximumSum2(arr) << '\n';
    cout << obj.maximumSum3(arr) << '\n';
    
    return 0;
}