#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/description/

// Brute Force
int maxSubarraySum(int arr[], int n)
{
    // T.C - O(n^3), S.C - O(1)
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) // O(n)
    {
        for (int j = i; j < n; j++) // O(n)
        {
            // subarray = arr[i.....j]
            int sum = 0;

            // add all the elements of subarray:
            for (int k = i; k <= j; k++) // O(n)
            {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// Better Solution - 
int maxSubarraySum2(int arr[], int n)
{
    // T.C - O(n^2), S.C - O(1)
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) // O(n)
    {
        int sum = 0;
        for (int j = i; j < n; j++) // O(n)
        {
            // current subarray = arr[i.....j]

            // add the current element arr[j]
            //  to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

// Optimal Approach -
long long maxSubarraySum3(int arr[], int n)
{
    // T.C - O(n), S.C - O(1)
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) // O(n)
    {

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int maxSum = maxSubarraySum(arr, n);
    // int maxSum = maxSubarraySum2(arr, n);
    int maxSum = maxSubarraySum3(arr, n);

    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}