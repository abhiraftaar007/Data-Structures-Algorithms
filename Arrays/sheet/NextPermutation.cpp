#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-permutation/description/

class Solution
{
public:
    void nextPermutation(vector<int> &a)
    {
        int n = a.size();
        int idx = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
            {
                idx = i;
                break;
            }
        }

        if (idx == -1)
        {
            reverse(a.begin(), a.end());
            return;
        }

        for (int i = n - 1; i > idx; i--)
        {
            if (a[idx] < a[i])
            {
                swap(a[i], a[idx]);
                break;
            }
        }

        reverse(a.begin() + idx + 1, a.end());
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {1,2,3};
    Solution obj;
    
    obj.nextPermutation(nums);

    for(auto& i:nums){
        cout << i << " ";
    }

    return 0;
}