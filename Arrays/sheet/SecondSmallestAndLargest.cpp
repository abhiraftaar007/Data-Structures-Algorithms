#include <bits/stdc++.h>
using namespace std;

// Solution 1 - Only works when there are no duplicates
void getElements(vector<int> &arr, int n)
{
    // S.C - O(1)
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl; // edge case when only one element is present in array

    sort(arr.begin(), arr.end()); // O(nlogn)

    int small = arr[1];
    int large = arr[n - 2];

    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}

// Solution 2 - for duplicates also
void getElements2(vector<int>& arr, int n)
{
    // T.C - O(N), S.C - O(1)
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl; // edge case when only one element is present in array

    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}

// Solution 3 - Single pass solution - Most optimised
int secondSmallest(vector<int>& arr, int n)
{
    if (n < 2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            second_small = small;
            small = arr[i];
        }
        else if (arr[i] < second_small && arr[i] != small)
        {
            second_small = arr[i];
        }
    }
    return second_small;
}
int secondLargest(vector<int>& arr, int n)
{
    if (n < 2)
        return -1;
    int large = INT_MIN, second_large = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            second_large = large;
            large = arr[i];
        }

        else if (arr[i] > second_large && arr[i] != large)
        {
            second_large = arr[i];
        }
    }
    return second_large;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {5, 4, 3, 2, 1, 5, 4, 4, 3};

    // getElements(arr,arr.size());
    // getElements2(arr,arr.size());

    cout << secondLargest(arr,arr.size()) << '\n';
    cout << secondSmallest(arr, arr.size()) << '\n';

    return 0;
}