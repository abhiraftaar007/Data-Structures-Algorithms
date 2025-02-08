#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-array-by-parity/description/

class Solution
{
public:
    vector<int> sortArrayByParity1(vector<int> &nums)
    {
        // self-solution
        vector<int> odd;
        vector<int> even;
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
            i++;
        }

        int o = odd.size();
        i = 0;
        while (i < o)
        {
            even.push_back(odd[i]);
            i++;
        }

        return even;
    }

    vector<int> sortArrayByParity2(vector<int> &nums)
    {
        // self-solution 2
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            int j = i + 1;
            while (j < n && nums[j] % 2 != 0)
            {
                j++;
            }
            if (j == n)
                break;
            swap(nums[i], nums[j]);
            i++;
        }

        return nums;
    }
};

int main()
{
    vector<int> nums = {3,1,2,4};
    
    Solution obj;

    vector<int> ans = obj.sortArrayByParity1(nums);

    for(auto& i:ans){
        cout << i << " ";
    }

    return 0;
}