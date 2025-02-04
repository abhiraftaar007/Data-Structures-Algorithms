#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // using sliding window - self solution
        int n = nums.size();

        int i = 0, j = 0, ans = 0, sum = 0;

        while(j<n){

            if(j!=0 && nums[j]<=nums[j-1]){
                i = j;
                sum = 0;
            }
            sum+=nums[j];
            ans = max(sum, ans);
            j++;

        }

        return ans;
    }
};


int main()
{
    vector<int> nums = {10, 20, 30, 5, 10, 50};

    Solution obj;

    cout << obj.maxAscendingSum(nums);

    return 0;
}