#include<bits/stdc++.h>
using namespace std;

// Brute Force - 
int findPeakElement(vector<int> &arr)
{
    // T.C - O(n)
    int n = arr.size(); // Size of array.

    for (int i = 0; i < n; i++)
    {
        // Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

// Optimal - using Binary Search
int findPeakElement2(vector<int> &arr)
{
    int n = arr.size(); // Size of array.

    // Edge cases:
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

        // If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1])
            low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else
            high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement2(arr);
    cout << "The peak is at index: " << ans << "\n";

    return 0;
}