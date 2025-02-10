#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        unordered_map<int, int> count;
        int k = 0;

        for (int num : nums)
        {
            count[num]++;
            if (count[num] <= 2)
            {
                nums[k] = num;
                k++;
            }
        }

        return k;
    }
};

int main()
{
    vector<int> arr = {1,1,1,2,2,3};

    Solution obj;
    
    cout << obj.removeDuplicates(arr);

    return 0;
}