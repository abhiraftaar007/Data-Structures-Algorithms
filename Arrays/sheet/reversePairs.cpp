#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-pairs/description/

int countPairs(vector<int> &a, int n)
{

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 2 * a[j])
                cnt++;
        }
    }
    return cnt;
}

// Brute Force - 
int team(vector<int> &skill, int n)
{
    // T.C - O(n^2), S.C - O(1)
    return countPairs(skill, n);
}

void merge(vector<int> &nums, int low, int mid, int high, int &reversePairsCount)
{
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2 * (long long)nums[j])
        {
            j++;
        }
        reversePairsCount += j - (mid + 1);
    }
    int size = high - low + 1;
    vector<int> temp(size, 0);
    int left = low, right = mid + 1, k = 0;
    while (left <= mid && right <= high)
    {
        if (nums[left] < nums[right])
        {
            temp[k++] = nums[left++];
        }
        else
        {
            temp[k++] = nums[right++];
        }
    }
    while (left <= mid)
    {
        temp[k++] = nums[left++];
    }
    while (right <= high)
    {
        temp[k++] = nums[right++];
    }
    int m = 0;
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[m++];
    }
}

void mergeSort(vector<int> &nums, int low, int high, int &reversePairsCount)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) >> 1;
    mergeSort(nums, low, mid, reversePairsCount);
    mergeSort(nums, mid + 1, high, reversePairsCount);
    merge(nums, low, mid, high, reversePairsCount);
}

// Optimal solution - 
int reversePairs(vector<int> &nums)
{
    // T.C - O(nlogn), S.C - O(n)
    int reversePairsCount = 0;
    mergeSort(nums, 0, nums.size() - 1, reversePairsCount);
    return reversePairsCount;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {1, 3, 2, 3, 1};
    int n = a.size();
    // int cnt = team(a, n);
    int cnt = reversePairs(a);
    cout << "The number of reverse pair is: "
         << cnt << endl;

    return 0;
}