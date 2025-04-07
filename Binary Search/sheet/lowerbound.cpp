#include<bits/stdc++.h>
using namespace std;

// Brute Force - using linear search
int lowerBound(vector<int> arr, int n, int x)
{
    // T.C - O(n), S.C - O(1)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            // lower bound found:
            return i;
        }
    }
    return n;
}

// Optimal - using binary search
int lowerBound2(vector<int> arr, int n, int x)
{
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

    // https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array
    
    /*
    int s = 0;
       int e = arr.size() - 1;
       int m ;
       int ans=-1;
        while (s <= e){
          m = s + (e-s)/2;
            if (x < arr[m]){
                e = m - 1;
            }
            else{
                ans=m;
                s=m+1;
            }
        }
    return ans;
    */
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {3, 3, 4, 5, 6, 6, 8};
    int n = arr.size(), x = 4;
    /* int ind = lowerBound(arr, n, x); */
    int ind = lowerBound2(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";

    return 0;
}