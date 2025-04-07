#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Iterative
int binarySearch(vector<int> &nums, int target)
{
    // T.C - O(logn)
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Approach 2 - Recursive
int binarySearch2(vector<int> &nums, int low, int high, int target)
{
    // T.C - O(logn)
    if (low > high)
        return -1; // Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (target > nums[mid])
        return binarySearch2(nums, mid + 1, high, target);
    return binarySearch2(nums, low, mid - 1, target);
}

int search(vector<int> &nums, int target)
{
    return binarySearch2(nums, 0, nums.size() - 1, target);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;

    // int ind = binarySearch(a, target);
    int ind = search(a,target);

    if (ind == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: "
             << ind << endl;

    return 0;
}