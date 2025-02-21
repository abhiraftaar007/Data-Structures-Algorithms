#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k

// Brute Force
int getLongestSubarray(vector<int> &a, int k)
{
    // T.C - O(n^3), S.C - O(1)
    int n = a.size(); // size of the array.

    int len = 0;

    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            int s = 0;
            for (int K = i; K <= j; K++)
            {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// Solution 2 - Better Approach
int getLongestSubarray2(vector<int> &a, int k)
{
    // T.C - O(n^2), S.C - O(1)
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        int s = 0;
        for (int j = i; j < n; j++)
        { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

// Solution 3 - Optimal - Using Hashing
int getLongestSubarray3(vector<int> &a, int k)
{
    // T.C - O(n) or O(nlogn), S.C - O(n)
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        // Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a = {-1, 1, 1};
    int k = 1;
    // int len = getLongestSubarray(a, k);
    // int len = getLongestSubarray2(a, k);
    int len = getLongestSubarray3(a, k);

    cout << "The length of the longest subarray is: " << len << "\n";

    return 0;
}