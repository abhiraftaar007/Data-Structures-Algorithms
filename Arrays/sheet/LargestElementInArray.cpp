#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-array

// Solution 1 - Sorting
int LargestElement(vector<int> &arr)
{
    sort(arr.begin(), arr.end()); // O(nlogn)
    return arr[arr.size() - 1];
}

// Solution 2 - using Linear Search
int findLargestElement(vector<int> &arr, int n)
{

    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (maxi < arr[i])
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

// solution 3 - recursive
int largestElement(vector<int> &arr, int i, int &maxi)
{
    // T.C - O(n) , recursive call for each element
    // S.C - O(n), recursive stack space
    if (i == arr.size())
    {
        return maxi;
    }

    if (maxi < arr[i])
    {
        maxi = arr[i];
    }

    largestElement(arr, i + 1, maxi);

    return maxi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {2, 5, 1, 3, 10};
    cout << LargestElement(arr) << '\n';
    cout << findLargestElement(arr, arr.size()) << '\n';

    int maxi = 0;
    int i = 0;
    cout << largestElement(arr, i, maxi) << '\n';

    return 0;
}