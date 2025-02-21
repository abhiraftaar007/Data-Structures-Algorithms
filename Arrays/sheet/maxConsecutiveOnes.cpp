#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones/submissions/
class Solution
{
public:
    // T.C - O(n), S.C - O(1)
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(nums);
    cout << "The maximum  consecutive 1's are " << ans;

    return 0;
}