#include<bits/stdc++.h>
using namespace std;

// Brute Force - Using Set Data Structure
int removeDuplicates(vector<int>& arr, int n)
{
    // T.C - O(nlogn + n), S.C - O(n)
    set<int> set; // O(n)
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]); // O(nlogn)
    }
    int k = set.size();
    int j = 0;
    for (int x : set) // O(n)
    {
        arr[j++] = x;
    }
    return k;
}

// Optimal Approach - using two pointers - single pass solution
int removeDuplicates2(vector<int>& arr, int n)
{
    // T.C - O(n), S.C - O(1)
    int i = 0;
    for (int j = 1; j < n; j++) // O(n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1,2,2,3,4,4,4,5}; // sorted array

    // int k = removeDuplicates(arr,arr.size());
    int k = removeDuplicates2(arr,arr.size());

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}