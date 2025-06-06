#include<bits/stdc++.h>
using namespace std;

// Brute Force - Linear search algorithm
bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    // T.C - O(n)
    int n = arr.size(); // size of the array.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return true;
    }
    return false;
}

// Optimal - Binary search
bool searchInARotatedSortedArrayII2(vector<int> &arr, int k)
{
    // T.C - O(logN)
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if mid points the target
        if (arr[mid] == k)
            return true;

        // Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                // element exists:
                high = mid - 1;
            }
            else
            {
                // element does not exist:
                low = mid + 1;
            }
        }
        else
        { // if right part is sorted:
            if (arr[mid] <= k && k <= arr[high])
            {
                // element exists:
                low = mid + 1;
            }
            else
            {
                // element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII2(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    return 0;
}