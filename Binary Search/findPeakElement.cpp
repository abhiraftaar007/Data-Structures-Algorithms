#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=leetcode-75

// Brute force - self solution
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    if (nums.size() == 2)
    {
        if (nums[0] > nums[1])
            return 0;
        else
            return 1;
    }

    int i = 0;
    int j = 1;
    int k = 2;

    int n = nums.size();
    while (k < n)
    {
        if (nums[j] > nums[i] && nums[j] > nums[k])
        {
            return j;
        }
        i++;
        j++;
        k++;
    }

    if (nums[j] > nums[j - 1])
        return j;

    return 0;
}

// Optimal - Binary Search
int findPeakElement2(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;

    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement2(nums);

    return 0;
}