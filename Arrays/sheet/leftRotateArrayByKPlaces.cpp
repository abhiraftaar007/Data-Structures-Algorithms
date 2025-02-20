#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-array/description/  

// Approach 1
void RotateToRight(vector<int>& arr, int n, int k)
{
    // T.C - O(n)
    // S.C - O(k)
    if (n == 0)
        return;
    k = k % n;
    if (k > n)
        return;
    int temp[k]; // O(k)
    for (int i = n - k; i < n; i++) // O(k)
    {
        temp[i - n + k] = arr[i];
    }
    for (int i = n - k - 1; i >= 0; i--) // O(n)
    {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    RotateToRight(nums, nums.size(), k);

    for(auto& i : nums){
        cout << i << " ";
    }

    return 0;
}