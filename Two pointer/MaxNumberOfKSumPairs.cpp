#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-number-of-k-sum-pairs/?envType=study-plan-v2&envId=leetcode-75

// Self-solution
int maxOperations(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int cnt = 0, i = 0, j = n - 1;

    while (i < j)
    {
        long long sum = nums[i] + nums[j];
        if (sum == k)
        {
            cnt++;
            i++;
            j--;
        }
        else if (sum < k)
            i++;
        else
            j--;
    }

    return cnt;
}


// ChatGPT Solution
int maxOperations2(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < 2)
        return 0; // If there are fewer than 2 elements, no valid pairs can be formed.

    // Sort the array to use the two-pointer technique.
    sort(nums.begin(), nums.end());

    int count = 0; // To keep track of valid pairs.
    int left = 0, right = n - 1;

    // Use the two-pointer technique to find pairs.
    while (left < right)
    {
        int currentSum = nums[left] + nums[right];

        if (currentSum == k)
        {
            // If the sum matches 'k', it's a valid pair.
            count++;
            left++;
            right--;
        }
        else if (currentSum < k)
        {
            // If the sum is less than 'k', move the left pointer to the right to increase the sum.
            left++;
        }
        else
        {
            // If the sum is greater than 'k', move the right pointer to the left to decrease the sum.
            right--;
        }
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 5;

    cout << maxOperations2(arr, k);
    
    return 0;
}