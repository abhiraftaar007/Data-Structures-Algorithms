#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
{
    // Two Pointer + Sorting indices + Placing values
    // T.C - O(nlogn)
    // S.C - O(n)
    int n = nums.size();
    // Find location of each number
    vector<pair<int, int>> copy;
    for (int i = 0; i < n; i++)
    {
        copy.push_back(make_pair(nums[i], i));
    }
    // Get ordered array with their original array index
    sort(copy.begin(), copy.end());

    // Find groups and place ordered values
    int left = 0, right = 1;

    while (right < n)
    {
        // find group and get their original array indices
        vector<int> pos = {copy[left].second};
        while (right < n && abs(copy[right].first - copy[right - 1].first) <= limit)
        {
            pos.push_back(copy[right].second);
            right++;
        }

        // order indices
        sort(pos.begin(), pos.end());

        // Place ordered values to ordered indices in original array
        for (int i = 0; i < right - left; i++)
        {
            nums[pos[i]] = copy[left + i].first;
        }

        left = right;
        right++;
    }

    return nums;
}

int main()
{
    vector<int> arr = {1, 5, 3, 9, 8};
    int limit = 2;
    vector<int> ans = lexicographicallySmallestArray(arr, limit);

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}