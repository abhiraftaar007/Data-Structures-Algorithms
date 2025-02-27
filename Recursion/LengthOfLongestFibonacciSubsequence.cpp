#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/?envType=daily-question&envId=2025-02-27

class Solution
{
public:
    int solve(int j, int k, vector<int> &arr, unordered_map<int, int> &mp)
    {
        int target = arr[k] - arr[j];

        if (mp.count(target) && mp[target] < j)
        { // i < j < k
            int i = mp[target];
            return solve(i, j, arr, mp) + 1; //  +1 for adding kth element in the sequence
        }

        return 2;
    }
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i; // element -> idx
        }

        int max_length = 0;
        // j<k
        for (int j = 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int length = solve(j, k, arr, mp);
                if (length >= 3)
                {
                    max_length = max(max_length, length);
                }
            }
        }

        return max_length;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1,2,3,4,5,6,7,8};
    Solution obj;

    cout << obj.lenLongestFibSubseq(arr);
    
    return 0;
}