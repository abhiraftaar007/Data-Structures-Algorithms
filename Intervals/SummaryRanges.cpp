#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150

vector<string> summaryRanges(vector<int> &nums)
{
    int n = nums.size();
    vector<string> result;

    for (int i = 0; i < n; i++)
    {
        int start = nums[i];
        // nums[i+1]-nums[i]==1 indicate overflow
        // so use - nums[i]+1 == nums[i+1]
        while (i + 1 < n && nums[i] + 1 == nums[i + 1])
        {
            i++;
        }

        if (start != nums[i])
        {
            result.push_back(to_string(start) + "->" + to_string(nums[i]));
        }
        else
        {
            result.push_back(to_string(start));
        }
    }

    return result;
}


int main()
{
    vector<int> arr = {0,1,2,4,5,7};
    vector<string> ans = summaryRanges(arr);
    for(auto &i:ans){
        cout << i << ", ";
    }
    return 0;
}