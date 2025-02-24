#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-sum/description/
// Brute Force
vector<int> twoSum(int n, vector<int> &arr, int target)
{
    // T.C - O(n^2), S.C - O(1)
    vector<int> ans;
    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = i + 1; j < n; j++) // O(n)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}

// Better - using hashing
vector<int> twoSum2(int n, vector<int> &arr, int target)
{
    // T.C - O(n), S.C - O(n)
    unordered_map<int, int> mpp; // O(n)
    for (int i = 0; i < n; i++) // O(n )
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) // O(1)
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

// Optimised - using two pointer
vector<int> twoSum3(int n, vector<int> &arr, int target)
{
    // T.C - O(n) + O(nlogn), S.C - O(1)
    vector<int> ans;
    sort(arr.begin(), arr.end()); // O(nlogn)
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            ans.push_back(arr[left]);
            ans.push_back(arr[right]);
            return ans;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return {-1,-1};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    // vector<int> ans = twoSum(arr.size(), arr, target);
    // vector<int> ans = twoSum2(arr.size(), arr, target);
    vector<int> ans = twoSum3(arr.size(), arr, target);

    for(auto& i : ans){
        cout << i << " ";
    }

    return 0;
}