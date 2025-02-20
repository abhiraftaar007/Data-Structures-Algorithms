#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

// Solution 1 - Brute Force
bool isSorted(vector<int>& arr, int n)
{
    // T.C - O(n^2), S.C - O(1)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                return false;
        }
    }

    return true;
}

// Optimal Solution - single traversal
bool isSorted2(vector<int>& arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1,2,3,4,5};

    cout << isSorted(arr,arr.size()) << '\n';
    cout << isSorted2(arr,arr.size()) << '\n';

    return 0;
}