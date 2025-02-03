#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/

bool subsetSum(vector<int> &arr, int n, int target)
{
    // int n = arr.size();

    // Initialize the DP table
    int t[n + 1][target + 1];

    // Base cases
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (j == 0)
            {
                t[i][j] = 1; // Sum 0 is always possible (with empty subset)
            }
            else if (i == 0)
            {
                t[i][j] = 0; // No elements, can't make a positive sum
            }
        }
    }

    // DP logic
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // Printing the DP table (matrix t)
    cout << "DP Table (Matrix t):" << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return t[n][target]; // The answer will be in the bottom-right corner of the table
}

bool canPartition(vector<int> &nums)
{
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if (sum % 2 != 0)
        return false;

    else
        return subsetSum(nums, nums.size(), sum / 2);
}

int main()
{
    vector<int> arr = {1, 2, 3, 5};

    cout << canPartition(arr);

    return 0;
}