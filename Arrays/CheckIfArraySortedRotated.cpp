#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/1528292889/?envType=daily-question&envId=2025-02-02

bool isSorted(int &i, int &j, vector<int> &nums, int n)
{
    while (j < n)
    {
        if (nums[i] > nums[j])
        {
            break;
        }
        j++;
        i++;
    }

    if (j == n)
        return true;

    return false;
}

// Solution 1 -> self-solution
bool check(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return true;
    int i = 0;
    int j = i + 1;

    bool sorted = isSorted(i, j, nums, n);
    if (sorted)
        return true;

    int largest = nums[i];

    i = j;
    if (j != n - 1)
        j = j + 1;

    while (j < n)
    {
        if (nums[i] <= nums[j] && nums[j] <= largest && nums[j] <= nums[0])
        {
            j++;
            i++;
        }
        else
        {
            break;
        }
    }

    if (j == n)
        return true;

    return false;
}

int countAdjacentInversions(vector<int> &arr, int n)
{
    int inversions = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            inversions++;
        }
    }

    return inversions;
}

// Solution 2 - Good Code Quality and Approach
bool check2(vector<int> &nums)
{
    int n = nums.size();

    int inversions = countAdjacentInversions(nums, n);

    // If there is not inversions, the array is sorted.
    if (inversions == 0)
    {
        return true;
    }

    if (nums[0] == nums[n - 1])
    {

        if (inversions == 1)
        {
            return true;
        }

        return false;
    }

    // If there is exactly one inversion and the last element is smaller
    // than the first element, the array is both sorted and rotated.
    if (inversions == 1 && nums[n - 1] < nums[0])
    {
        return true;
    }

    // otherwise, the array is not sorted and rotated.
    return false;
}

int main()
{
    vector<int> nums = {3,4,5,1,2};

    cout << check(nums) << '\n';
    cout << check2(nums);

    return 0;
}