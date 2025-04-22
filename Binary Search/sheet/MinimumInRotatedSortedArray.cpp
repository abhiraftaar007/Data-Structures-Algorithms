#include<bits/stdc++.h>
using namespace std;

// Brute Force - linear search
int findMin(vector<int> &arr)
{
    // T.C - O(n)
    int n = arr.size(); // size of the array.
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // Always keep the minimum.
        mini = min(mini, arr[i]);
    }
    return mini;
}

// Optimal - using binary Search
int findMin2(vector<int> &arr)
{
    // T.C - O(logN)
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

// Further Optimization - Binary Search
int findMin3(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin3(arr);
    cout << "The minimum element is: " << ans << "\n";

    return 0;
}