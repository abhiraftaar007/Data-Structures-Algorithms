#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays

// Solution 1 - using map
vector<int> FindUnion(vector<int>& arr1, vector<int>& arr2, int n, int m)
{
    // T.C - O((m+n)logn(m+n))
    map<int, int> freq; // O(m+n)

    vector<int> Union; // This is used to return an ans

    for (int i = 0; i < n; i++) // O(n)
        freq[arr1[i]]++; // O(logn)

    for (int i = 0; i < m; i++) // O(m)
        freq[arr2[i]]++; // O(logm)

    for (auto &it : freq)
        Union.push_back(it.first);

    return Union;
}

// Solution 2 - Using Set
vector<int> FindUnion2(vector<int>& arr1, vector<int>& arr2, int n, int m)
{
    // T.C - O((m+n)logn(m+n))

    set<int> s; // O(m+n)

    vector<int> Union; // This is used to return an ans

    for (int i = 0; i < n; i++) // O(n)
        s.insert(arr1[i]); // O(logn)

    for (int i = 0; i < m; i++) // O(m)
        s.insert(arr2[i]); // O(logn)

    for (auto &it : s)
        Union.push_back(it);
    return Union;
}

// Solution 3 - Two Pointers - if both arrays are sorted
vector<int> FindUnion3(vector<int>& arr1, vector<int>& arr2, int n, int m)
{
    // T.C - O(m+n), S.C - O(1)

    int i = 0, j = 0;  // pointers
    vector<int> Union; // Union vector

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        else // case 3
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n) // IF any element left in arr1
    {
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }

    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    
    return Union;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};

    // vector<int> Union = FindUnion(arr1, arr2, arr1.size(), arr2.size());
    // vector<int> Union = FindUnion2(arr1, arr2, arr1.size(), arr2.size());
    vector<int> Union = FindUnion3(arr1, arr2, arr1.size(), arr2.size());

    for(auto& val:Union){
        cout << val << " ";
    }

    return 0;
}