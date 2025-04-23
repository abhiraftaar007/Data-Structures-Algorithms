#include<bits/stdc++.h>
using namespace std;

// Brute Force - 
int findKRotation(vector<int> &arr)
{
    // T.C - O(n)
    int n = arr.size(); // size of array.
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < ans)
        {
            ans = arr[i];
            index = i;
        }
    }
    return index;
}

// Optimal - Using Binary Search
int findKRotation2(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation2(arr);
    cout << "The array is rotated " << ans << " times.\n";

    return 0;
}