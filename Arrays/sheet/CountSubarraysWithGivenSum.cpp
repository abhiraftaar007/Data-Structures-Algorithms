#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/description/

// Brute Force -
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    // T.C - O(n^3), S.C - O(1)
    int n = arr.size(); // size of the given array.
    int cnt = 0;        // Number of subarrays:

    for (int i = 0; i < n; i++) // O(n)
    { // starting index i
        for (int j = i; j < n; j++) // O(n)
        { // ending index j

            // calculate the sum of subarray [i...j]
            int sum = 0;
            for (int K = i; K <= j; K++) // O(n)
                sum += arr[K];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

// Better Approach -
int findAllSubarraysWithGivenSum2(vector<int> &arr, int k)
{
    // T.C - O(n^2), S.C - O(1)
    int n = arr.size(); // size of the given array.
    int cnt = 0;        // Number of subarrays:

    for (int i = 0; i < n; i++) // O(n)
    { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++) // O(n)
        { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

// Optimal -
int findAllSubarraysWithGivenSum3(vector<int> &arr, int k)
{
    // T.C - O(n) or O(nlogn), S.C - O(1)
    int n = arr.size(); // size of the given array.
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++)
    {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {3, 1, 2, 4};
    int k = 6;

    // int cnt = findAllSubarraysWithGivenSum(arr, k);
    // int cnt = findAllSubarraysWithGivenSum2(arr, k);
    int cnt = findAllSubarraysWithGivenSum3(arr, k);

    cout << "The number of subarrays is: " << cnt << "\n";

    return 0;
}