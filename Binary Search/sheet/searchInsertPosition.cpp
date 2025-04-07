#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-insert-position/description/

int searchInsert(vector<int> &arr, int x)
{
    // T.C - O(logN), S.C - O(1)
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
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

    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";

    return 0;
}