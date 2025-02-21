#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/single-number/description/

// Solution 1 - Brute Force
int getSingleElement(vector<int> &arr)
{
    // T.C - O(n^2), S.C - O(1)
    // Size of the array:
    int n = arr.size();

    // Run a loop for selecting elements:
    for (int i = 0; i < n; i++)
    {
        int num = arr[i]; // selected element
        int cnt = 0;

        // find the occurrence using linear search:
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1)
            return num;
    }

    // This line will never execute
    // if the array contains a single element.
    return -1;
}

// Solution 2 - Using hashing
int getSingleElement2(vector<int> &arr)
{
    // T.C - O(3n), S.C - (maxElement+1)
    // size of the array:
    int n = arr.size();

    // Find the maximum element:
    int maxi = arr[0];
    for (int i = 0; i < n; i++) 
    {
        maxi = max(maxi, arr[i]);
    }

    // Declare hash array of size maxi+1
    // And hash the given array:
    vector<int> hash(maxi + 1, 0); 
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Find the single element and return the answer:
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
            return arr[i];
    }

    // This line will never execute
    // if the array contains a single element.
    return -1;
}

// Solution 3 - Using map
int getSingleElement3(vector<int> &arr)
{
    // T.C - O(nlogm) +  O(m), S.C - O(m)
    // size of the array:
    int n = arr.size();

    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp; // m = size of the map - O(m)
    for (int i = 0; i < n; i++) // O(n)
    {
        mpp[arr[i]]++; // O(logm)
    }

    // Find the single element and return the answer:
    for (auto it : mpp) // O(m)
    {
        if (it.second == 1)
            return it.first;
    }

    // This line will never execute
    // if the array contains a single element.
    return -1;
}

// Solution 4 - XOR Approach
int getSingleElement4(vector<int> &arr)
{
    // T.C - O(n), S.C - O(1)
    // size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {4, 1, 2, 1, 2};

    // int ans = getSingleElement(arr);
    // int ans = getSingleElement2(arr);
    // int ans = getSingleElement3(arr);
    int ans = getSingleElement4(arr);

    cout << "The single element is: " << ans << endl;

    return 0;
}