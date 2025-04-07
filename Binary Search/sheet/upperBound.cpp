#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

// Brute Force - Linear search
int upperBound(vector<int> &arr, int x, int n)
{
    // T.C - O(N), S.C - O(1)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            // upper bound found:
            return i;
        }
    }
    return n;
}

// Optimal - Binary Search

int upperBound2(vector<int> &arr, int x, int n)
{
    // T.C - O(logn), S.C - O(1)
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x)
        {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 9;

    /* int ind = upperBound(arr, x, n); */
    int ind = upperBound2(arr,x,n);

    cout << "The upper bound is the index: " << ind << "\n";

    return 0;
}